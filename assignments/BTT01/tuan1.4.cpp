#include <iostream>;
using namespace std;

/*baitap4*/

int main()
{
	int hst,hsl,hsh;
	float dt,dl,dh,dtb;
	cout<<"nhap diem toan:"; 
	cin>>dt;
	cout<<"nhap diem ly:";
	cin>>dl;
	cout<<"nhap diem hoa:";
	cin>>dh;
	cout<<"nhap he so toan:";
	cin>>hst;
	cout<<"nhap he so ly:";
	cin>>hsl;
	cout<<"nhap he so hoa:";
	cin>>hsh;
	dtb=(dt*hst+dl*hsl+dh*hsh)/(hst+hsl+hsh);
	cout<<"diem trung binh la:"<<dtb;
	return 0;
	
}
