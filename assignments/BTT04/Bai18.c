#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int first_digit;
    while (n!=0)
    {
        first_digit=n%10;
        n=n/10;
    }
    printf("Result : %d",first_digit);
    return 0;
}
