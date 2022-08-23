#include <stdio.h>
#define MAX 100

void Nhap(int A[][MAX],int *m,int *n)
{
    printf("Nhap so hang m:");
    scanf("%d",m);
    printf("Nhap so cot n :");
    scanf("%d",n);
    printf("--------Bat dau nhap---------\n");
    for (int i=0;i<*m;i++)
    {
        for (int j=0;j<*n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
}

int Tong(int A[][MAX], int i,int j,int k)
{
    int s=0;
    int d1=0;
    for (int x=i;d1++<k;x++)
    {
        int d2=0;
        for (int y=j;d2++<k;y++)
        {
            s=s+A[x][y];
        }
    }
    return s;
}

int main()
{
    int A[MAX][MAX];
    int m,n;
    Nhap(A,&m,&n);
    int k;
    int sum;
    do
    {
        printf("Nhap k : (k<min(m,n) :");
        scanf("%d",&k);
    } while (k>=m || k>=n);
    int max=Tong(A,0,0,k);
 
    {
        for (int i=0;i<=m-k;i++)
        {
            for (int j=0;j<=n-k;j++)
            {
                sum=Tong(A,i,j,k);
                if (sum>max)
                {
                    max=sum;
                }

            }
        }
    } 
    printf("Tong lon nhat [k x k ] : %d\n",max);
    return 22;

}