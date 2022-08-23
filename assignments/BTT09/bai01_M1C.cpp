#include <iostream>
using namespace std;

#define MAX 100

void nhap(int a[],int &n)
{
    cout<<"Nhap n:";
    cin>>n;
    cout<<"Nhap mang :"<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void xuat(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

void them(int a[],int b[],int &vt,int &k,int &n)
{
    do
    {
        cout<<"vi tri muon them phan tu ? (0<=0<=n) ";
        cin>>vt;
        cout<<"gia tri cua phan tu muon them ? ";
        cin>>k;
    } while (vt<0||vt>n);

    for (int i=0, j=0;i<n;i++)
    {
        b[i]=a[i];
    }
    a[vt]=k;
    n++;
    for (int i=vt+1;i<n;i++)
    {
        a[i]=b[i-1];
    }

}

void xoa(int a[],int &n,int &vt)
{   
    cout<<"Nhap vi tri muon xoa :";
    cin>>vt;
    
    for (int i=vt,j=i+1;j<n;i++)
    {
        a[i]=a[j++];
    }
    n--;
}
void TachSo(int a[],int n,int b[],int &nb,int c[],int &nc)
{
    nb=nc=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2)
        {
            b[nb++]=a[i];           /* mảng b lưu số lẻ */
        }
        else
        {
            c[nc++]=a[i];           /* mảng c lưu số chẳn   */
        }
    }
    
}

int main()
{
    int n;
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int vt;
    int k;
    nhap(a,n);
    them(a,b,vt,k,n);
    cout<<"Ket qua cau a:"<<endl;
    xuat(a,n);
    cout<<endl;
    xoa(a,n,vt);
    cout<<endl<<"Ket qua cau b :"<<endl;
    xuat(a,n);
    cout<<endl<<"Ket qua cau c:"<<endl;
    int nb,nc;
    TachSo(a,n,b,nb,c,nc);
    xuat(b,nb);
    cout<<endl;
    xuat(c,nc);
    return 225;
}