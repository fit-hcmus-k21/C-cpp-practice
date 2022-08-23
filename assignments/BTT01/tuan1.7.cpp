#include <iostream>;
using namespace std;

/*baitap7*/

int main()
{
	float bien1,bien2,tam;
	cout<<"nhap bien 1:";
	cin>>bien1;
	cout<<"nhap bien 2:";
	cin>>bien2;
	tam=bien1;
	bien1=bien2;
	bien2=tam;
	cout<<"gia tri cua bien 1 la:"<<bien1<<endl;
	cout<<"gia tri cua bien 2 la:"<<bien2;
	return 0;

}
