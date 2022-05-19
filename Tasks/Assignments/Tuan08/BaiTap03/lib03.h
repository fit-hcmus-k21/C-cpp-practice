#include <iostream>
#include <cmath>
using namespace std;

//  Hàm nhập mảng số nguyên (Không đệ qui)
void NhapMang(int *&a, int &n);

//  Hàm xuất mảng số nguyên ra màn hình
void XuatMang(int *a, int n);

//  Hàm xuất mảng số nguyên ra màn hình theo thứ tự ngược (từ n-1 đến 0)
void XuatNguoc(int *a,int n);

//  Hàm tìm số lớn nhất trong mảng số nguyên
int SoLonNhat(int *a, int n);

//  Hàm kiểm tra số nguyên tố
bool KiemTraSNT(int a);

//  Hàm đếm các số nguyên tố có trong mảng số nguyên
int DemSoNT(int *a, int n);

//  Hàm đếm các giá trị phân biệt trong mảng số nguyên (các số trùng nhau chỉ đếm 1 lần)
int DemGTPB(int *a,int csDau,int n);

//  Hàm kiểm tra mảng số nguyên có chứa toàn số chia hết cho 7 hay không
bool KiemTra7(int *a,int n);

//  Hàm hoán đổi hai số
void swap(int &a, int &b);

//  Hàm sắp xếp mảng số nguyên theo thứ tự tăng dần
void Sapxep(int *a,int n);

/***
//  Hàm lấy chỉ số của số lớn nhât
int GetPosMax(int *a, int n);

//  Hàm sắp xếp mảng số nguyên theo thứ tự tăng dần
void SapXepTD(int *a, int n);

***/
