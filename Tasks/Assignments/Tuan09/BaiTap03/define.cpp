#include "lib.h"

//  Khởi tạo bàn cờ
void KhoiTao(int **&a, int N)
{
    a = new int*[N];
    for (int i=0;i<N;i++)
    {
        a[i] = new int[N];
    }
    //  Khởi tạo giá trị 0 cho các ô trong bàn cờ
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            a[i][j]=0;
        }
    }
}

//  Hàm in bàn cờ : các vị trí có giá trị là số thứ tự bước đi của quân mã
void In(int **a,int N)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout<<setw(2)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
} 

//  Hàm di chuyển của quân mã trên bàn cờ
void DiTuan(int **&a, int N, int row, int col, int stt)
{
    int dx[8]={-2,-2,-1,-1,1,1,2,2};
    int dy[8]={-1,1,-2,2,-2,2,-1,1};
    //  Đánh dấu vị trí (i,j) đã đi
    a[row][col]=stt++;

    int newX;
    int newY;

    for (int i=0;i<8;i++)
    {
        if (stt==N*N+1)
        {
            //  Nếu đã đi đủ N*N bước thì in bàn cờ các bước đi
            In(a,N);
            exit(225);
        }

        //  Tọa độ bước đi mới
        newX=row + dx[i];
        newY=col + dy[i];

        //  Kiểm tra bước đi mới có hợp lệ hay không
        if (newX<N && newX>=0 && newY<N && newY>=0 && a[newX][newY]==0)
        {
            DiTuan(a,N,newX,newY,stt);
        }
    }
    //  Nếu không đi được 1 trong 8 vị trí đó thì trả lại giá trị ban đầu và quay lại vị trí khác
    stt--;
    a[row][col]=0;
}