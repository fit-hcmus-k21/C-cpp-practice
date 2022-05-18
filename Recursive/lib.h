#include <iostream>
using namespace std;

//  Hàm khởi tạo bàn cờ NxN ô khi chưa đặt quân hậu 
void KhoiTao(int **&a,int N);

//  Hàm in bàn cờ NxN ô
void In(int **a, int N);

//  Hàm kiểm tra vị trí hàng row, cột col có đặt quân hậu được hay không
bool KiemTra(int **a, int row, int col, int N);

//  Hàm đệ quy đặt quân hậu
void DatHau(int **&a, int N, int i);