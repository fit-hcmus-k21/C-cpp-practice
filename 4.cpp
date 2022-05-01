//  Đọc/ghi file nhi phan

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
                        //      Đọc file số/ mảng

    ifstream fin("input1.txt",ios::in);     //  File đọc dữ liệu
    ofstream fout("output1.txt",ios::out|ios::binary);  //  File ghi dữ liệu
    if (!fin.is_open()||!fout.is_open())
    {
        cout<<"\nMo file that bai...\n";
    }
    int x,y;
    int **p=nullptr;
    fin>>x>>y;

    //  Cấp phát mảng động
    p=new int*[x];
    for (int i=0;i<x;i++)
    {
        p[i]=new int[y];
    }
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            fin>>p[i][j];
        }
    }
    xuat(p,x,y);
    //  xóa bớt 2 cột rồi ghi ra file output1.txt
    for (int i=0;i<x;i++)
    {
        p[i]=(int *) realloc(p[i],(y-2)*sizeof(int));
    }
    y=y-2;
    xuat(p,x,y);

    //  Ghi file
    for (int i=0;i<x;i++)
    {
        fout.write((char*)p[i],y*sizeof(int));
        fout.write("\n",1);
    }


    //  Giải phóng bộ nhớ

    for (int i=0;i<x;i++)
    {
        delete[] p[i];
    }

                        
    
                        //  Dong file

    
    fin.close();
    fout.close();
    cout<<"\nHoan thanh...\n";
    return 225;
}