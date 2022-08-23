#include <stdio.h>

int main ()
{
    int a;
    int b;
    printf("Enter integer a :");
    scanf("%d",&a);
    printf("Enter integer b :");
    scanf("%d",&b);
    int tempt;
    if (a<b)
        {
            tempt=a;
            a=b;
            b=tempt;
        }
    if (a%b==0) 
        printf(" The greatest common divisor :%d",b);
    else
    {
        for (int i=b;i>=1;i--)
            
                if (a%i==0 && b%i==0) 
                    {
                        printf("The greatest common divisor :%d",i);
                        break;
                    }
    }
    return 0;
}