#include "lib02.h"

//  Hàm đếm số lượng chữ số của số nguyên dương n
int DemChuSo(int n)
{
    if (n<10)
    {
        return 1;
    }
    return DemChuSo(n/10) +1;
}

//  Hàm tính tổng các chữ số chẵn của số nguyên dương n
int TongSoChan(int n)
{
    if (n<10)
    {
        return (n%2==0) ? n : 0;
    }
    return ((n%10)%2==0) ? n%10 + TongSoChan(n/10) : TongSoChan(n/10);
}

//  Hàm tìm chữ số đầu tiên của số nguyên dương n
int ChuSoDauTien(int n)
{
    if (n<10)
    {
        return n;
    }
    return ChuSoDauTien(n/10);
}

//  Hàm tìm số đảo ngược của số nguyên dương n
int SoDao(int n)
{
    if (n<10)
    {
        return n;
    }
    return (n%10)*pow(10,DemChuSo(n)-1) + SoDao(n/10); 
}

//  Hàm tìm chữ số lớn nhất của số nguyên dương n
int ChuSoLonNhat(int n)
{
    if (n<10)
    {
        return n;
    }
    ChuSoLonNhat(n/10);
    return (n%10>ChuSoLonNhat(n/10)) ? n : ChuSoLonNhat(n/10);
}

//  Hàm kiểm tra số nguyên dương n có chứa toàn số lẻ hay không
bool KiemTra(int n)
{
    if (n<10)
    {
        return (n%2==1) ? true : false;
    }
    return (n%2==1) ? KiemTra(n/10) : false;
}
