#include <stdio.h>
#include "41221_1.h"

int main()
{
    int Array[5]={22,5,2003,18,888};
    int B[5]={22};
    printf("Tong la : %d\n",TongArray(Array,5));
    printf("Trung Binh la: %f\n",TBArray(Array,5));
    CopyArray(Array,B,5);
    for  (int i=0;i<5;i++) printf("B[%d] = %d\n",i,B[i]);
    MaxArray(Array,225,5);
    for (int i=0;i<5;i++) printf("A[%d] = %d ",i,Array[i]);
    SxArray(Array,5);
    for(int i=0;i<5;i++) printf("A[%d] = %d ",i,Array[i]);
    return 0;

}