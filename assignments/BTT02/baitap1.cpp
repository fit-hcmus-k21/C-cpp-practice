#include <stdio.h>
using namespace std;

//bai1: gpt ã+b=0

int main()
{
	float a;
	float b;
	float x;
	printf("nhap he so a:");
	scanf("%d",&a);
	printf("nhap he so b:");
	scanf("%d",&b);
	if (a==0 && b==0) printf("vo so nghiem");
	if (a==0 && b!=0) printf("vo nghiem");
	if (a!=0) 
	{
		 x=-b/a;
		printf("nghiem x= %f",x);
	}
	return 0;	
			
}
