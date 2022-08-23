#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    int factorial=1;
    for (int i=1;i<=n;i++)
        factorial=factorial*i;
    return factorial;
}

float SUM_1(int n)
{
    float sum=0;
    for (int i=1;i<=n;i++)
        sum=sum+1.0/factorial(i);
    return sum;
}

float SUM_2(int n)
{
    float sum=0;
    for (int i=1;i<=n;i++)
        sum=sum+pow(-1,i-1)/factorial(i);
    return sum;
}

float SUM_3(float x,int n)
{
    double sum=0;
    for (int i=1;i<=n;i++)
            sum=sum+pow(-1,i)*pow(x,i)/factorial(i);
    return sum;
}

float SUM_4(float x,int n)
{
    float sum=0;
    int small_sum;
    for (int i=1;i<=n;i++)
    {
        small_sum=0;
        for (int j=1;j<=i;j++) 
            small_sum=small_sum+j;
        sum=sum+pow(-1,i)*pow(x,i)/small_sum;
    }
    return sum;
}


