#include <iostream>
#include <iomanip>
using namespace std;

typedef struct 
{
    char name[10];
    char mssv[10];
    int diemSo[3];
}SinhVien;

SinhVien nhap();
void Xuat(SinhVien *SV,int sl);