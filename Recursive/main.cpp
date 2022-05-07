#include "lib.h"

int main()
{
    int N=5;
    int **a;
    KhoiTao(a,N);
    DatHau(a,N,0);

    //  Giải phóng bộ nhớ
    for (int i=0;i<N;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 225;
}