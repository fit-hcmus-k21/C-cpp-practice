/* Viết hàm tính tổng, hiệu của 2 số.*/

#include <stdio.h>
int Tong(int a, int b)
{
    int S=a+b;
    return S;
}
int Hieu(int a, int b)
{
    int H=a-b;
    return H;
}

int main()
{
    int x,y;
    printf("Nhap hai so :");
    scanf("%d %d",&x,&y);
    printf("Tong la : %d",Tong(x,y));
    printf("\nHieu la : %d",Hieu(x,y));
    return 225;
}