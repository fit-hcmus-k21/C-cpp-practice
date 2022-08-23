#include <iostream>
using namespace std;

typedef struct 
{
    char MaSach[7];
    char TenSach[50];
    char NXB[50];
    int Gia;
    int SoTrang;
    int Nam_xb;
} QUYENSACH;

int main()
{
    int LuaChon;
    do
    {
        cout<<endl<<"--------------------------------";
        cout<<endl<<"0. Ket thuc";
        cout<<endl<<"1. Nhap danh sach cac quyen sach";
        cout<<endl<<"2. Xuat danh sach cac quyen sach ra man hinh";
        cout<<endl<<"3. Sap xep cac quyen sach trong mang theo thu tu tang dan cua nam xuat ban";
        cout<<endl<<"4. Tim quyen sach it hon k trang co gia ban cao nhat trong mang";
        cout<<endl<<"5. Them mot quyen sach vao trong mang";
        cout<<endl<<"6. Xoa cac quyen sach co nam xuat ban truoc nam chi dinh ra khoi mang";
        cout<<endl<<"Lua chon? ";
        switch(LuaChon)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            default:
        }

    } while (LuaChon!=0);
    
}