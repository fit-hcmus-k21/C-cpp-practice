#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int x;
    printf("Enter a positive integer:");
    scanf("%d",&n);
    printf("Enter a integer:");
    scanf("%d",&x);
    if (n<0) return main();
    float big_sum=0;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        sum=sum+i;
        big_sum=big_sum+(float)(pow(x,i))/(sum);
    }
    printf("Result : %f",big_sum);
    return 0;

}