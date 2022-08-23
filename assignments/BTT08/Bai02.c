#include <stdio.h>
#define MAX 100

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

double TB(int A[],int n)
{
    double S=0;
    for (int i=0;i<n;i++)
    {
        S=S+A[i];
    }
    return S/n;
}

int max(int A[],int n)
{
    int max=A[0];
    for (int i=1;i<n;i++)
    {
        if (A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}

int second(int A[],int n)
{
    int max2=A[0];
    for (int i=1;i<n;i++)
    {
        if (A[i]!=max(A,n) && A[i]>max2 )
        {
            max2=A[i];
        }
    }
    return max2;
}

int main()
{
    int A[MAX]={0};
    int n;
    NhapMang(A,&n);
    XuatMang(A,n);
    printf("Trung binh : %lf\n",TB(A,n));
    printf("So lon nhat : %d\n",max(A,n));
    printf("So lon nhi : %d\n",second(A,n));
    return 225;
}