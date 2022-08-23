#include <stdio.h>
#define MAX 100
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int f1=0;
    int f2=1;
    int fn;
    int a[MAX]={0,0,1};         //a[1]=0;   a[2]=1; an=a(n-1)+a(n-2)
    

    for (int i=3;i<=n;i++)
    {
        fn=f1+f2;
        a[i]=fn;
        f1=f2;
        f2=fn;
    }
    printf("%d so fibonaci dau tien la :\n",n);
    for (int j=1;j<=n;j++)
    {
        printf("%d ",a[j]);
    }
    return 22;
}