#include <iostream>
using namespace std;

int main()
{
    int n;
    int *p=NULL;
    cout<<"Nhap so phan tu n: ";
    cin>>n;
    p=new int[n];
    cout<<"Nhap mang cac phan tu: ";
    for (int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    p=(int *) realloc(p,2*n*sizeof(int));
    for (int i=n-1;i>=0;i--)
    {
        p[2*i+1]=p[i];
    }
    for (int i=0;i<2*n;i+=2)
    {
        p[i]=p[i+1];
    }
    cout<<"-----output-----\n";
    for (int i=0;i<2*n;i++)
    {
        cout<<p[i]<<" ";
    }
    delete[] p;
    cout<<"\nHoan thanh...\n";
    return 225;

}