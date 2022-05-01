#include <iostream> 
#include <math.h>
#include <fstream>
#pragma pack(2)
using namespace std;

/***    Cấu trúc file bmp gồm 4 phần chính:
 *      -   Header      : 14 bytes
 *                      + signature:     2 bytes
 *                      + filesize:      4 bytes
 *                      + reserved:      4 bytes
 *                      + DataOffset:    4 bytes
 *      -   DIB         : 40 bytes
 *                      + DIB size:      4 bytes
 *                      + width:         4 bytes
 *                      + height:        4 bytes
 *                      + planes:        2 bytes
 *                      + bpp:           2 bytes
 *                      + compression:   4 bytes
 *                      + ImageSize:     4 bytes
 *                      + XppM:          4 bytes
 *                      + YppM:          4 bytes
 *                      + Colors Used:   4 bytes
 *                      + ImportantColor:4 bytes
 *      -   Color Table : tùy biến
 *      -   Pixel Data  : tùy biến                  ***/

//  Khai báo cấu trúc Header:

typedef struct 
{
    char sign1;         //  chữ ký file
    char sign2;
    int fSize;          //  kích thước file
    int reserved;       //  phần dành riêng
    int DataOffset;     //  dịa chỉ bắt đầu lưu dữ liệu điểm ảnh
} HEADER;

//  Khai báo cấu trúc DIB:

typedef struct 
{
    int dibSize;        //  kích thước phần DIB
    int width;          //  số pixel theo chiều rộng
    int height;         //  số pixel theo chiều dài
    short planes;       //  số lớp màu (=1)
    short bpp;          //  số bit/pixel: 1,4,8,16,24,32
    int compression;    //  cách nén ảnh [0: không nén; 1: 8 bit RLE; 4 bit RLE]
    int ImageSize;      //  kích thước phần dữ liệu điểm ảnh
    int XppM;           //  độ phân giải theo phương ngang
    int YppM;           //  độ phân giải theo phương đứng
    int Colors;         //  số màu trong bảng màu
    int ImpColor;       //  số màu quan trọng
} DIB;

//  Khai báo cấu trúc pixel

typedef struct 
{
    char B;             //  Blue
    char G;             //  Green
    char R;             //  Red
}  PIXEL;

//  Khai báo cấu trúc ảnh BMP

typedef struct 
{
    HEADER header;
    DIB dib;
    char *ColorsTable = NULL;  //  con trỏ tới vùng nhớ lưu thông tin bảng màu (nếu có)
    char *overage = NULL;      //  con trỏ tới vùng nhớ lưu phần dư của DIB (nếu có)
    char *PixelData =   NULL;    //  con trỏ tới vùng nhớ lưu dữ liệu điểm ảnh
} BITMAP;

//  Hàm đọc ảnh bmp từ đường dẫn file
void ReadBmp(char *FileInput, BITMAP &image)
{
    ifstream fin(FileInput,ios:: in | ios:: binary);
    
    //  Kiểm tra mở file thành công hay không
    if (!fin.is_open())
    {
        cout<<"-----Loi mo file-----\n";
        exit(225);
    }

    //  Đọc header ảnh
    fin.read((char *) &image.header,14);
    
    //  Đọc phần DIB
    fin.read((char*) &image.dib,sizeof(DIB));

    //  Kiểm tra xem kích thước DIB có bằng 40 hay không, nếu lớn hơn 40 thì đọc phần thừa vào overage
    if (image.dib.dibSize>40)
    {
        image.overage = new char[image.dib.dibSize-40];             //  1. Nhớ giải phóng bộ nhớ
        fin.read((char *) image.overage,image.dib.dibSize-40);
    }

    //  Cấp phát vùng nhớ cho con trỏ đến dữ liệu điểm ảnh
    image.PixelData = new char[image.dib.ImageSize];                //  2. Nhớ giải phóng bộ nhớ     

    //  Đưa con trỏ đến phần bắt đầu dữ liệu điểm ảnh
    fin.seekg(image.header.DataOffset); 

    //  Đọc phần dữ liệu điểm ảnh
    fin.read((char *) image.PixelData, image.dib.ImageSize);

    //  Đọc thông tin bảng màu (nếu có)
    int R = image.header.DataOffset-image.dib.dibSize-sizeof(HEADER);
    if (R>0)
    {
        image.ColorsTable = new char[R];                            //  3. Nhớ giải phóng vùng nhớ
        fin.seekg(image.header.DataOffset-R);
        fin.read((char*) image.ColorsTable,R);
    }

    //  Đóng file
    fin.close();

}

