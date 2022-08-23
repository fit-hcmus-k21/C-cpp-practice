/* Viết hàm sắp xếp 3 số theo thứ tự tăng dần/giảm dần. */

#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void ascending(int *a,int *b, int *c)
{
    if (*a>*b) swap(a,b);
    if (*a>*c) swap(a,c);
    if (*b>*c) swap(b,c);
    printf("Ascending : %d %d %d",*a,*b,*c);
}
void descending(int *a,int *b, int *c)
{
    if (*a<*b) swap(a,b);
    if (*a<*c) swap(a,c);
    if (*b<*c) swap(b,c);
    printf("\nDescending : %d %d %d",*a,*b,*c);
}
int main()
{
    int x,y,z;
    printf("Enter 3 integers :");
    scanf("%d %d %d",&x,&y,&z);
    ascending(&x,&y,&z);
    descending(&x,&y,&z);
    return 225;
}