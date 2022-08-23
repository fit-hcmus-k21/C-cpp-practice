#include <iostream>;
using namespace std;

/*baitap9*/

int main()
{
	int tongtien,T500,T100,T1;
	cout<<"nhap vao tong tien ban co:";
	cin>>tongtien;
	T500=tongtien/500000;
	T100=(tongtien-T500*500000)/100000;
	T1=(tongtien-T500*500000-T100*100000)/1000;
	cout<<"so to 500k doi duoc la:"<<T500<<endl;
	cout<<"so to 100k doi duoc la:"<<T100<<endl;
	cout<<"so to 1k doi duoc la:"<<T1;
	return 0;
}
