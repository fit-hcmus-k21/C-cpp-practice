#include <stdio.h>
#include <math.h>

int main()
{
    int binary;
    printf("Enter a binary number : ");
    scanf("%d",&binary);
    int duplicate=binary;
    int digit;
    float decimal=0;
    int count=0;
    while (binary!=0) 
    {
        digit=binary%10;
        decimal=decimal+digit*pow(2,count);
        count=count+1;
        binary=binary/10;
    }
    printf("Result : %d => %.0f",duplicate,decimal);
    return 0;
}