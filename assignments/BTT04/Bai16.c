#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter positive integer:");
    scanf("%d",&n);
    if (n<=0) return main();
    bool square_root=false;
    int tempt=(int) sqrt(n);
    if (tempt*tempt==n) square_root=true;
    if (square_root) printf("Result: %d is a square root !",n);
    else 
                    printf("Result : %d is not a square root !",n);
    return 0;
}