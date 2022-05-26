#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tuSo;
    int mauSo;
public:
    PhanSo()
    {
        tuSo=mauSo=0;
    }
    ~PhanSo()
    {
        tuSo=mauSo=0;
    }

    //  Nhập
    void set()
    {
        cout<<"Nhap tu so: ";
        cin>>this->tuSo;
        cout<<"Nhap mau so: ";
        cin>>this->mauSo;
    }

    //  Xuất
    void get()
    {
        cout<<this->tuSo<<"/"<<this->mauSo<<endl;
    }

    //  Cộng
    PhanSo Cong(PhanSo ps1,PhanSo ps2)
    {
        PhanSo ps3;
        ps3.tuSo=ps1.tuSo*ps2.mauSo+ps2.tuSo*ps1.mauSo;
        ps3.mauSo=ps1.mauSo*ps2.mauSo;
        return ps3;
    }

    //  Trừ
    PhanSo Tru(PhanSo ps1,PhanSo ps2)
    {
        PhanSo ps3;
        ps3.tuSo=ps1.tuSo*ps2.mauSo-ps2.tuSo*ps1.mauSo;
        ps3.mauSo=ps1.mauSo*ps2.mauSo;
        return ps3;
    }

    //  Nhân
    PhanSo Nhan(PhanSo ps1,PhanSo ps2)
    {
        PhanSo ps3;
        ps3.tuSo=ps1.tuSo*ps2.tuSo;
        ps3.mauSo=ps1.mauSo*ps2.mauSo;
        return ps3;
    }

    //  Chia
    PhanSo Chia(PhanSo ps1,PhanSo ps2)
    {
        PhanSo ps3;
        ps3.tuSo=ps1.tuSo*ps2.mauSo;
        ps3.mauSo=ps1.mauSo*ps2.tuSo;
        return ps3;
    }

};


int main()
{
    PhanSo obj1,obj2,obj3;
    obj1.set();
    obj2.set();
    obj3=obj3.Cong(obj1,obj2);
    obj3.get();
    obj3=obj3.Tru(obj1,obj2);
    obj3.get();
    obj3=obj3.Nhan(obj1,obj2);
    obj3.get();
    obj3=obj3.Chia(obj1,obj2);
    obj3.get();
    cout<<"\nHoan thanh...\n";
    return 225;
}