/***        Kĩ thuật truy hồi
 * 1.   Tính giai thừa của n
 * 2.   Tính tổng bình phương từ 1 đến n
 * 3.   Tìm phần tử nhỏ nhất trong mảng
 * 4.   Kiểm tra mảng có thứ tự tăng dần hay không
 * 5.   Đếm số lượng mảng con tăng liên tục trong mảng số nguyên
 * 6.   Sắp xếp mảng tăng
 *                                                              ***/

#include <iostream>
using namespace std;

//  Tính giai thừa của n
int GiaiThua(int n)
{
    if (n==0)
    {
        return 1;
    }
    if (n==1)
    {
        return 1;
    }
    return GiaiThua(n-1)*n;
}

//  Tính tổng bình phương từ 1 đến n
int TongBP(int n)
{
    if (n==1)
    {
        return 1;
    }
    return n*n+TongBP(n-1);
}

//  Tìm phần tử nhỏ nhất trong mảng
int GetMin(int *a, int sl)
{
    

}

//  Kiểm tra mảng có thứ tự tăng dần hay không
bool KiemTra(int *a,int sl)
{
    if (sl==1)
    {
        return true;
    }
    for (int i=0;i<sl-1;i++)
    {
        if (a[i]>a[sl-1])
        {
            return false;
        }
    }
    KiemTra(a,sl-1);

}

//  Đếm số lượng mảng con tăng liên tục trong mảng số nguyên
int SoMangCon(int *a,int sl)
{

}

//  Hàm hoán đổi
void swap(int &a,int &b)
{
    int c=a;
    a=b; 
    b=c;
}

//  Hàm tìm phần tử lớn nhất
int GetMax(int *a,int n)
{
    int i,maxpos=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>a[maxpos])
        {
            maxpos=i;
        }
    }
    return maxpos;
}

//  Sắp xếp mảng tăng
void SapXep(int *a,int sl)
{
    if (sl==1)
    {
        return;
    }
    swap(a[sl-1],a[GetMax(a,sl-1)]);
    SapXep(a,sl-1);
}

int main()
{
    cout<<GiaiThua(5)<<endl;
    cout<<TongBP(4)<<endl;
    int a[5]={5,19,-17,23,8};
    if (KiemTra(a,5))
    {
        cout<<"Mang chua sap xep tang\n";
    }
    SapXep(a,5);
    for (int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    if (KiemTra(a,5))
    {
        cout<<"Mang da sap xep tang\n";
    }
    cout<<endl;
    return 225;

}