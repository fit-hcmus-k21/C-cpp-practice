#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int sum=0;
    int digit;
    while (n!=0)
    {
        digit=n%10;
        sum=sum+digit;
        n=n/10;
    }
     printf("Result : %d",sum);   
    return 0;
}