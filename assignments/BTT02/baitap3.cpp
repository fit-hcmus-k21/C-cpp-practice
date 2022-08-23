#include <stdio.h>
using namespace std;

//baitap3


int main()
{
	char kitu;
	printf("nhap ki tu :");
	scanf("%c",&kitu);
	if (kitu>='a' && kitu<='z') kitu=kitu-32;
	else kitu=kitu+32;
	printf("ki tu sau khi chuyen la: %c",kitu);
	return 0;
}
