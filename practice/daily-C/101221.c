#include <stdio.h>
#define MAX 10

int Tong(int A[][MAX], int m,int n)
{
    int S=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            S=S+A[i][j];
        }
    }
    return S;
}

int TongDong(int A[][MAX],int k,int n)
{
    int S=0;
    for (int i=0;i<n;i++)
    {
        S=S+A[k-1][i];
    }
    return S;
}

int TongCot(int A[][MAX],int m,int k)
{
    int S=0;
    for (int i=0;i<m;i++)
    {
        S=S+A[i][k-1];
    }
    return S;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SapXep(int A[][MAX],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        if (i%2)
        {
            for(int j=0;j<n-1;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    if (A[i][j]<A[i][k]) swap(&A[i][j],&A[i][k]);
                }
            }
        }
        else
            for(int j=0;j<n-1;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    if (A[i][j]>A[i][k]) swap(&A[i][j],&A[i][k]);
                }
            }

    }
}

void nhapmang(int A[][MAX], int m,int n)
{
    printf("Nhap mang:\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
}

void XuatMang(int A[][MAX],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int A[MAX][MAX];
    int m,n;
    printf("Nhap so dong, cot :");
    scanf("%d%d",&m,&n);
    nhapmang(A,m,n);
    printf("Tong cua cac phan tu mang : %d",Tong(A,m,n));
    int k;
    printf("\nNhap dong muon tinh tong :");
    scanf("%d",&k);
    printf("Tong cua dong thu %d : %d",k,TongDong(A,k,n));
    int l;
    printf("\nNhap cot muon tinh tong :");
    scanf("%d",&l);
    printf("Tong cua cot thu %d : %d\n",l,TongCot(A,m,l));
    SapXep(A,m,n);
    XuatMang(A,m,n);


    return 225;
}