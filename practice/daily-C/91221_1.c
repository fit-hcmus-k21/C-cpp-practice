#include <stdio.h>
#include <stdbool.h>

bool snt(int n)
{
    if (n==1) return false;
    for (int i=2;i<=n/2;i++)
        if (n%i==0) return false;
    return true;
}
int sodao(int n)
{
    int sodao=0;
    int cs;
    while (n!=0)
    {
        cs=n%10;
        sodao=sodao*10+cs;
        n=n/10;
    }
    return sodao;
}

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
        if (snt(i) && snt(sodao(i)))    
            printf("%d ",i);
    return 22;
}