#include "lib.h"

//  Giải bài toán mã đi tuần ở mức độ tổng quát

int main()
{
    int N=8;
    int **a;
    int row=2;
    int col=0;
    int stt = 1;
    /***
    cout<<"Nhap vi tri ban dau cua quan ma (i,j):  ";
    cin>>row>>col;
    ***/
    a[row][col]=stt++;

    //  Tìm các vị trí đi được của quân mã
    KiemTra(a,N,row,col,stt);


    //  Giải phóng bộ nhớ
    for (int i=0;i<N;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 225;
}