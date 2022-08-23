#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Enter integer a :");
    scanf("%d",&a);
    printf("Enter integer b :");
    scanf("%d",&b);
    //Find the greatest common of a and b :
    int max_common_divisor;
    int tempt;
    if (a<b)
        {
            tempt=a;
            a=b;
            b=tempt;
        }
    if (a%b==0) max_common_divisor=b; 
    else
    {
        for (int i=b;i>=1;i--)
            
                if (a%i==0 && b%i==0) 
                {
                    max_common_divisor=i;
                    break;
                }
    }
    int min_common_multiple;
    min_common_multiple = (a*b)/max_common_divisor;
    printf("Result : %d", min_common_multiple);
    return 0;
}