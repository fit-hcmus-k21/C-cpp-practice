//  Viết hàm cho mảng động 1 chiều 
//      Tìm các phần tử phân biệt trong mảng
//      Liệt kê số lần xuất hiện các phần tử phân biệt trong mảng
//      Tìm các mảng con tăng dần liên tục trong mảng 
//      Tìm tất cả mảng con dài nhất gồm toàn số lẻ
//      Tìm tất cả mảng con liên tục dài nhất gồm toàn số lẻ

#include <iostream>
using namespace std;

void nhap(int *&a,int &sl)
{
    cout<<"Nhap so phan tu n: ";
    cin>>sl;
    a=new int[sl];
    cout<<"---Nhap mang---\n";
    for (int i=0;i<sl;i++)
    {
        cin>>a[i];
    }
}

void xuat(int *a,int sl)
{
    cout<<"---Xuat mang---\n";
    for (int i=0;i<sl;i++)
    {
        cout<<a[i]<<" ";
    }
}

void giaiphong(int *&a)
{
    cout<<"--Giai phong bo nho--";
    delete[] a;
}

//  hàm tìm các phần tử phân biệt trong mảng
void timpb(int *a,int *&b,int sl)
{
    int d=0;
    for (int i=0;i<sl;i++)
    {
        int j;
        for ( j=0;j<d;j++)
        {
            if (a[i]==b[j])
            {
                break;
            }
        }
        if (i==j)
        {
            b=(int *) realloc(b,(d+1)*sizeof(int));
            b[d++]=a[i];
        }
    }
}

//  Liệt kê số lần xuất hiện các phần tử phân biệt trong mảng
void lietke(int *a,int *b, int *&c,int sl)
{
    c=(int *) realloc(c, sizeof(b));
    int id=0;
    for (int i=0;i<sizeof(b)/sizeof(int);i++)
    {
        int count=0;
        for (int j=0;j<sl;j++)
        {
            if (a[j]==b[i])
            {
                count++;
            }
        }
        c[id++]=count;
    }
}

//  Tìm các mảng con tăng dần liên tục
void mangCon(int *a,int sl)
{
    int pos=0;
    for (int i=0;i<sl-1;i++)
    {
        pos=i;
        for (int j=i+1;j<sl;j++)
        {
            if (a[j]>a[pos])
            {
                pos=j;
            }
            else
            {
                break;
            }
        }
        if (pos>i)
        {
            for (int k=i;k<=pos;k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<"\n----------\n";
        }
        i=pos;
    }
}

//  Tìm tất cả mảng con liên tục dài nhất gồm toàn số lẻ

void TimMangCon(int *a,int sl)
{


}

//  Tìm tất cả mảng con dài nhất gồm toàn số lẻ

int main()
{
    //  Chưa xong >.<

    int *a,*b,*c;
    int sl;

}