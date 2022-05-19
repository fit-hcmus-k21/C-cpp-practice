#include "lib01.h"

//  Hàm tính S(n) = 1^2 + 2^2 +... +n^2
int TongBinhPhuong(int n)
{   
    if (n==1)
    {
        return 1;
    }
    else
    {
        return n*n+TongBinhPhuong(n-1);
    }
}

//  Hàm tính S(n) = 1 + 1/2 +...+ 1/n
double TongPhanSo(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        return 1.0/n+TongPhanSo(n-1);
    }
}

//  Hàm tính S(n) = 1/2 + 1/4 +... +1/2n
double TongPhanSoChan(int n)
{
    if (n==1)
    {   
        return 1.0/(2*n);
    }
    else
    {
        return ( 1.0/(2*n) + TongPhanSoChan(n-1) ) ;
    }
}

//  Hàm tính S(x,n) = x^2 + x^4 + ... + x^2n 
int TongLuyThua(int x, int n)
{
    if (n==1)
    {
        return (int) pow(x,2*n);
    }
    else
    {
        return (int) pow(x,2*n) + TongLuyThua(x,n-1);
    }
}

//  Hàm tính giá trị số hạng thứ n trong dãy Fibonaci
int GiaTriFibo(int n)
{
    if (n==1)
    {
        return 1;
    }
    if (n==2)
    {
        return 1;
    }
    return GiaTriFibo(n-1) + GiaTriFibo(n-2);
}
