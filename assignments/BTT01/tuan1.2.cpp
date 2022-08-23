#include <iostream>;
using namespace std;

/*baitap2*/

int main()
{
	int sl, DG;
	cout<<"nhap so luong:";
	cin>>sl;
	cout<<"nhap don gia:";
	cin>>DG;
	int tongtien,thue;
	tongtien=sl*DG;
	thue=tongtien*10/100;
	cout<<"tong tien la:"<<tongtien<<endl;
	cout<<"tien thue la:"<<thue;
	return 0;
}
