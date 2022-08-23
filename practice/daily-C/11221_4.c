#include <stdio.h>

int sodao(int n)
{
        int digit;
        int sodao=0;
        while (n!=0)
        {
                digit=n%10;
                sodao=sodao*10+digit;
                n=n/10;
        }
        return sodao;
}

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
void DocIn(int y)
{
    int cs;
    while (y!=0)
    {
        cs=y%10;
        switch(cs)
        {
            case 0: 
                    printf("Zero ");
                    break;
            case 1:
                    printf("One ");
                    break;
            case 2:
                    printf("Two ");
                    break;
            case 3:
                    printf("Three ");
                    break;
            case 4:
                    printf("Four ");
                    break;
            case 5:
                    printf("Five ");
                    break;
            case 6:
                    printf("Six ");
                    break;
            case 7:
                    printf("Seven ");
                    break;
            case 8:
                    printf("Eight ");
                    break;
            case 9:
                    printf("Nine ");
                    break;
        }
        y=y/10;
    }
}

int main()
{
    int n;
    printf("Nhap vao so nguyen n :");
    scanf("%d",&n);
    if (n<=100||n>=100000) return main();
    printf("Result : %d :", Tong(n));
    DocIn(Tong(n));
    printf("\n");
    DocIn(sodao(n));
    return 225;
}