/* Viết hàm tìm số nhỏ nhất/lớn nhất của 3 sô*/

#include <stdio.h>

int min(int a,int b, int c)
{
    int min=a;
    if (min>b) min=b;
    if (min>c) min=c;
    return min;
}
int max(int a,int b,int c)
{
    int max=a;
    if (max<b) max=b;
    if (max<c) max=c;
    return max;
}

int main()
{
    int a,b,c;
    printf("Enter 3 integers : ");
    scanf("%d %d %d",&a,&b,&c);
    printf("Result :");
    printf("\nMin : %d",min(a,b,c));
    printf("\nMax : %d",max(a,b,c));
    return 225;
}