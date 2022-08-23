#include <stdio.h>
#include <math.h>
using namespace std;

//baitap 2: 


int main()
{
	float a;
	float b;
	float c;
	float x, x1, x2;
	float delta;
	printf("nhap he so a:");
	scanf("%f",&a);
	printf("nhap he so b:");
	scanf("%f",&b);
	printf("nhap he so c:");
	scanf("%f",&c);
	if (a==0 && b==0) 
	{
		if (c==0) printf("vo so nghiem");
		if (c!=0) printf("vo nghiem");
	}
	if (a==0 && b!=0) 
	{
		x=-c/b;
		printf(" nghiem x=%f",x);
	}
	if (a!=0) 
	{
		delta=(b*b-4*a*c);
		if (delta <0) printf(" vo nghiem");
		if (delta==0) 
		{
			x=-b/(2*a);
			printf(" co nghiem kep x1=x2=%f",x);
		}
		if (delta >0)
		{
			x1=(-b-sqrt(delta))/(2*a);
			x2=(-b+sqrt(delta))/(2*a);
			printf("co hai nghiem phan biet\n");
			printf("x1=%f\n",x1);
			printf("x2=%f",x2);
		}
	}
	return 0;
		
}
