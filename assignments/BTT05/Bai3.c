#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prime(int n)
{
    if (n==0||n==1) return false;
    for (int i=2;i<=(int)sqrt(n);i++)
        if (n%i==0) return false;
    return true;
}

int main()
{
    int sum=0;
    for (int i=1;i<=50;i++)
        if (prime(i)) sum=sum+i;
    printf("Result : %d",sum);
    return 0;
}