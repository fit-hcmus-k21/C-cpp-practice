#include <stdio.h>

int main()
{
    printf("Enter a range of integers :");
    int n;
    int min;
    scanf("%d",&n);
    if (n!=0) min=n;
    else
    {
        printf("There is not any suitable integer !");
        return 0;
    }
    do 
    {
        scanf("%d",&n);
        if (min>n) min=n;
    }
    while (n!=0);
    printf("Result : %d",min);
    return 0;
}