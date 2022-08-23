#include "BaiTap05.h"

int main()
{
    int sl;
    cout<<"Nhap so luong sinh vien: ";
    cin>>sl;
    SinhVien *SV=new SinhVien[sl];
    //  Nho delete[] =))
    for (int i=0;i<sl;i++)
    {
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<" :"<<endl;
        SV[i]=nhap();
    }
    cout<<"-------------------------------"<<endl;
    cout<<"Xuat thong tin sinh vien: "<<endl;
    Xuat(SV,sl);
    
    FILE *file=fopen("sinhvien.bin","wb");
    if (file!=NULL)
    {
        fwrite(SV,sizeof(SinhVien),sizeof(SV),file);
    }

    fclose(file);
    delete[] SV;
    return 225;
    
}
