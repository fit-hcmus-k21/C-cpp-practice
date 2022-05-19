#include <iostream>
#include <iomanip>
using namespace std;

//  Các bước mà quân mã có thể đi là (i+dx,j+dy)

//  Khởi tạo bàn cờ
void KhoiTao(int **&a, int N);

//  Hàm in bàn cờ : các vị trí có giá trị là số thứ tự bước đi của quân mã
void In(int **a,int N);

//  Hàm di chuyển của quân mã trên bàn cờ
void DiTuan(int **&a, int N, int row, int col, int stt);