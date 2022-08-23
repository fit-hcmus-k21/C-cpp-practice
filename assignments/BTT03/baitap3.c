#include <stdio.h>

int main()
{
    int n;
    printf("enter a positive integer: ");
    scanf("%d",&n);
    for (; ; )
        if (n<=0)
            continue;

    return 0;
}