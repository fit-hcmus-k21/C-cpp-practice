#include <stdio.h>
#define MAX 100

void array(int b[])
{
    printf("%p\n",&b);
    printf("%p\n",&b[0]);
    printf("%p\n",b);

}

int main()
{
    int a[MAX]={};

    array(a);
    printf("--------------------\n");
    printf("%p\n",&a);
    printf("%p\n",&a[0]);
    printf("%p\n",a);
    return 225;
}