#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    printf("Enter a integer: ");
    scanf("%d",&x);
    int n;
    printf("Enter a positive integer :");
    scanf("%d",&n);
    if (n<0) return main();
    int sum=0;
    for (int i=1;i<=n;i++)
        sum=sum+pow(x,(2*i));
    printf("Result: %d",sum);
    return 0;
}