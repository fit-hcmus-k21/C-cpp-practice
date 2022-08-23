#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool squareroot(int n)
{
    double a=sqrt(n);
    if (a*a==n) 
        return true;
    else
        return false;
}

double average()
{
    double S=0;
    int cout=0;
    for (int i=1;i<=100;i++)
        if (squareroot(i)) 
        {
            S=S+i;
            cout++;
        }
    return S/cout;
}


int main()
{
    printf("Result: %lf",average());

    int x;
    printf("\nEnter a number:");
    scanf("%d",&x);
    if (squareroot(x))
        printf("%d is a square root !",x);
    else
        printf("%d is not a square root !",x);
    return 225;
}