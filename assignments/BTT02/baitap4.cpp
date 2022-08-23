#include <stdio.h>
using namespace std;

//baitap4

int main()
{
	int a,b,c,d;
	printf("nhap 4 so :");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	int min,max;
	min=a;
	max=a;
	if (max<b) max=b;
	if (max<c) max=c;
	if (max<d) max=d;
	if (min>b) min=b;
	if (min>c) min=c;
	if (min>d) min=d;
	printf("gia tri nho nhat la: %d",min);
	printf("\ngia tri lon nhat la: %d",max);
	return 0; 
}