//  Hàm lưu ảnh bmp xuống file theo đường dẫn
void SaveBmp(char *FileOutput, BITMAP &image)
{
    ofstream fout(FileOutput, ios:: out | ios::binary);

    //  Kiểm tra mở file
    if (!fout.is_open())
    {
        cout<<"\nLoi mo file...\n";
        exit(225);
    }

    //  Ghi header file
    fout.write((char *) &image.header, 14);

    //  Ghi phần DIB
    fout.write((char *) &image.dib,40);
    
    //  Ghi phần thừa của DIB (nếu có)
    if (image.overage != NULL)
    {
        fout.write((char *)image.overage,image.dib.dibSize-40);
    }

    //  Ghi thông tin bảng màu (nếu có)
    if (image.ColorsTable != NULL)
    {
        int R = image.header.DataOffset-image.dib.dibSize-sizeof(HEADER);
        fout.write((char*) image.ColorsTable,R);
    }
    
    //  Ghi dữ  liệu điểm ảnh
    fout.write((char *) image.PixelData, image.dib.ImageSize);
    
    //  Đóng file
    fout.close();
}

//   Hàm chuyển đổi ảnh 24bpp hay 32bpp sang ảnh 8bpp
void ConvertBmp(BITMAP img1, BITMAP &img2)
{
    //  Chuyển các thông tin ảnh nguồn cho ảnh đích
    img2.header = img1.header;
    img2.dib = img1.dib;
    
    //  Cấp phát vùng nhớ cho con trỏ ghi phần thừa của DIB
    //img2.overage=new char[img2.dib.dibSize-40];                 //  4. Nhớ giải phóng bộ nhớ
    //img2.overage=img1.overage;
    img2.dib.bpp=8;
    img2.dib.Colors=pow(2,img2.dib.bpp);

    //       Cách tính kích thước ảnh
    /***     Padding bytes
     *  Khi một mảng các pixel được nạp vào bộ nhớ, mỗi hàng phải bắt đầu tại một địa chỉ bộ nhớ mà địa chỉ
     *  đó là bội số của 4, do ta sử dụng pixel có thể kết thúc với địa chỉ không chia hết cho 4, vì vậy 
     *  sẽ có những padding bytes để bù đắp số byte thiếu và đảm bảo rằng kết thúc mỗi dòng địa chỉ bộ nhớ 
     *  luôn là bội của 4.
     *  => padding = [ 4-(width*bpp/8)%4 ]%4
     *     [Trong đó: bpp là số bit/pixel]
     *  => ImageSize = width*height*bpp/8+padding*height                     ***/

    //  Tính số padding bytes
    int padding1=(4-(img1.dib.width*img1.dib.bpp/8)%4)%4;       //  padding bytes ảnh nguồn
    int padding2=(4-(img2.dib.width*img2.dib.bpp/8)%4)%4;       //  padding bytes ảnh đích

    //  Tính lại kích thước ảnh
    img2.dib.ImageSize=(img2.dib.width*img2.dib.height*img2.dib.bpp/8) + padding2*img2.dib.height;

    //  Tính lại kích thước file
    img2.header.fSize = img2.dib.dibSize + sizeof(HEADER) + img2.dib.ImageSize;

    //  Cấp phát vùng nhớ cho dữ liệu điểm ảnh của ảnh đích
    img2.PixelData=new char[img2.dib.ImageSize];                        //  5. Nhớ giải phóng bộ nhớ

    /****  Chuyển dữ liệu điểm ảnh                  ****/

    //  Khai báo con trỏ PixPtr đi qua từng pixel của ảnh nguồn
    char *PixPtr=img1.PixelData;

    //  Chuyển dữ liệu điểm ảnh từ ảnh nguồn (24bpp/32bpp) sang ảnh đích 8bpp
    char B,G,R;

    //  Đối với ảnh 24bit
    if (img1.dib.bpp==24)
    {   
        //  Đi qua từng dòng pixel (height)
        for (int i=0;i<img2.dib.height;i++)
        {
            //  Đi qua từng cột pixel (width)
            for (int j=0;j<img2.dib.width;j++)
            {
                //  Đi qua các bytes màu Blue, Green, Red
                B = *PixPtr++;
                G = *PixPtr++;
                R = *PixPtr++;
                //  Dữ liệu điểm ảnh của ảnh 8bpp bằng trung bình cộng 3 màu B,G,R của ảnh 24bpp hay 32bpp
                img2.PixelData[i*(img2.dib.width*img2.dib.bpp/8+padding2)+j] = (char) (B+G+R)/3;
                
            }
            //  Bỏ qua byte(s) padding
            PixPtr = PixPtr + padding1;
        }
    }

    //  Đối với ảnh 32bit
    if (img1.dib.bpp==32)
    {
        //  Đi qua từng dòng pixel (height)
        for (int i=0;i<img2.dib.height;i++)
        {
            //  Đi qua từng byte trên cột pixel (width)
            for (int j=0;j<img2.dib.width;j++)
            {
                PixPtr++;                               //      Bỏ qua byte màu A rồi đi qua các bytes màu Blue, Green, Red
                B = *PixPtr++;
                G = *PixPtr++;
                R = *PixPtr++;
                //  Dữ liệu điểm ảnh của ảnh 8bpp bằng trung bình cộng 3 màu B,G,R của ảnh 24bpp hay 32bpp
                img2.PixelData[i*(img2.dib.width*img2.dib.bpp/8+padding2)+j] = (char) (B+G+R)/3;
                
            }
            //  Bỏ qua byte(s) padding
            PixPtr = PixPtr + padding1;
        }
    }

    //  Cách của thầy
    /***char *pSrcRow=img1.PixelData;
    char *pDstRow=img2.PixelData;
    int nSrcByteInPix=img1.dib.bpp/8;
    int nDstByteInPix=img2.dib.bpp/8;
    int nSrcByteInRow=(img1.dib.width*nSrcByteInPix)+padding1;
    int nDstByteInRow=(img2.dib.width*nDstByteInPix)+padding2;
    for (int i=0;i<img1.dib.height;i++)
    {
        char *pSrcPix=pSrcRow;
        char *pDstPix=pDstRow;
        for (int j=0;j<img1.dib.width;j++)
        {
            if (img2.dib.bpp==24)
            {
                B=pSrcPix[0];
                G=pSrcPix[1];
                R=pSrcPix[2];
            }
            if (img2.dib.bpp==32)
            {
                B=pSrcPix[1];
                G=pSrcPix[2];
                R=pSrcPix[3];
            }
            char avg=(char) ((B+G+R)/3);
            pDstPix[0]=avg;
            pSrcPix+=nSrcByteInPix;
            pDstPix+=nDstByteInPix;
        }
        pSrcRow+=nSrcByteInRow;
        pDstRow+=nDstByteInRow;
    }***/

    //  Chuyển một số thông tin
    img2.dib.dibSize=40;
    img2.header.DataOffset=1078;
    img2.dib.compression=0;

    img2.ColorsTable=new char[1024];
    int d=0;
    for (int i=0;i<256;i++)
    {
        img2.ColorsTable[d++]=0;
        img2.ColorsTable[d++]=i;
        img2.ColorsTable[d++]=22;

        img2.ColorsTable[d++]=0;
    }

}

