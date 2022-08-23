#include <stdio.h>
#define MAX 100

void HoanDoi(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SapXep(int A[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (A[i]>A[j])
            {
                HoanDoi(&A[i],&A[j]);
            }
        }
    }
}

void NhapMang(int A[],int *n)
{
    printf("Nhap n :");
    scanf("%d",n);
    for (int i=0;i<*n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n");
}

void XuatMang(int A[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{
    int A[MAX];
    int n;
    NhapMang(A,&n);
    SapXep(A,n);
    XuatMang(A,n);
    return 225;
}