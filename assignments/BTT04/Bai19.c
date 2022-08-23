#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int reverse=0;
    int digit;
    while (n!=0)
    {
       digit=n%10;
       reverse=reverse*10+digit;
       n=n/10; 
    }
    printf("Result : %d",reverse);    
    return 0;
}