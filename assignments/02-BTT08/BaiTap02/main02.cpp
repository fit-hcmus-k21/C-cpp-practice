#include "lib02.h"

int main()
{
    //  Kiểm thử các hàm đã viết
    int n;
    cout<<"Nhap so nguyen duong n: ";
    cin>>n;
    cout<<"---------------KET QUA---------------\n";
    
    cout<<"So luong chu so cua "<<n<<" :"<<DemChuSo(n)<<endl;

    cout<<"Tong cac chu so chan cua "<<n<<" : "<<TongSoChan(n)<<endl;

    cout<<"Chu so dau tien cua "<<n<<" : "<<ChuSoDauTien(n)<<endl;

    cout<<"So dao nguoc cua "<<n<<" : "<<SoDao(n)<<endl;

    cout<<"Chu so lon nhat cua "<<n<<" : "<<ChuSoLonNhat(n)<<endl;

    cout<<"So "<<n;KiemTra(n) ? cout<<" chua toan so le !\n" : cout<<" khong chua toan so le !"<<endl;

    cout<<"....hoan thanh...\n";
    return 225;
}