#include<iostream>
#include<math.h>
using namespace std; 

void nhap(int A[], int &n);
void xuat(int kq);
int timSCPMax(int A[], int n);
int timMax(int a, int b);
bool kiemtraSCP(int x);
int main()
{
	int A[100],n;
	nhap(A,n);
	int kq=timSCPMax(A,n);
	xuat(kq);
	return 0;
}
int timSCPMax(int A[], int n)
{
	int max=-1;
	for(int i=0; i<n; i++)
		if(kiemtraSCP(A[i]))
			max=timMax(A[i],max);
	return max;
}
int timMax(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
bool kiemtraSCP(int x)
{
	for(int i=0; i<=sqrt(x); i++)
		if(i*i==x)
			return true;
	return false;
}

void nhap(int A[], int &n)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>A[i];
}
void xuat(int kq)
{
	cout<<kq;
}