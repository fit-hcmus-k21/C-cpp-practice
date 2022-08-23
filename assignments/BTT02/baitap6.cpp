#include <stdio.h>
using namespace std;

//baitap6

int main()
{
	double tongtien;
	float S;  	//S la so km;
	printf("nhap so km da di:");
	scanf("%f",&S);
	if (S<0) return main();
	if (S<=1) tongtien=S*22000;
	if (S>1 && S<=5) tongtien=S*20000;
	if (S>5 && S<=120) tongtien=S*18000;
	if (S>120) tongtien=S*18000*0.9;
	printf("so tien phai tra la: %fl",tongtien);
	return 0;
}
