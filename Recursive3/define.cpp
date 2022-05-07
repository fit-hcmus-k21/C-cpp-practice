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

//  Hàm kiểm tra xem quân mã có thể đi tiếp tại vị trí hiện tại không
void KiemTra(int **&a, int N, int i, int j, int stt)
{
    if (stt==N*N)
    {
        In(a,N);
        return ;
    }
    //  8 vị trí mà quân mã ở vị trí (i,j) có thể đi tiếp:
    //  Vị trí 1:   (i-2;j+1)
    if (i-2>=0 && j+1<N && a[i-2][j+1]==0)
    {
        //  Nếu đi được thì đánh dấu vị trí mới đó
        a[i-2][j+1]=stt;
        KiemTra(a,N,i-2,j+1,stt+1);
        a[i-2][j+1]=0;
    }

    {
        //  Vị trí 2:   (i-2;j-1)
        if (i-2>=0 && j-1>=0 && a[i-2][j-1]==0)
        {
            //  Nếu đi được thì đánh dấu vị trí mới đó
            a[i-2][j-1]=stt;
            KiemTra(a,N,i-2,j-1,stt+1);
            a[i-2][j-1]=0;
        }
        
        {
            //  Vị trí 3:   (i-1;j+2)
            if (i-1>=0 && j+2<N && a[i-1][j+2]==0)
            {
                //  Nếu đi được thì đánh dấu vị trí mới đó
                a[i-1][j+2]=stt;
                KiemTra(a,N,i-1,j+2,stt+1);
                a[i-1][j+2]=0;
            }
            
            {
                //  Vị trí 4:   (i-1;j-2)
                if (i-1>=0 && j-2>=0 && a[i-1][j-2]==0)
                {
                    //  Nếu đi được thì đánh dấu vị trí mới đó
                    a[i-1][j-2]=stt;
                    KiemTra(a,N,i-1,j-2,stt+1);
                    a[i-1][j-2]=0;
                }
                
                {
                    //  Vị trí 5:   (i+1;j+2)
                    if (i+1<N && j+2<N && a[i+1][j+2]==0)
                    {
                        //  Nếu đi được thì đánh dấu vị trí mới đó
                        a[i+1][j+2]=stt;
                        KiemTra(a,N,i+1,j+2,stt+1);
                        a[i+1][j+2]=0;
                    }
                    
                    {
                        //  Vị trí 6:   (i+1;j-2)
                        if (i+1<N && j-2>=0 && a[i+1][j-2]==0)
                        {
                            //  Nếu đi được thì đánh dấu vị trí mới đó
                            a[i+1][j-2]=stt;
                            KiemTra(a,N,i+1,j-2,stt+1);
                            a[i+1][j-2]=0;
                        }
                        
                        {
                            //  Vị trí 7:   (i+2;j+1)
                            if (i+2<N && j+1<N && a[i+2][j+1]==0)
                            {
                                //  Nếu đi được thì đánh dấu vị trí mới đó
                                a[i+2][j+1]=stt;
                                KiemTra(a,N,i+2,j+1,stt+1);
                                a[i+2][j+1]=0;
                            }
                            
                            {
                                //  Vị trí 8:   (i+2;j-1)
                                if (i+2<N && j-1>=0 && a[i+2][j-1]==0)
                                {
                                    //  Nếu đi được thì đánh dấu vị trí mới đó
                                    a[i+2][j-1]=stt;
                                    KiemTra(a,N,i+2,j-1,stt+1);
                                    a[i+2][j-1]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}