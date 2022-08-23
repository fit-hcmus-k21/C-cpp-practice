#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int sum=0;
    for (int i=1;i<=n;i++)
        if (n%i==0) sum=sum+i;
    printf("Result : %d",sum);
    return 0;
}