//  Hàm thu nhỏ ảnh màu 32bpp, 24bpp, 8bpp theo tỉ lệ S cho trước
void ZoomOutBmp(BITMAP img1, BITMAP &img2, int s)
{
    //  Chuyển thông tin ảnh cũ sang ảnh mới
    img2.header = img1.header;
    img2.dib = img1.dib;
    //  Cấp phát vùng nhớ
    if (img1.overage!=NULL)
    {
        img2.overage = new char[img2.dib.dibSize-sizeof(HEADER)-40];
        img2.overage = img1.overage;
    }
    if (img1.ColorsTable!=NULL)
    {
        img2.ColorsTable = new char[img2.header.DataOffset-sizeof(HEADER)-img2.dib.dibSize];
        img2.ColorsTable = img1.ColorsTable;
    }

    //  Tính lại width, height
    if (img1.dib.width % s == 0)
    {
        img2.dib.width = img1.dib.width/s;
    }
    else
    {
        img2.dib.width = img1.dib.width/s + 1;
    }
    if (img1.dib.height % s ==0)
    {
        img2.dib.height = img1.dib.width/s;
    }
    else
    {
        img2.dib.height = img1.dib.height/s +1;
    }

    //  Tính padding byte(s)
    int padding1 = (4-(img1.dib.width*img1.dib.bpp/8)%4)%4;             //  padding của ảnh cũ
    int padding2 = (4-(img2.dib.width*img2.dib.bpp/8)%4)%4;             //  padding của ảnh mới

    //  Tính lại image size và file size
    img2.dib.ImageSize = img2.dib.width*img2.dib.height*img2.dib.bpp/8 + padding2*img2.dib.height;
    img2.header.fSize = img2.header.DataOffset + img2.dib.ImageSize;

    //  Cấp phát vùng nhớ để lưu dữ liệu điểm ảnh trong ảnh mới
    img2.PixelData = new char[img2.dib.ImageSize];                      //  6. Nhớ giải phóng bộ nhớ

    /***        Chuyển dữ liệu pixel data           ***/
    /***
    *   Ta chia dữ liệu điểm ảnh trong ảnh cũ thành N ma trận điểm ảnh con 
    *   Sau đó tính trung bình giá trị trong ma trận con rồi gán vào dữ liệu điểm ảnh mới     
    *   Trong đó, N = nRowM * nColM ;
    *   Với 
    *       nRowM = (img1.width*img1.bpp/8)/(s*s) ;          (nếu img1.width*img1.bpp/8)%(s*s)==0)
    *             = (img1.width*img1.bpp/8)/(s*s)) + 1 ;     (nếu img1.width*img1.bpp/8)%(s*s)!=0)
    *       nColM = img1.height/(s*s)                ;       (nếu img1.height%(s*s)==0)
    *             = img1.height/(s*s) + 1            ;       (nếu img1.height%(s*s)!=0)
    *                                                                                   ***/
    //  Khai báo s con trỏ để trỏ vào đầu mỗi dòng ma trận 
    char **p = new char*[s];                                               //   7.  Nhớ giải phóng bộ nhớ

    //  Tính số bytes trên 1 dòng của Pixel data ảnh cũ và ảnh mới (cả padding)
    int nRowBytes1 = img1.dib.width*img1.dib.bpp/8 + padding1;              //  ảnh cũ
    int nRowBytes2 = img2.dib.width*img2.dib.bpp/8 + padding2;              //  ảnh mới
    
    //  Dùng hai biến để định vị vị trí trên dòng, cột để kiểm tra điều kiện thuộc ma trận hay không
    int SttRow = 0;
    int SttCol = 0;

    //  Dùng biến index để đi qua từng byte trên pixel data ảnh mới
    int index = 0;

    //  Tính số ma trận theo dòng
    int nRowM = 0;
    if ((img1.dib.width) % (s) == 0)
    {
        nRowM = (img1.dib.width)/(s);
    }
    else
    {
        nRowM = (img1.dib.width)/(s) + 1;
    }

    //  Tính số ma trận theo cột
    int nColM = 0;
    if ((img1.dib.height) % (s) == 0)
    {
        nColM = img1.dib.height/(s);
    }
    else
    {
        nColM = img1.dib.height/(s) + 1;
    }

    //  Khai báo con trỏ origin trỏ và ô đầu tiên của ma trận con trên mỗi hàng ma trận con
    char *origin = img1.PixelData;

    //  Tính số bytes của pixel data trên 1 dòng của ảnh cũ (không tính padding)
    int M = img1.dib.width*img1.dib.bpp/8;

    //  Số bytes trên 1 cột pixel data của ảnh cũ
    int N = img1.dib.height;

    //  Duyệt qua từng ma trận con trên pixel data ảnh cũ, duyệt đủ N ma trận con thì dừng
    //  1pixel trên ảnh mới bằng s*s pixel trên ảnh cũ
    for (int i=0;i<nColM;i++)     
    {
        //cout<<"------------"<<i<<"-----------------\n";
        p[0] = origin;
        SttRow = 0;
        for (int j=0;j<nRowM;j++)
        {
            
        
            char B=0;
            char G=0;
            char R=0;
            int dB=0;
            int dG=0;
            int dR=0;
            char avgB=0;
            char avgG=0;
            char avgR=0;
            
            if ((M-SttRow)>=s && (N-(SttCol))>=s)
            {
                if (j==0)
                {
                    for (int x=1;x<s;x++)
                    {
                        p[x] = p[0] + x*nRowBytes1;
                    }
                }
                else
                {
                    for (int x=0;x<s;x++)
                    {
                        p[x] = p[x] +s;
                    }
                }
                for (int x=0;x<s;x++)
                {
                    for (int y=0;y<s*img2.dib.bpp/8;y++)
                    {
                        // 24bit
                        if (y%3==0)
                        {
                            B=B+p[x][y];
                            dB++;
                        }
                        else
                        {
                            if (y%3==1)
                            {
                                G=G+p[x][y];
                                dG++;
                            }
                            else
                            {
                                if (y%3==2)
                                {
                                    R=R+p[x][y];
                                    dR++;
                                }
                            }
                        }
                    }
                }
                
                 if (dB!=0)
                 {
                     avgB=B/dB;
                 }
                 if (dG!=0)
                 {
                     avgG=G/dG;
                 }
                 if (dR!=0)
                 {
                     avgR=R/dR;
                 }
                 //cout<<"....: "<<avgB<<" "<<avgG<<" "<<avgR<<" "<<dB<<" "<<dG<<" "<<dR<<endl;
                 img2.PixelData[index++]=avgB;
                 img2.PixelData[index++]=avgG;
                 img2.PixelData[index++]=avgR;
                 
                
                
                SttRow = SttRow + s;
            
            }
            else
            {
                if ((M-SttRow)<s && (N-(SttCol)<s))
                {
                    int x = M-SttRow;
                    int y = N-(SttCol);
                    for (int h=0;h<y;h++)
                    {
                        p[h] = p[h] + s;
                    }
                    for (int h=0;h<y;h++)
                    {
                        for (int k=0;k<x*img2.dib.bpp/8;k++)
                        {
                            
                            // 24bit
                        if (k%3==0)
                        {
                            B=B+p[h][k];
                            dB++;
                        }
                        else
                        {
                            if (k%3==1)
                            {
                                G=G+p[h][k];
                                dG++;
                            }
                            else
                            {
                                if (k%3==2)
                                {
                                    R=R+p[h][k];
                                    dR++;
                                }
                            }
                        }
                    }
                     
                         if (dB!=0)
                 {
                     avgB=B/dB;
                 }
                 if (dG!=0)
                 {
                     avgG=G/dG;
                 }
                 if (dR!=0)
                 {
                     avgR=R/dR;
                 }
                 img2.PixelData[index++]=avgB;
                 img2.PixelData[index++]=avgG;
                 img2.PixelData[index++]=avgR;
                 
                    SttRow = SttRow + s;
                }
                }
                else
                {
                    if (M-SttRow<s)
                    {
                        for (int x=0;x<s;x++)
                        {
                            p[x] = p[x] + s;
                        }
                        int c = M-SttRow;
                        for (int h=0;h<s;h++)
                        {
                            for (int k=0;k<c*img2.dib.bpp/8;k++)
                            {
                                    // 24bit
                        if (k%3==0)
                        {
                            B=B+p[h][k];
                            dB++;
                        }
                        else
                        {
                            if (k%3==1)
                            {
                                G=G+p[h][k];
                                dG++;
                            }
                            else
                            {
                                if (k%3==2)
                                {
                                    R=R+p[h][k];
                                    dR++;
                                }
                            }
                        }
                            }
                        }
                         
                         if (dB!=0)
                 {
                     avgB=B/dB;
                 }
                 if (dG!=0)
                 {
                     avgG=G/dG;
                 }
                 if (dR!=0)
                 {
                     avgR=R/dR;
                 }
                 img2.PixelData[index++]=avgB;
                 img2.PixelData[index++]=avgG;
                 img2.PixelData[index++]=avgR;
                 
                        
                        SttRow = SttRow + s;
                    }
                    else
                    {
                        if (N-SttCol<s)
                        {
                            int r = N-(SttCol);
                            for (int x=0;x<r;x++)
                            {
                                p[x] = p[x] +s;
                            }
                            for (int h=0;h<r;h++)
                            {
                                for (int k=0;k<s*img2.dib.bpp/8;k++)
                                {
                                       // 24bit
                        if (k%3==0)
                        {
                            B=B+p[h][k];
                            dB++;
                        }
                        else
                        {
                            if (k%3==1)
                            {
                                G=G+p[h][k];
                                dG++;
                            }
                            else
                            {
                                if (k%3==2)
                                {
                                    R=R+p[h][k];
                                    dR++;
                                }
                            }
                        }
                                }
                            }
                             
                             if (dB!=0)
                 {
                     avgB=B/dB;
                 }
                 if (dG!=0)
                 {
                     avgG=G/dG;
                 }
                 if (dR!=0)
                 {
                     avgR=R/dR;
                 }
                 img2.PixelData[index++]=avgB;
                 img2.PixelData[index++]=avgG;
                 img2.PixelData[index++]=avgR;
                 
                            
                            SttRow = SttRow + s;
                        }
                    }
                }
            }
            
        }
       
        origin = origin + nRowBytes1*s;
        SttCol = SttCol + s;
        index = index + padding2;
    }
    cout<<"hi\n";
   
    //  Giải phóng bộ nhớ 
    delete[] p;
    cout<<"hello\n";
}

