/*
Cho hàm con sau
Giá trị trả về của f(p,p) là bao nhiêu nếu giá trị của p được khởi tạo là 5 trước lệnh
gọi. Lưu ý rằng tham số đầu tiên được truyền bằng tham chiếu, tham số thứ hai được truyền
bằng giá trị.
int f(int &x, int c) 
{
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    return f(x, c) * x;
}

Hãy cho biết kết quả nào sau đây là giá trị trả về đúng
(a) 3024
(b) 6561
(c) 55440
(d) 161051
Chạy chương trình và cho biết tại sao chương trình trả về kết quả đó?

=> Chọn B :Hàm đệ quy
f(5,5): 
{
    c==4;
    x==6;
    f(6,4)*6:
    {
        c==3;
        x==7;
        f(7,3)*7:
        {
            .... đến khi c==0...
        }
    }
}

*/

#include <iostream>
using namespace std;

int f(int &x, int c) 
{
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    return f(x, c) * x;
}

int main()
{
    int p=5;
    printf("Result: %d",f(p,p));
    return 225;

}