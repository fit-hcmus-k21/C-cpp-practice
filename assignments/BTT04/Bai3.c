#include <stdio.h>

int main()
{
    int n;
    printf("Enter a positive integer :");
    scanf("%d",&n);
    if (n<0) return main();
    float sum=0;
    for (int i=1;i<=n;i++)
        sum=sum+1.0/(2*i);
    printf("Result : %f",sum);
    return 0;
}