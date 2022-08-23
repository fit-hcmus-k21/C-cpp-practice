#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int max=0;
    int digit;
    while (n!=0)
    {
        digit=n%10;
        if (max<digit) max=digit;
        n=n/10;
    }
    printf("Result : %d",max);
    return 0;
}