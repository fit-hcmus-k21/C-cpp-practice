#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool snt(int n)
{
    if (n==1) return false;
    for (int i=2;i<=n/2;i++)
        if (n%i==0) return false;
    return true;
}
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    int d=3;
    for (int i=2;d<=n;i++)
    {
        d=pow(2,i)-1;
        if (snt(d))
            printf("%d ",d);
    }
    return 22;
}