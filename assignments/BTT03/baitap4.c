#include <stdio.h>;

int main()
{
    int sum=0;
    int i;
    int j;
    int dem=0;
    for (i=1; i<=30; i++)
    {
        for (j=1;j<=i;j++)
           {
                if (i%j==0)    dem=dem+1;        
           }
        if (dem==2) sum=sum+i;
        dem=0;
    }
    printf("Sum of prime numbers from 1 to 30 :%d",sum);
    return 0;
}