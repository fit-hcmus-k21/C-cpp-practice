#include <stdio.h>

int Tong(int x)
{
    int S=0;
    int cs;
    while (x!=0)
    {
        cs=x%10;
        S=S+cs;
        x=x/10;
    }
    return S;
}

int main()
{
    int n;
    printf("Nhap vao so nguyen n :");
    scanf("%d",&n);
    if (n<=100||n>=100000) return main();
    printf("Result : %d", Tong(n));
    return 225;
}