//  Hàm xuất thông tin ảnh ra màn hình để kiểm tra
void Output(BITMAP image)
{
    //  Xuất thông tin hình ảnh ra màn hình để kiểm tra
    cout<<"---------------Thong tin hinh anh----------------\n";
    cout<<"/******Header:\n";
    cout<<"signature: "<<image.header.sign1<<image.header.sign2<<endl;
    cout<<"FileSize: "<<image.header.fSize<<endl;
    cout<<"DataOffset: "<<image.header.DataOffset<<endl<<endl;
    cout<<"/******DIB:\n";
    cout<<"DIB size: "<<image.dib.dibSize<<endl;
    cout<<"Width: "<<image.dib.width<<endl;
    cout<<"Height: "<<image.dib.height<<endl;
    cout<<"Planes: "<<image.dib.planes<<endl;
    cout<<"Bits per pixel: "<<image.dib.bpp<<endl;
    cout<<"Compression: "<<image.dib.compression<<endl;
    cout<<"Image Size: "<<image.dib.ImageSize<<endl;
    cout<<"XpixelsPerM: "<<image.dib.XppM<<endl;
    cout<<"YpixelsPerM: "<<image.dib.YppM<<endl;
    cout<<"Colors Used: "<<image.dib.Colors<<endl;
    cout<<"Important Color: "<<image.dib.ImpColor<<endl<<endl;

}

