#include "lib03.h"
#pragma

int main()
{
    //  Kiểm thử các hàm đã viết

    cout<<"-------------KET QUA--------------\n";

    int *a;
    int n;

    cout<<"Nhap mang:\n";
    NhapMang(a,n);

    cout<<"Xuat mang:\n";
    XuatMang(a,n);

    cout<<"\nXuat mang nguoc: \n";
    XuatNguoc(a,n);

    cout<<"\nSo lon nhat trong mang: "<<SoLonNhat(a,n)<<endl;

    cout<<"So so nguyen to co trong mang: "<<DemSoNT(a,n)<<endl;

    cout<<"So gia tri phan biet trong mang: "<<DemGTPB(a,0,n)<<endl;

    cout<<"Mang co chua toan so chia het cho 7 hay khong? ";
    if (KiemTra7(a,n))
    {
        cout<<"co\n";
    }
    else
    {
        cout<<"khong\n";
    }

    cout<<"Mang so nguyen theo thu tu tang dan: \n";
    Sapxep(a,n);
    XuatMang(a,n);

    cout<<"\n....hoan thanh...\n";

    return 225;
}