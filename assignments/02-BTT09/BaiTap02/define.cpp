#include "lib.h"

//  Giải bài toán tám hậu ở mức độ tổng quát

//  Hàm khởi tạo bàn cờ NxN ô khi chưa đặt quân hậu 
void KhoiTao(int **&a,int N)
{
    //  Cấp phát bộ nhớ                 1.  Nhớ giải phóng
    a = new int*[N];
    for (int i=0;i<N;i++)
    {
        a[i]=new int[N];
    }
    //  Thiết lập giá trị tất cả các ô là 0 
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            a[i][j]=0;
        }
    }
}

//  Hàm in bàn cờ NxN ô
void In(int **a, int N)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//  Hàm kiểm tra vị trí hàng row, cột col có đặt quân hậu được hay không
bool KiemTra(int **a, int row, int col, int N)
{
    //  Kiểm tra trên cùng cột
    for (int i=0;i<row;i++)
    {
        if (a[i][col]!=0)
        {
            //cout<<"false cot:"<<i<<","<<col<<endl;
            return false;
        }
    }

    //  Kiểm tra đường chéo trên
    int i=row-1, j=col-1;
    while (i>=0 && j>=0)
    {
        if (a[i][j]!=0)
        {
            //cout<<"false dct: "<<i<<","<<j<<endl;
            return false;
        }
        i--;
        j--;
    }

    //  Kiểm tra đường chéo dưới
    int m=row-1, n=col+1;
    while (m>=0 && n<N)
    {
        if (a[m][n]!=0)

        {
            //cout<<"false dcd: "<<m<<","<<n<<endl;
            return false;
        }
        m--;
        n++;
    }

    //  Nếu tất cả đều thỏa thì trả về true: có thê đặt quân hậu tại vị trí đó 
    return true;
}

//  Hàm đệ quy đặt quân hậu
void DatHau(int **&a, int N, int i)
{
    //  Xét theo từng hàng i: 0 -> N-1

    //  Trong mỗi hàng xét ở vị trí j xem có thể đặt quân hậu tại đấy không

    //  Những ô đặt quân hậu là 1
    if (i==N)
    {
        In(a,N);
        return;
    }

    for (int j=0;j<N;j++)
    {
            if (KiemTra(a,i,j,N))
            {
                //  Đánh dấu ô đặt hậu là số 1
                a[i][j]=1;

                //  Đặt hậu cho hàng tiếp theo
                DatHau(a,N,i+1);
                
                //  Đánh dấu lại
                a[i][j]=0;
                
            }
    }
}

