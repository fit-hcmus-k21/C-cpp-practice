#include <iostream>;
using namespace std;

/*baitap8*/

int main()
{
	int bsx,N,T,C,Dv,sonut;
	cout<<"nhap so bien so xe:";
	cin>>bsx;
	Dv=bsx%10;
	C=(bsx/10)%10;
	T=(bsx/100)%10;
	N=bsx/1000;
	sonut=(N+T+C+Dv)%10;
	cout<<"so nut la:"<<sonut;
	return 0;
}
