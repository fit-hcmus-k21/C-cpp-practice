//  Cho người dùng nhập số nguyên dương n
//      Viết hàm cho người dùng nhập mảng động gồm n phần tử
//      Sắp xếp mảng theo thứ tự tăng dần
//      Tính số lần xuất hiện của mỗi giá trị trong mảng
//      Sắp xếp các giá trị của mảng giảm dần theo số lần xuất hiện

#include <iostream>
using namespace std;



void nhap(int *&a, int sl)
{
    cout<<"Nhap mang dong "<<sl<<" phan tu: \n";
    a=new int[sl];
    for (int i=0;i<sl;i++)
    {
        cin>>a[i];
    }
}

void increase(int *a,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)\
        {
            if (a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

void xuat(int *a,int sl)
{
    cout<<"Xuat mang: \n";
    for (int i=0;i<sl;i++)
    {
        cout<<a[i]<<" ";
    }
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}



int main()
{
    int n;
    int *a=NULL;
    cout<<"Nhap so phan tu n: ";
    cin>>n;
    //  Nhập mảng động n phần tử
    nhap(a,n);
    xuat(a,n);
    //  Sắp xếp mảng theo thứ tự tăng dần
    cout<<endl;
    increase(a,n);
    xuat(a,n);
    //  Tính số lần xuất hiện của mỗi giá trị trong mảng
    int *p=new int[n];
    cout<<"\nTinh so lan xuat hien cac gia tri trong mang :\n";
    for (int i=0;i<n;i++)
    {
        int j;
        for (j=0;j<i;j++)
        {
            if (a[i]==a[j])
            {
                p[i]=p[j];
                break;
            }
        }
        if (i==j)
        {
            int dem=1;
            for (int x=i+1;x<n;x++)
            {
                if (a[x]==a[i])
                {
                    dem++;
                }
            }
            p[i]=dem;
            cout<<"**** "<<a[i]<<" : "<<dem<<" lan\n";
        }
    }
    //  Sắp xếp các giá trị của mảng giảm dần theo số lần xuất hiện
    cout<<"Sap xep cac gia tri giam dan theo so lan xuat hien\n";
    cout<<"----Xuat mang va so lan xuat hien truoc khi sap xep-----\n";
    xuat(a,n);
    cout<<endl;
    xuat(p,n);
    cout<<endl;
    //  Bắt đầu sắp xếp
    cout<<"----Xuat mang va so lan xuat hien sau khi sap xep-----\n";
    for (int posi=0;posi<n-1;posi++)
    {
        for (int posj=posi+1;posj<n;posj++)
        {
            if (p[posi]<p[posj])
            {
                swap(p+posi,p+posj);
                swap(a+posi,a+posj);
            }
        }
    }
    xuat(a,n);
    xuat(p,n);
    //  Giải phóng vùng nhớ
    delete[] a;
    delete[] p;
    cout<<"\nHoan thanh...\n";
    return 225;
}
