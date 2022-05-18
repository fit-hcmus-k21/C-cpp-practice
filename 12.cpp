#include<stdio.h>
#include<stdlib.h>

struct HEADER
{
    /* Vì trong file ảnh thì nó chỉ chứa 14 byte để lưu 4 thông tin Header, nhưng ở phần stuct nếu khai báo 4 thông tin đó thì phải mất
    đến 16 byte, vì thế nếu đọc hết 16 byte của biến HEADER thì sẽ nhảy sang mất 2 byte của bên DIB, nên ở đây chúng ta khai báo 3 biến
    int ở phía dưới trước, rồi sau đó khai báo thêm 1 biến Signature ở chỗ BITMAP để chúng không chung 1 struct từ đó kích thước
    phần thông tin HEADER được đọc chính xác */

    int FileSize;// Kích thước file.
    int Reserved;// Phần dành riêng.
    int DataOffset;// Địa chỉ phần bắt đầu lưu trữ Pixel Data.
};

struct DIB
{ 
    int DIB_Size;// Kích thước phần DIB
    int Width;// Số pixel theo chiều rộng
    int Height;// Số pixel theo chiều dài.
    short Planes;// Số lớp màu.
    short bits_pixel;// Số bit trên 1 pixel, xác định xem loại ảnh 8, 16 hay 32 bit.
    int Compression;// Cách nén ảnh.
    int ImageSize;// Kích thước phần dữ liệu điểm ảnh.
    int Xpixels;// Độ phân giải theo phương ngang.
    int Ypixels;// Độ phân giải theo phương đứng.
    int ColorUsed;// Số lượng màu trong bảng màu.
    int ImptColor;// Màu quan trọng.
};

struct BITMAP
{
    char* Signature = new char[2];// Chữ kí file.
    HEADER header;// Khai báo biến header lưu phần Header.
    DIB dib;// Khai báo biến DIB lưu phần DIB
    char* DIB_Reserved;// Con trỏ trỏ tới vùng nhớ để lưu phần dư của DIB.
    char* pixelData;// Con trỏ trỏ tới vùng nhớ để lưu dữ liệu điểm ảnh.
    int* colorTable;// Con trỏ trỏ tới vùng nhớ để lưu thông tin bảng màu.
};


int readFileBMP(char* fileName, BITMAP& bmp)
{
    // Mở file bmp ở chế độ đọc nhị phân.
    FILE* f = fopen(fileName, "rb") ;
    if(f == NULL)
    {
        printf("Cannot open file for reading !");
        return 0;
    }

    // Đọc thông tin phần Header.(16 byte)
    // Đọc thông tin phần chữ kí file.
    fread(bmp.Signature, sizeof(char), 2, f);
    fread(&(bmp.header), sizeof(HEADER), 1, f);

    // Đọc thông tin phần DIB.(40 byte)
    fread(&(bmp.dib), sizeof(DIB), 1, f);

    // Đọc thông tin phần dư của DIB.
    if ((bmp.dib).DIB_Size > 40)
    {
        // Kích thước phần dư trong DIB.
        int count = (bmp.dib).DIB_Size - 40;
        // Cáp phát vùng nhớ cho phần dư trong DIB.
        bmp.DIB_Reserved = new char[count];
        // Đọc phần dư trong DIB.
        fread(bmp.DIB_Reserved, sizeof(char), count, f);
    }

    // Đọc thông tin bảng màu.
    // Đọc số lượng màu sử dụng.
    int nums =bmp.dib.ColorUsed;
    //  Cấp phát vùng nhớ chứa thông tin bảng màu.
    bmp.colorTable = new int[nums];
    // Đọc thông tin phần bảng màu.
    fread(bmp.colorTable, sizeof(int), nums, f);

    // Đọc thông tin phần dữ liệu điểm ảnh.
    // Đưa con trỏ đến vị trí đầu tiên của dữ liệu điểm ảnh.
    fseek(f, (bmp.header.DataOffset), SEEK_SET);
    // Cấp phát vùng nhớ cho phần dữ liệu điểm ảnh.
    bmp.pixelData = new char[(bmp.dib).ImageSize];
    // Đọc dữ liệu điểm ảnh.
    fread(bmp.pixelData, sizeof(char), (bmp.dib).ImageSize, f);

    // Đóng file.
    fclose(f);
    return 1;
}

int saveFileBMP(char* fileName, BITMAP& bmp)
{
    // Mở file ở chế độ ghi nhị phân.
    FILE* f = fopen(fileName, "wb");
    if(f == NULL)
    {
        printf("Cannot open file for writting !");
        return 0;
    }

    // Ghi phần Header xuống file.
    // Ghi phần chữ kí xuống file.
    fwrite(bmp.Signature, sizeof(char), 2, f);
    fwrite(&(bmp.header), sizeof(HEADER), 1, f);

    // Ghi phần DIB xuống file.
    fwrite(&(bmp.dib), sizeof(DIB), 1, f);
    // Ghi phần dữ của DIB nếu như kích thước DIB lớn hơn 40.
    if ((bmp.dib).DIB_Size > 40)
    {
        // Số byte lưu phần dư trong DIB.
        int count = (bmp.dib).DIB_Size - 40; 
        // Ghi phần thông tin dư trong DIB xuống file.
        fwrite(bmp.DIB_Reserved, sizeof(char), count, f);
    }

    // Ghi thông tin bảng màu xuống file.
    // Số lượng màu sử dụng trong ảnh.
    int nums =bmp.dib.ColorUsed;
    // Ghi thông tin bảng màu xuống file.
    fwrite(bmp.colorTable, sizeof(int), nums, f);
    
    // Ghi thông tin phần dữ liệu điểm ảnh xuống file.
    fwrite(bmp.pixelData, sizeof(char), bmp.dib.ImageSize, f);

    // Đóng file.
    fclose(f);
    return 1;
}

int convertBMP(char* fileConvert, BITMAP bmp)// Hàm chuyển đổi ảnh từ 24bits sang 8bits.
{
    // Mở fileConvert ở chế độ ghi nhị phân.
    FILE* f = fopen(fileConvert, "wb");
    if(f == NULL)
    {
        printf("Cannot open file for writting !");
        return 0;
    }

    // Tiến hành chuyển đổi từ 24bits sang 8bits.
    for (int i = 0; i < bmp.dib.ImageSize; i++)
    {
        
    }
    
    return 1;
}

void show_infor(BITMAP bmp)
{
    printf("Sign: %s\n", bmp.Signature);
    printf("File Size: %d\n", bmp.header.FileSize);
    printf("Data Offset: %d\n", bmp.header.DataOffset);
    printf("DIB size: %d\n", bmp.dib.DIB_Size);
    printf("Width: %d\n", bmp.dib.Width);
    printf("Height: %d\n", bmp.dib.Height);
    printf("Bits per Pixel: %d\n", bmp.dib.bits_pixel);
    printf("Compression: %d\n", bmp.dib.Compression);
    printf("Image Size: %d\n", bmp.dib.ImageSize);
    printf("Color Used: %d\n", bmp.dib.ColorUsed);
    printf("Important Color: %d\n", bmp.dib.ImptColor);
}

int main(int argc, char* argv[])
{
    BITMAP bmp;
    char file_read[50] = "260422_1.bmp";
    // char* file_save = "julia_set_new.bmp";
    // char* file_convert = "julia_set_conv.bmp";
    readFileBMP(file_read, bmp);
    // convertBMP(file_convert, bmp);
    show_infor(bmp);


    delete[] bmp.Signature;
    return 1;
}