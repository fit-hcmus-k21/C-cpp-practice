#include <stdio.h>
#include <stdbool.h>
bool kiemtra(int a)
{
    bool kiemtra =false;
    if (a % 10!=0) kiemtra=true;
    return kiemtra;
}

int sodao(int *b)
{
    int sodao=0;
    int cs;
    int sotam=*b;
    while (sotam!=0)
    {
        cs=sotam%10;
        sodao=sodao*10+cs;
        sotam=sotam/10;
    }
    *b=sodao;
    return *b;
}

int timkiem(int x,int *min,int *max)
{
    int cs;
    while (x!=0)
    {
        cs=x%10;
        if (cs<*min) *min=cs;
        if (cs>*max) *max=cs;
        x=x/10;
    }
    return 225;
}

int main()
{
    int n;
    printf("Nhap vao so nguyen n : ");
    scanf("%d",&n);
    if (n<10 || n>10000 || !kiemtra(n)) return main();
    int bansao=n;
    sodao(&bansao);
    int min=n%10;
    int max=n%10;
    timkiem(n,&min,&max);
    printf("Result : \n");
    printf("So dao cua %d la : %d\n",n,bansao);
    printf("Chu so lon nhat la : %d",max);
    printf("\nChu so nho nhat la: %d",min);
    return 22503;
}