#include <iostream>
#include <string.h>
using namespace std;

typedef struct 
{
    int mssv;
    char hoten[51];
    float dtb;
} SINHVIEN;

//  Nhập 1 sinh viên từ bàn phím

SINHVIEN nhap();

//  Xuất 1 sinh viên ra màn hình

void xuat(SINHVIEN sv);

//  Kiểm tra mssv có hợp lệ hay không

bool kiemtra_mssv(int mssv);

//  Hiệu chỉnh tên sinh viên

void HieuChinh(char *HoTen);

//  Kiểm tra một chuỗi cho trước có xuất hiện trong tên sinh viên hay không

bool kiemtra_Hoten(char *HoTen,char *Chuoi_kitu);

//  Nhập danh sách sinh viên

void Nhap_DSSV(SINHVIEN *DSSV,int sl);

//  Xuất danh sách sinh viên

void Xuat_DSSV(SINHVIEN *DSSV,int sl);

// Tìm sinh viên có điểm trung bình cao nhất

void TimSV_DTB_Max(SINHVIEN *DSSV,int sl);

//  Hoán đổi 2 sinh viên

void hoandoi(SINHVIEN *a,SINHVIEN *b);

//  Sắp xếp DSSV tăng dần theo mssv

void SapXep_TangDan(SINHVIEN *DSSV,int sl);

//  Sắp xếp DSSV giảm dần theo mssv

void SapXep_GiamDan(SINHVIEN *DSSV,int sl);

//Sắp xếp DSSV theo đtb giảm dần

void SapXep_DTB(SINHVIEN *DSSV,int sl);

//  Sắp xếp DSSV cùng điểm theo mssv giảm dần

void Sap_xep_mssv(SINHVIEN *DSSV,int sl);

// Tìm 5 sinh viên có điểm trung bình cao nhất, nếu có nhều sinh viên có cùng điểm tb cao nhất thì ưu tiên chọn các bạn sinh viên cố mssv nhỏ hơn

void Tim_5sv(SINHVIEN *DSSV,int sl);



