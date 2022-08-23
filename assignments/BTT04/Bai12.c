#include <stdio.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    for (int i=1;i<=n;i++)
        if (n%i==0) printf("%d  ",i);
    return 0;
}