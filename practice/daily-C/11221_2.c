#include <stdio.h>
#include <math.h>

int main()
{
    int x,n;
    printf("Nhap vao so nguyen duong x va n : ");
    scanf("%d %d",&x,&n);
    if (x<=0 || n<=0) return main();
    int S=0;
    for (int i=1;i<=n;i++)
        S=S+pow(i,2)*pow(x,i)*pow(-1,i+1);
    printf("Result : S = %d",S);
    return 225;
}