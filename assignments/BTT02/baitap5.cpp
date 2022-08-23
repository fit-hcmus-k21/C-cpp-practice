#include <stdio.h>
using namespace std;

/*bai5*/

int main()
{
	int a,b,c,d;
	printf("enter 4 numbers:");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	int min,max;
	/*tim min,max:*/
	min=a;
	max=a;
	if (max<b) max=b;
	if (max<c) max=c;
	if (max<d) max=d;
	if (min>b) min=b;
	if (min>c) min=c;
	if (min>d) min=d;
	/*tim so thu hai va thu ba:*/
	int s2,s3;
	if (a!=min && a!=max) s2=a;
	if (b!=min && b!=max) s2=b;
	if (c!=min && c!=max) s2=c;
	if (d!=min && d!=max) s2=d;
	if (a!=min && a!=max && a!=s2) s3=a;
	if (b!=min && b!=max && b!=s2) s3=b;
	if (c!=min && c!=max && c!=s2) s3=c;
	if (d!=min && d!=max && d!=s2) s3=d;
	
	int tam;
	if (s2>s3) 
	{
		tam=s2;
		s2=s3;
		s3=tam;
	}
	/*sap xep:*/
	printf("sap xep theo thu tu tang dan: %d %d %d %d",min,s2,s3,max);
	return 0;
	

	
}
