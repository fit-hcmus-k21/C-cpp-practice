#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;
struct hocsinh
{
	int MaHS;
	char TenHS[100];
	float Diemtoan, Diemly, Diemhoa;
	float DiemTB;
	char hocluc[100]; 
};
void nhap(hocsinh hs[], int n)
{
	for (int i=0; i<n; i++){
		cout<<"hoc sinh thu"<<i+1<<endl;
		cout<<"nhap ma hoc sinh"<<endl;
		cin>>hs[i].MaHS;
		cout<<"nhap ten hoc sinh"<<endl;
		cin>>hs[i].TenHS;
		cout<<"nhap diem toan"<<endl;
		cin>>hs[i].Diemtoan;
		cout<<"nhap diem ly"<<endl;
		cin>>hs[i].Diemly;
		cout<<"nhap diem hoa"<<endl;
		cin>>hs[i].Diemhoa;
	}
}

void diemTB(hocsinh hs[],int n)
{
	for (int i=0; i<n; i++){
		hs[i].DiemTB=(hs[i].Diemtoan+hs[i].Diemly+hs[i].Diemhoa)/3;
	}
}
void xuatDTB(hocsinh hs[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<"DTB hoc sinh thu "<<hs[i].MaHS<<" : "<<hs[i].DiemTB<<endl;
	}
}
void xeploai(hocsinh hs[], int n)
{
	for (int i=0; i<n; i++){
		if (hs[i].DiemTB>=9){
			strcpy(hs[i].hocluc,"Xuat Sac");
		}
		else if (hs[i].DiemTB>=8){
			strcpy(hs[i].hocluc,"Gioi");
		}
		else if (hs[i].DiemTB>=7){
			strcpy(hs[i].hocluc,"Kha");
		}
		else if (hs[i].DiemTB>=5){
			strcpy(hs[i].hocluc,"Trung Binh");
		}
		else {
			strcpy(hs[i].hocluc,"Yeu");
		}
	}
}
void sapxep(hocsinh hs[], int n)
{
	float giamdan;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (hs[i].DiemTB<hs[j].DiemTB){
			    giamdan=hs[i].DiemTB;
				hs[i].DiemTB=hs[j].DiemTB;
				hs[j].DiemTB=giamdan;
			}
		}
	}
}
void xuat(hocsinh hs[], int n)
{

	cout<<"\nSTT\tMa HS\tTen HS\tToan\tLy\tHoa\tDiem TB\tHoc luc";
	for (int i=0; i<n; i++){
		cout<<"\n"<<i+1;
		cout<<"\t"<<hs[i].MaHS;
		cout<<"\t"<<hs[i].TenHS;
		cout<<"\t"<<hs[i].Diemtoan;
		cout<<"\t"<<hs[i].Diemly;
		cout<<"\t"<<hs[i].Diemhoa;
		cout<<"\t"<<hs[i].DiemTB;
		cout<<"\t"<<hs[i].hocluc;
		cout<<endl;
	}
}
void diemhoamax(hocsinh hs[], int n)
{
	int max=0;
	for (int i=0; i<n; i++)
		if (max<hs[i].Diemhoa)
		max=hs[i].Diemhoa;

}
void menu(hocsinh hs[], int n)
{
	cout<<"----------MENU----------"<<endl;
	cout<<"1. Nhap vao tu ban phim mot danh sach cac hoc sinh"<<endl;
	cout<<"2. Tinh diem trung binh cho cac hoc sinh"<<endl;
	cout<<"3. In ra man hinh danh sach hoc sinh voi day du thong tin duoi dang bang "<<endl;
	cout<<"4. Sap xep danh sach hoc sinh theo thu tu giam dan cua diem trung binh va in ra danh sach sau sap xep"<<endl;
	cout<<"5. In ra man hinh danh sach cac hoc sinh co diem hoa lon nhat"<<endl;
	cout<<"6. Them vao danh sach hoc sinh voi thong tin nhap vao ban phim, sao cho van dam bao thu tu sap xep"<<endl;
	cout<<"7. Xoa khoi danh sach cac hoc sinh co diem ly"<<endl;
	cout<<"8. Luu danh sach hoc sinh ra tep sv1.dat"<<endl;
	cout<<"9. Doc danh sach hoc sinh tu tep sv1.dat va in danh sach ra man hinh"<<endl;
	int x;
	nhaplai:
	
	cout<<"nhap lua chon"<<endl; cin>>x;
	switch(x){
		case 1:
		nhap(hs, n);
		break;
		case 2:
	    diemTB(hs,n);
		break;
		case 3:
		cout<<"in danh sach";
		diemTB(hs,n);
		xeploai(hs,n);
		xuat(hs,n);
		break;
		case 4:
		cout<<"danh sach giam dan la: "<<endl;
		sapxep(hs,n);
		xuat(hs,n);
		break;
		case 5:
		cout<<"cac hoc sinh co diem hoa lon nhat"<<endl;
		diemhoamax(hs,n);
		break;
		
		
		
		
	}
}
int main ()
{
	int n;
	cout<<"nhap n hoc sinh"<<endl;
	cin>>n;
	hocsinh hs[100];
	nhap(hs,n);
	menu(hs,n);
}