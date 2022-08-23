#include<stdio.h>
int main()
{
    float sum, x;
    while (x > 0)
    {
        printf(" Input a number : ");
        scanf(" %f",&x);
        if (x > 0)
        {
            sum += x ;
        }
        
    }
    printf("Sum all numbers = %f",sum);
    return 1;
    
}