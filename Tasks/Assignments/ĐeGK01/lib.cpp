#include "lib.h"

//   Khởi tạo danh sách 

MewMew NhapThongTin()
{
    MewMew meo;
    cout<<"Nhap ma so: ";
    cin>>meo.ID;
    cout<<"Nhap giong meo: ";
    fflush(stdin);
    fgets(meo.KindCat,M,stdin);
    cout<<"Nhap mau long: ";
    fflush(stdin);
    fgets(meo.FurCollor,N,stdin);
    cout<<"Nhap can nang: ";
    cin>>meo.Weight;

    //  Kiểm tra kí tự xuống dòng thừa

    if (meo.KindCat[strlen(meo.KindCat)-1]=='\n')
    {
        meo.KindCat[strlen(meo.KindCat)-1]='\0';
    }
    if (meo.FurCollor[strlen(meo.FurCollor)-1]=='\n')
    {
        meo.FurCollor[strlen(meo.FurCollor)-1]='\0';
    }
    return meo;
}

void KhoiTaoDS(MewMew *&DS, int &sl )
{
    cout<<"==========Khoi Tao Danh Sach ==========\n";
    pri"Nhap so luong meo: ");
    scanf("%d",&sl);
    DS = (MewMew*) malloc(sl*sizeof(MewMew));

    if (DS==NULL)
    {
        printf("------------Cap phat that bai-----------\n");
        exit(225);
    }

    //  Bắt đầu nhập thông tin 

    for (int i=0;i<sl;i++)
    {
        printf("*** Nhap thong tin meo thu %d: \n",i+1);
        DS[i]=NhapThongTin();
    }
}


void XuatThongTin(MewMew meo)
{
    printf("%s%d\n","Ma so: ",meo.ID);
    printf("%s%s\n","Giong meo: ",meo.KindCat);
    printf("%s%s\n","Mau long: ",meo.FurCollor);
    printf("%s%.2f\n","Can nang: ",meo.Weight);
}

//  2.  Kiểm tra danh sách có rỗng hay không

void KiemTra(MewMew *&DS, int sl)
{
    if (DS==NULL)
    {   
        printf("%s\n","-> Danh sach rong !");
    }
    else
    {
        printf("%s\n","-> Danh sach khong rong !");
    }
}

//  3.  Thêm 1 con mèo vào cuối danh sách

void AddCat(MewMew *&DS, int &sl)
{
    printf("==========Them Meo Vao Cuoi==========\n");    
    sl++;
    DS = (MewMew*) realloc(DS, sl*sizeof(MewMew));
    printf("*** Nhap thong tin meo muon them  ***\n");
    DS[sl-1]=NhapThongTin();
}

//  4.  Xóa con mèo cuối cùng trong danh sách

void DeleteCat(MewMew *&DS,int &sl)
{
    printf("==========Xoa Meo Cuoi Cung==========\n");
    sl--;
    DS = (MewMew*) realloc(DS, sl*sizeof(MewMew));
}

//  5.  Tìm con mèo có cân nặng nhỏ nhất. Nếu có nhiều con mèo có cân nặng nhỏ nhất bằng nhau thì chỉ cần trả về con mèo đầu tiên.

void FindCat(MewMew *&DS, int sl)
{
    printf("==========Con Meo Can Nang Nho Nhat==========\n");
    int min=DS[0].Weight;
    int pos=0;
    for (int i=1;i<sl;i++)
    {
        if (DS[i].Weight<min)
        {
            min=DS[i].Weight;
            pos=i;
        }
    }
    printf("*** Ket qua: \n");
    XuatThongTin(DS[pos]);
}

//  6.  Cập nhật màu lông (cho trước) cho con mèo có mã số (cho trước)

void UpdateFur(MewMew *&DS, int sl)
{
    printf("==========Cap Nhat Mau Long==========\n");
    int id;
    char *fur=new char[N];
    printf("%s","Mau long cap nhat: ");
    fflush(stdin);
    fgets(fur,N,stdin);
    if (fur[strlen(fur)-1]=='\n')
    {
        fur[strlen(fur)-1]='\0';
    }
    printf("%s","Ma so: ");
    scanf("%d",&id);
    for (int i=0;i<sl;i++)
    {
        if (DS[i].ID==id)
        {
            strcpy(DS[i].FurCollor,fur);
        }
    }
    delete[] fur;
}

//  7.  Sắp xếp danh sách tăng dần theo cân nặng và xuất danh sách sau khi sắp xếp

void Swap(MewMew *a, MewMew *b)
{
    MewMew c=*a;
    *a=*b;
    *b=c;
}

void ArrrangeCat(MewMew *&DS,int sl)
{
    printf("==========Sap Xep Tang Dan Can Nang==========\n");
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (DS[i].Weight>DS[j].Weight)
            {
                Swap(&DS[i],&DS[j]);
            }
        }
    }
    printf("*** Xuat danh sach:\n");
    for (int i=0;i<sl;i++)
    {
        XuatThongTin(DS[i]);
    }
}

//  8.  Tìm và trả về danh sách 3 con mèo có cân nặng lớn nhất

void Find3Cat(MewMew *&DS, int sl)
{
    printf("==========3 Con Meo Can Nang Lon Nhat==========\n");

    //  Sao chép mảng vào mảng cấp phát động mới để sắp xếp và tìm 

    MewMew *Cat=new MewMew[sl];
    memcpy(Cat,DS,sl*sizeof(MewMew));

    //  Sắp xếp theo giảm dần cân nặng

    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (Cat[i].Weight<Cat[j].Weight)
            {
                Swap(&Cat[i],&Cat[j]);
            }
        }
    }

    printf("*** Ket qua: \n");
    for (int i=0;i<3;i++)
    {
        XuatThongTin(Cat[i]);
    }

    //  Giải phóng vùng nhớ vừa cấp phát để sao chép

    for (int i=0;i<sl;i++)
    {
        delete[] Cat[i].KindCat;
        delete[] Cat[i].FurCollor;
    }
    delete[] Cat;
}

//  9.  Xóa rỗng danh sách

void DeleteDS(MewMew *&DS,int sl)
{
    printf("==========Xoa Rong Danh Sach==========\n");
    for (int i=0;i<sl;i++)
    {
        delete[] DS[i].KindCat;
        delete[] DS[i].FurCollor;
    }
    DS = (MewMew*) realloc(DS,0);
}