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

void XuatMang(int A[], int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int TimMax2(int A[],int n)
{
    int s1;
    int s2;
    if (A[0]>A[1])
    {
        s1=A[0];
        s2=A[1];
    }
    else
    {
        s1=A[1];
        s2=A[0];
    }
    for (int i=2;i<n;i++)
    {
        if (s1==s2 && (s1-A[i])!=0)
        {
            if (A[i]>s1)
            {
                s1=A[i];
            }
            else
            {
                s2=A[i];
            }
        }
        if (A[i]>s1)
        {
            s2=s1;
            s1=A[i];
        }
        else
        {
            if (A[i]!=s1 && A[i]>s2)
            {
                s2=A[i];
            }
        }
        
    }
    return s2;
}

int main()
{
    int A[MAX];
    int n;
    NhapMang(A,&n);
    XuatMang(A,n);
    printf("So lon nhi la : %d",TimMax2(A,n));
    return 22;
}