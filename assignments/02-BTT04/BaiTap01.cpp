#include "BaiTap01.h"

//  Nhập 1 sinh viên từ bàn phím

SINHVIEN nhap()
{
    SINHVIEN sv;
    cout<<"Nhap MSSV: ";
    cin>>sv.mssv;
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    fgets(sv.hoten,51,stdin);
    if (sv.hoten[strlen(sv.hoten)-1]=='\n')
    {
        sv.hoten[strlen(sv.hoten)-1]='\0';
    }
    cout<<"Nhap DTB: ";
    cin>>sv.dtb;
    return sv;
}

//  Xuất 1 sinh viên ra màn hình

void xuat(SINHVIEN sv)
{
    cout<<"MSSV: "<<sv.mssv<<endl;
    cout<<"Ho Ten:"<<sv.hoten<<endl;
    cout<<"DTB: "<<sv.dtb<<endl;
}

//  Kiểm tra mssv có hợp lệ hay không

bool kiemtra_mssv(int mssv)
{
    if (mssv/1000000>=1)
    {
        return true;
    }
    return false;
}

//  Hiệu chỉnh tên sinh viên

void HieuChinh(char *HoTen)
{
    for (int i=0;i<strlen(HoTen);i++)
    {
        if (HoTen[i]==32)
        {
            if (HoTen[i+1]>=97 )
            {
                HoTen[i+1]=HoTen[i+1]-32;
            }
        }
        if (HoTen[0]>=97)
        {
            HoTen[0]=HoTen[0]-32;
        }
    }
}

//  Kiểm tra một chuỗi cho trước có xuất hiện trong tên sinh viên hay không

bool kiemtra_Hoten(char *HoTen,char *Chuoi_kitu)

{
    char *p=NULL;
    bool kiemtra=false;
    for (int i=0;i<strlen(HoTen);i++)
    {
        if (HoTen[i]==Chuoi_kitu[0])
        {
            p=&HoTen[i];
            for (int j=0;j<strlen(Chuoi_kitu);j++)
            {
                if (*(p+j)!=Chuoi_kitu[j])
                {
                    kiemtra=false;
                    break;
                }
                kiemtra=true;
            }
            if (kiemtra==true)
            {
                return true;
            }
        }
    }
    return kiemtra;
}

//  Nhập danh sách sinh viên

void Nhap_DSSV(SINHVIEN *DSSV,int sl)
{
    for (int i=0;i<sl;i++)
    {
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        DSSV[i]=nhap();
    }
}

//  Xuất danh sách sinh viên

void Xuat_DSSV(SINHVIEN *DSSV,int sl)
{
    cout<<"Danh sach sinh vien: "<<endl;
    for (int i=0;i<sl;i++)
    {
        xuat(DSSV[i]);
    }
}

// Tìm sinh viên có điểm trung bình cao nhất

void TimSV_DTB_Max(SINHVIEN *DSSV,int sl)
{
    float max=DSSV[0].dtb;
    SINHVIEN *sv=NULL;
    for (int i=1;i<sl;i++)
    {
        if (DSSV[i].dtb>max)
        {
            max=DSSV[i].dtb;
            sv=&DSSV[i];
        }
    }
    cout<<"Diem trung binh cao nhat la: "<<max<<endl;
    xuat(*sv);
}

//  Hoán đổi 2 sinh viên

void hoandoi(SINHVIEN *a,SINHVIEN *b)
{
    SINHVIEN c=*a;
    *a=*b;
    *b=c;
}

//  Sắp xếp DSSV tăng dần theo mssv

void SapXep_TangDan(SINHVIEN *DSSV,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (DSSV[i].mssv>DSSV[j].mssv)
            {
                hoandoi(&DSSV[i],&DSSV[j]);
            }
        }
    }
}

//  Sắp xếp DSSV giảm dần theo mssv

void SapXep_GiamDan(SINHVIEN *DSSV,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (DSSV[i].mssv<DSSV[j].mssv)
            {
                hoandoi(&DSSV[i],&DSSV[j]);
            }
        }
    }
}

//Sắp xếp DSSV theo đtb giảm dần

void SapXep_DTB(SINHVIEN *DSSV,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (DSSV[i].dtb<DSSV[j].dtb)
            {
                hoandoi(&DSSV[i],&DSSV[j]);
            }
        }
    }
}

//  Sắp xếp DSSV cùng điểm theo mssv giảm dần

void Sap_xep_mssv(SINHVIEN *DSSV,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i;j<sl;j++)
        {
            if (DSSV[i].dtb==DSSV[j].dtb && DSSV[i].mssv<DSSV[j].mssv)
            {
                hoandoi(&DSSV[i],&DSSV[j]);
            }
        }
    }
}

// Tìm 5 sinh viên có điểm trung bình cao nhất, nếu có nhều sinh viên có cùng điểm tb cao nhất thì ưu tiên chọn các bạn sinh viên cố mssv nhỏ hơn

void Tim_5sv(SINHVIEN *DSSV,int sl)
{
    SapXep_DTB(DSSV,sl);
    Sap_xep_mssv(DSSV,sl);
    int d=0;
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i;j<sl;j++)
        {
            if (DSSV[i].dtb!=DSSV[j].dtb)
            {
                xuat(DSSV[i]);
                d++;
            }
            if (d>5)
            {
                break;
            }
        }
        if (d>5)
        {
            break;
        }
    }
}