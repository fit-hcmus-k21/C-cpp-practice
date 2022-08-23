#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive integer :");
    scanf("%d",&n);
    if (n<0) return main();
    int sum=0;
    int fac=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
            fac=fac*j;
        sum=sum+fac;
        fac=1;
    }
    printf("Result: %d",sum);
    return 0;
}