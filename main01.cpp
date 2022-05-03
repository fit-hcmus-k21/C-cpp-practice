#include "lib01.h"
#pragma()

int main()
{
    //  Kiểm các hàm đã viết
    int x,n;
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"Nhap n: ";
    cin>>n;
    cout<<"--------------------KET QUA----------------\n";

    cout<<"S(n) = 1^2+2^2+...+n^2\n";
    cout<<"=> S("<<n<<") : "<<TongBinhPhuong(n)<<endl;

    cout<<"S(n) = 1+1/2+...+1/n\n";
    cout<<"=> S("<<n<<") : "<<TongPhanSo(n)<<endl;

    cout<<"S(n) = 1/2+1/4+...+1/2n\n";
    cout<<"=> S("<<n<<") : "<<TongPhanSoChan(n)<<endl;

    cout<<"S(x,n) = x^2+x^4+...+x^2n\n";
    cout<<"=> S("<<n<<") : "<<TongLuyThua(x,n)<<endl;

    cout<<"Gia tri so hang thu "<<n<<"trong day Fibonaci:\n";
    cout<<"=> F("<<n<<") : "<<GiaTriFibo(n)<<endl;

    cout<<"...hoan thanh...\n";

    return 225;
}