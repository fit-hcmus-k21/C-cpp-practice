#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive integer :");
    scanf("%d",&n);
    if (n<0) return main();
    float sum=0;
    for (int i=0;i<=n;i++)
        sum=sum+(float) (2*i+1)/(2*i+2);
    printf("Result: %f",sum);
    return 0;
}