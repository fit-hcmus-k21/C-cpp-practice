/*  Viết hàm hoán vị 2 số
    a) void HoanVi(int& a, int& b);
    b) void HoanVi_pnt(int *a, int *b); */

#include <stdio.h>

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

