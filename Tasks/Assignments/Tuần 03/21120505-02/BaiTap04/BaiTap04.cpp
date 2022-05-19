#include <iostream>
#include <stdlib.h>
using namespace std;

int cmp_inc(const void *a, const void *b)
{
    int *x=(int*) a;
    int *y=(int*) b;
    return (*x>*y)? 1:-1;
}

int cmp_des(const void *a,const void *b)
{
    int *x=(int *) a;
    int *y=(int *) b;
    return (*x>*y)?-1:1;
}

int main()
{
    int n;
    cout<<"Nhap so luong so nguyen: ";
    cin>>n;
    int *X=new int[n];
    for (int i=0;i<n;i++)
    {
        cin>>X[i];
    }
    int Luachon;
    do 
    {
        cout<<"-------------------------"<<endl;
        cout<<"0. Ket thuc"<<endl;
        cout<<"1. Sap xep theo tang dan"<<endl;
        cout<<"2. Sap xep theo giam dan"<<endl;
        cout<<"Moi ban lua chon... ";
        cin>>Luachon;
        switch(Luachon)
    {
        case 1:
            qsort(X,n,sizeof(int),cmp_inc);
            for (int i=0;i<n;i++)
            {
                cout<<X[i]<<" ";
            }
            cout<<endl;
            break;
        case 2:
            qsort(X,n,sizeof(int),cmp_des);
            for (int i=0;i<n;i++)
            {
                cout<<X[i]<<" ";
            }
            cout<<endl;
            break;
        default: 
            break;
    }
    }
    while(Luachon!=0);

    delete[] X;
    cout<<endl<<"Hoan thanh..."<<endl;;
    return 225;
}