#include <iostream>;
using namespace std;

int main()
{
	char kitu;
	cout<<"nhap ki tu :";
	cin>>kitu;
	if (kitu>='a' && kitu<='z') kitu=kitu-32;
	else
	kitu=kitu+32;
	cout<<"ki tu sau khi chuyen la:"<<kitu;
	return 0;
}
