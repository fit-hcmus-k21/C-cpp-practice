#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100

bool kiemtra(int S[],int n,int x)
{
    for (int i=0;i<n;i++)
    {
        if (S[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

int GanX(int S[],int n,int x)
{
    int value = abs(x-S[0]);
    int SoGanX=S[0];
    for (int i=1;i<n;i++)
    {
        if (abs(x-S[i])<value)
        {
            SoGanX=S[i];
            value=abs(x-S[i]);
        }
    }
    return SoGanX;
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
    int S[MAX];
    int n;
    NhapMang(S,&n);
    XuatMang(S,n);
    
    int x;
    printf("Nhap x :");
    scanf("%d",&x);
    if (kiemtra(S,n,x))
    {
        printf("So %d co trong S(n)\n",x);
    }
    else
    {
        printf("So %d khong co trong S(n)\n",x);
    }
    
    printf("So gan %d la : %d",x,GanX(S,n,x));
    return 225;

}