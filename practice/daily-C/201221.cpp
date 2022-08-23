#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct quan_ly_ho_dan
{
    char ma_ho[10];
    char ten_chu_ho[40];
    int so_thanh_vien;
    float muc_thu_nhap;
    bool ho_ngheo;
    float tro_cap;
};
void title()
{
    cout << setw(11) << left << "Ma ho dan";
    cout << setw(30) << left << "Ten chu ho";
    cout << setw(30) << right << "So thanh vien";
    cout << setw(30) << right << "Muc thu nhap";
    cout << setw(15) << right << "Ho ngheo";
    cout << setw(30) << right << "Tro cap";
    cout << endl;
    {
	int chon;
	do
	{
		cout << "\n============= MAIN MENU (Struct ver.) =============\n\n";
		cout << "1: Nhap danh sach tu ban phim \n";
		cout << "2: In danh sach day du \n";
		cout << "3: Sap xep danh sach \n";
		cout << "4: San pham co tong tien lon nhat \n";
		cout << "5: Them vao danh sach 1 ban ghi \n";
		cout << "6: Xoa khoi danh sach 1 ban ghi \n";
		cout << "0: Exit \n";
		cout << "\n===================================================\n";
		cout << "\nLua chon: ";
		cin >> chon;
		
		
		switch (chon)
		{
		    case 1: //Nhap(); 
            break;
		    case 2: //In();  	
            break;
            case 3: //Sap_Xep();	
            break;
		    case 4: //Tong_Max();    
            break;
		    case 5: //Them();		
            break;
		    case 6: //Xoa();	
            break;
            default: break;
		}
        
	} while(chon);


}
}
int main()
{   
    quan_ly_ho_dan qlhd[10];
// Nhap n
int n;
cout << "Nhap so phan tu n: ";
cin >> n;

for (int i = 0; i < n; i++)
{
    cout << "\n-------Nhap quan ly ho dan------\n";
    cout << "Ma ho dan: ";
    fflush(stdin);
    cin.getline(qlhd[i].ma_ho, 10);
    cout << "Ten chu ho: ";
    cin.getline(qlhd[i].ten_chu_ho, 40);
    cout<<"So thanh vien : ";
    cin>>qlhd[i].so_thanh_vien;
    cout<<"Muc thu nhap : ";
    cin>>qlhd[i].muc_thu_nhap;
    cout<<"Ho ngheo : ";
    cin>>qlhd[i].ho_ngheo;
}  
 //ho ngheo
 for (int i = 0; i < n; i++)
 {
 	bool ho_ngheo =  true ;
	cout << ho_ngheo;
 }
//tro cap
for (int i = 0; i < n; i++)
{
    if (qlhd[i].so_thanh_vien >= 5)
       qlhd[i].tro_cap=1000000 ;
    else if (qlhd[i].so_thanh_vien >= 3)
       qlhd[i].tro_cap= 800000 ;
    else if (qlhd[i].so_thanh_vien >=1 )
       qlhd[i].tro_cap = 500000 ;
    else 
        qlhd[i].tro_cap=0;

}
//Xuat bang quan ly ho dan
cout<<"\n----------Bang quan ly ho dan---------\n";
title();
for (int i = 0; i < n; i++)
{
    cout << setw(11) << left << "Ma ho dan";
    cout << setw(30) << left << "Ten chu ho";
    cout << setw(30) << right << "So thanh vien";
    cout << setw(30) << right << "Muc thu nhap";
    cout << setw(15) << right << "Ho ngheo";
    cout << setw(30) << right << "Tro cap";
    cout << endl;
}
//in ....
title();
int min=0;
for (int i = 0; i < n; i++)
{
    if(qlhd[i].muc_thu_nhap < min)
    {
        min = qlhd[i].muc_thu_nhap;
    }
    cout<<"\n\t\t\t------Bang quan ly ho dan thu nhap nho nhat -------  ";
}
cout<<endl; 
system("pause"); 
return 0;   
}
