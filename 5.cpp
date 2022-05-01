//  Doc file nhi phan output1.txt

#include <iostream>
#include <fstream>
using namespace std;

void xuat(int **a,int x,int y)
{
    cout<<"\nXuat mang: \n";
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    ifstream fin("output1.txt",ios::binary);
    int **p=nullptr;

    //  Cấp phát mảng động
    p=new int*[5];
    for (int i=0;i<5;i++)
    {
        p[i]=new int[3];
    }
    for (int i=0;i<5;i++)
    {
        fin.read((char*)p[i],3*sizeof(int));
        fin.seekg(1,ios::cur);
    }
    xuat(p,5,3);

    //  Giải phóng bộ nhớ

    for (int i=0;i<5;i++)
    {
        delete[] p[i];
    }

    fin.close();
    cout<<"Hoan thanh...\n";
    return 225;
}