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

int TimX(int A[],int n,int x)
{
    for (int i=0;i<n;i++)
    {
        if (A[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int TimX2(int A[],int n,int x, int B[])
{
    int i;
    int j=0;
    for (i=0;i<n;i++)
    {
        if (A[i]==x)
        {
            B[j++]=i;
        }
    }
    return j--;
}

int main()
{
    int A[MAX]={0};
    int n;
    NhapMang(A,&n);
    XuatMang(A,n);
    int x;
    printf("Nhap x :");
    scanf("%d",&x);
    int vt=TimX(A,n,x);
    if (vt==-1)
    {
        printf("Khong tim thay %d\n",x);
    }
    else
    {
        printf("Vi tri cua %d la : %d\n",x,vt);
    }
    int B[MAX]={0};
    for (int i=0;i<TimX2(A,n,x,B);i++)
    {
        printf("%d ",B[i]);
    }
    return 225;
}