//  Viết chương trình theo tham số dòng lệnh
int main()
{
    BITMAP image1;
    BITMAP image2;
    BITMAP image3;
    BITMAP image4;

    //  Đọc ảnh bmp từ đường dẫn file
    char FileInput[50]="21120500.bmp";
    ReadBmp(FileInput,image1);
    char name[50]="260422_1.bmp";
    ReadBmp(name,image2);

    //  Lưu ảnh bmp xuống file theo đường dẫn
    //char FileOutput[50]="output1.bmp";

    //  Chuyển ảnh bmp 24bpp/ 32bpp sang 8bpp
    //ConvertBmp(image1,image2);
    //ConvertBmp(image3,image4);

    //  Xuất thông tin hình ảnh ra màn hình để kiểm tra
    //Output(image1);
    //Output(image2);

    //  Thu nhỏ ảnh 24bpp hay 32bpp  theo tỉ lệ s
    ZoomOutBmp(image1,image3,2);
    //ZoomOutBmp(image2,image4,4);

    //  Lưu ảnh vừa chuyển xuống file theo đường dẫn để kiểm tra
    char BmpConvert1[50]="output1.bmp";
    char BmpConvert2[50]="output2.bmp";
    SaveBmp(BmpConvert1,image3);
    //SaveBmp(BmpConvert2,image4);


    //  Giải phóng vùng nhớ 
    delete[] image1.overage;
    delete[] image2.overage;
    delete[] image3.overage;
    delete[] image4.overage;
    delete[] image1.ColorsTable;
    delete[] image2.ColorsTable;
    delete[] image3.ColorsTable;
    delete[] image4.ColorsTable;
    delete[] image1.PixelData;
    delete[] image2.PixelData;
    delete[] image3.PixelData;
    delete[] image4.PixelData;
    
    cout<<"\n...hoan thanh...\n\n\n";
    return 225;
}
