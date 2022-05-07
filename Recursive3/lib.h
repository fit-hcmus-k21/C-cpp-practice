#include <iostream>
#include <iomanip>
using namespace std;

//  Khởi tạo bàn cờ
void KhoiTao(int **&a, int N);

//  Hàm in bàn cờ : các vị trí có giá trị là số thứ tự bước đi của quân mã
void In(int **a,int N);

//  Hàm kiểm tra xem quân mã có thể đi tiếp tại vị trí hiện tại không
void KiemTra(int **&a, int N, int i, int j, int stt);