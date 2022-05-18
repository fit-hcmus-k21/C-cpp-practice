#include "lib.h"

//  Giải bài toán mã đi tuần ở mức độ tổng quát

int main()
{
    int N=7;
    int **a;
    KhoiTao(a,N);

    int row=2;
    int col=0;
    
    /***
    cout<<"Nhap vi tri ban dau cua quan ma (i,j):  ";
    cin>>row>>col;
    ***/

    int stt=1;

    //  Tìm các vị trí đi được của quân mã
    DiTuan(a,N,row,col,stt);

    cout<<"\nok....\n";
    //  Giải phóng bộ nhớ
    for (int i=0;i<N;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    cout<<"\nHoan thanh...\n";
    return 225;
}