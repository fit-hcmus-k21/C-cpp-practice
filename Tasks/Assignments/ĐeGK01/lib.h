#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#define M 30
#define N 30

//  Khai báo cấu trúc thông tin con mèo

typedef struct 
{
    int ID;
    char *KindCat = new char[M];
    char *FurCollor = new char[N];
    float Weight;
} MewMew;

//  Hàm Nhập thông tin

MewMew NhapThongTin();

//  Khởi tạo danh sách

void KhoiTaoDS(MewMew *&DS, int &sl );

//  Xuất thông tin

void XuatThongTin(MewMew meo);

//  Hàm kiểm tra danh sách có rỗng hay không

void KiemTra(MewMew *&DS, int sl);

//  Thêm 1 con mèo cuối danh sách

void AddCat(MewMew *&DS, int &sl);

//  Xóa 1 con mèo cuối danh sách

void DeleteCat(MewMew *&DS,int &sl);

//  Tìm mèo có cân nặng nhỏ nhất
void FindCat(MewMew *&DS, int sl);

//  Cập nhật màu lông cho mèo

void UpdateFur(MewMew *&DS, int sl);

//  Hoán đổi 2 con mèo
void Swap(MewMew *a, MewMew *b);

//  Sắp xếp danh sách mèo theo tăng dần cân nặng
void ArrrangeCat(MewMew *&DS,int sl);

//  Tìm 3 con mèo có cân nặng lớn nhất

void Find3Cat(MewMew *&DS, int sl);

//  Xóa rỗng danh sách

void DeleteDS(MewMew *&DS)
