#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    int count=0;
    for (int i=1;i<=n;i++)
        if (n%i==0 && i%2==1) count=count+1;
    printf("Result: %d",count);
    return 0; 
}