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
        cout<<endl;
    }
    cout<<endl;
}

int Tong_Db(int a[][MAX],int m,int n)
{
    int s=0;
    for (int i=0;i<n;i++)
    {
        s=s+a[0][i];
        s=s+a[m-1][i];
    }
    for (int j=1;j<m-1;j++)
    {
        s=s+a[j][0];
        s=s+a[j][n-1];
    }
    return s;
}

bool kiemtra(int m,int n)
{
    if (m==n)
    {
        return 1;
    }
    return 0;
}

int Tong_Dcc(int a[][MAX],int m,int n)
{
    int s=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==j)
            {
                s=s+a[i][j];
            }
        }
    }
    return s;
}

int Tong_Dcp(int a[][MAX],int m,int n)
{
    int s=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i+j==n-1)
            {
                s=s+a[i][j];
            }
        }
    }
    return s;
}

int Tong_hang_k(int a[][MAX],int m,int n,int k)
{
    int s=0;
    for (int i=0;i<n;i++)
    {
        s=s+a[k-1][i];
    }
    return s;
}

int hang_max(int a[][MAX],int m,int n)
{
    int s=0;
    int max;
    int vt=0;
    for (int i=0;i<m;i++)
    {
        s=0;
        for (int j=0;j<n;j++)
        {
            s=s+a[i][j];
        }
        if (i==0)
        {
            max=s;
        }
        else
        {
            if (s>max)
            {
                max=s;
                vt=i;
            }
        }
    }
    return vt;
}

bool min(int a[][MAX],int m,int n,int x)
{
    for (int i=0;i<m;i++)
    {
        if (x>a[i][n])
        {
            return false;
        }
    }
    return true;
}

bool max(int a[][MAX],int m,int n,int x)
{
    for (int j=0;j<n;j++)
    {
        if (x<a[m][j])
        {
            return false;
        }
    }
    return true;
}

void yen_ngua(int a[][MAX],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if ( min(a,m,j,a[i][j]) && max(a,i,n,a[i][j]) )
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
}

int main()
{
    int a[MAX][MAX];
    int m,n;
    nhap(a,m,n);
    xuat(a,m,n);
    cout<<"Tong cac phan tu bien :"<<Tong_Db(a,m,n)<<endl;
    
    if (kiemtra(m,n))
    {
        cout<<"Tong duong cheo chinh :"<<Tong_Dcc(a,m,n)<<endl;
        cout<<"Tong duong cheo phu :"<<Tong_Dcp(a,m,n)<<endl;
    }

    int k;
    cout<<"Nhap hang muon tinh tong:";
    cin>>k;
    cout<<"Tong hang thu "<<k<<"la :"<<Tong_hang_k(a,m,n,k)<<endl;

    cout<<"Hang co tong lon nhat cua ma tran la hang thu "<<hang_max(a,m,n)+1<<endl;

    cout<<"gia tri yen ngua cua ma tran : ";
    yen_ngua(a,m,n);
    cout<<endl;
    return 225;
    
}