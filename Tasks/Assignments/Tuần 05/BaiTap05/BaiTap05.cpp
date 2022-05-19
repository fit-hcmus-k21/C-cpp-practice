#include "BaiTap05.h"

SinhVien nhap()
{
    SinhVien sv;
    cout<<"Nhap ten sinh vien: ";
    fflush(stdin);
    fgets(sv.name,10,stdin);
    cout<<"Nhap mssv: ";
    fflush(stdin);
    fgets(sv.mssv,10,stdin);
    cout<<"Nhap diem so ba mon: ";
    cin>>sv.diemSo[0]>>sv.diemSo[1]>>sv.diemSo[2];
    if (sv.name[9]=='\n')
    {
        sv.name[9]='\0';
    }
    if (sv.mssv[9]=='\n')
    {
        sv.mssv[9]='\0';
    }
    return sv;
}

void Xuat(SinhVien *SV,int sl)
{
    for (int i=0;i<sl;i++)
    {
        cout<<"MSSV : "<<SV[i].mssv<<endl;
        cout<<"Ho ten : "<<SV[i].name<<endl;
        cout<<"Diem : "<<setw(4)<<left<<SV[i].diemSo[0]<<setw(4)<<left<<SV[i].diemSo[1]<<setw(4)<<left<<SV[i].diemSo[2]<<endl;
    }
}

