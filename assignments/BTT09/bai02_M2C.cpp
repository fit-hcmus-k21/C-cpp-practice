#include <iostream>
using namespace std;
#define MAX 100

void nhap(int a[][MAX],int &m,int &n)
{
    cout<<"Nhap so hang:";
    cin>>m;
    cout<<"Nhap so cot:";
    cin>>n;
    cout<<"Nhap ma tran :"<<endl;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

void xuat(int a[][MAX],int m,int n)
{
    cout<<"Xuat ma tran :"<<endl;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
    }
}
int Tong(int a[][MAX],int m,int n)
{
    int s=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            s=s+a[i][j];
        }
    }
    return s;
}

int Tong_MT(int a[][MAX],int m1,int n1,int b[][MAX],int m2,int n2)
{
    return Tong(a,m1,n1)+Tong(b,m2,n2);
}

int main()
{
    int a[MAX][MAX];
    int b[MAX][MAX];
    int m1,m2;
    int n1,n2;
    nhap(a,m1,n1);
    nhap(b,m2,n2);
    cout<<endl;
    cout<<"Tong hai ma tran la: "<<Tong_MT(a,m1,n1,b,m2,n2);
    return 22;
}