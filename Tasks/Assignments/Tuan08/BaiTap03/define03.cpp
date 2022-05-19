#include "lib03.h"

//  Hàm nhập mảng số nguyên (Không đệ qui)
void NhapMang(int *&a, int &n)
{
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    a = new int[n];     //  Cấp phát động, nhớ giải phóng
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

//  Hàm xuất mảng số nguyên ra màn hình
void XuatMang(int *a, int n)
{
    if (n==1)
    {
        cout<<a[0]<<" ";
        return ;
    }
    XuatMang(a,n-1);
    cout<<a[n-1]<<" ";
}

//  Hàm xuất mảng số nguyên ra màn hình theo thứ tự ngược (từ n-1 đến 0)
void XuatNguoc(int *a,int n)
{
    if (n==0)
    {
        return;
    }
    cout<<a[n-1]<<" ";
    XuatNguoc(a,n-1);
}

//  Hàm tìm số lớn nhất trong mảng số nguyên
int SoLonNhat(int *a, int n)
{
    if (n==1)
    {
        return a[0];
    }
    return (a[n-1]>SoLonNhat(a,n-1)) ? a[n-1] : SoLonNhat(a,n-1);
}

//  Hàm kiểm tra số nguyên tố
bool KiemTraSNT(int a)
{
    if (a==1)
    {
        return false;
    }
    for (int i=2;i<=a/2;i++)
    {
        if (a%i==0)
        {
            return false;
        }
    }
    return true;
}

//  Hàm đếm các số nguyên tố có trong mảng số nguyên
int DemSoNT(int *a, int n)
{
    if (n==0)
    {
        return 0;
    }
    return KiemTraSNT(a[n-1]) ? 1 + DemSoNT(a,n-1) : DemSoNT(a,n-1);
}

//  Hàm đếm các giá trị phân biệt trong mảng số nguyên (các số trùng nhau chỉ đếm 1 lần)
int DemGTPB(int *a,int csDau,int n)
{
    if (csDau>=n)
    {
        return 0;
    }
    for (int i=csDau+1;i<n;i++)
    {
        if (a[csDau]==a[i]) 
        {
            return DemGTPB(a,csDau+1,n);
        }
    }
    return 1 + DemGTPB(a,csDau+1,n);
}

//  Hàm kiểm tra mảng số nguyên có chứa toàn số chia hết cho 7 hay không
bool KiemTra7(int *a,int n)
{
    if (n==1)
    {
        return (a[0]%7==0) ? true:false;
    }
    return (a[n-1]%7==0) ? KiemTra7(a,n-1) : false;
}

//  Hàm hoán đổi hai số
void swap(int &a, int &b)
{
    int c=a;
    a=b;
    b=c;
}

//  Hàm sắp xếp mảng số nguyên theo thứ tự tăng dần
void Sapxep(int *a,int n)
{
    if (n==1)
    {
        return;
    }
    Sapxep(a,n-1);
    if (a[n-1]<a[n-2])
    {
        swap(a[n-1],a[n-2]);
        Sapxep(a,n-1);
    }
}

/***
//  Hàm lấy chỉ số của số lớn nhât
int GetPosMax(int *a, int n)
{
    int pos=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>a[pos])
        {
            pos=i;
        }
    }
    return pos;
}

//  Hàm sắp xếp mảng số nguyên theo thứ tự tăng dần
void SapXepTD(int *a, int n)
{
    if (n==0)
    {
        return;
    }
    if (a[n-1]<a[GetPosMax(a,n-1)])
    {
        swap(&a[n-1],&a[GetPosMax(a,n-1)]);
        SapXepTD(a,n-1);
    }
    SapXepTD(a,n-1);
}
***/
