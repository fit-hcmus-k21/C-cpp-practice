#include <iostream>
#include <string.h>
using namespace std;

typedef struct 
{
    int STT;
    char TenMon[50];
    int GiaTien;
} MON_AN;

typedef struct 
{
    int slm;
    MON_AN * TM= new MON_AN[slm];       // nhớ delete[] TM;
    int TGT;
    int GT;
} PHAN_AN;


int main()
{
    // Khởi tạo danh sách món ăn
    MON_AN x[6];
    for (int i=0;i<6;i++)
    {
        x[i].STT=i+1;
    }
    strcpy(x[0].TenMon,"Burger");
    strcpy(x[1].TenMon,"Cheese burger");
    strcpy(x[2].TenMon,"Chicken burger");
    strcpy(x[3].TenMon,"Drink");
    strcpy(x[4].TenMon,"Potato");
    strcpy(x[5].TenMon,"Ice cream");
    x[0].GiaTien=130;
    x[1].GiaTien=150;
    x[2].GiaTien=200;
    x[3].GiaTien=130;
    x[4].GiaTien=120;
    x[5].GiaTien=160;

    cout<<"Chon mot trong cac phan an sau:"<<endl;
    cout<<"1: Phan an A (Burger, Drink, Potato)"<<endl;
    cout<<"2. Phan an B (Cheese burger, Drink, Potato)"<<endl;
    cout<<"3. Phan an C (Chicken burger, Drink, Potato)"<<endl;
    cout<<"4. Phan an D (Chicken burger, Drink, Potato, Ice cream)"<<endl;



    int LuaChon;
    switch(LuaChon)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        default:
    }

    return 225;
}