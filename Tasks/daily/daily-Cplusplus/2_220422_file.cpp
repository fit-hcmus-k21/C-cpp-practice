//  Viết hàm nhập mảng N phân số
//  Sắp xếp mảng tăng dần
//  Ghi N phân số đã sắp xếp xuống file nhị phân

//  Viết hàm đọc file văn bản input, sau đó xuất file văn bản output 
//  ...với mỗi dòng trong file output ghi số lượng từ xuất hiện trên dòng tương ứng của file input 

#include <iostream>
#include <fstream>
using namespace std;

typedef struct 
{
    int tuso;
    int mauso;
} PHANSO;

//  Hàm nhập mảng N phân số

void nhap(PHANSO *&a,int &sl)
{
    cout<<"\n-----Ham nhap mang n phan so----\n";
    cout<<"Nhap so luong n: ";
    cin>>sl;
    cout<<"Nhap mang cac phan so (tu:mau): ";
    a=new PHANSO[sl];
    for (int i=0;i<sl;i++)
    {
        cin>>a[i].tuso;
        cin>>a[i].mauso;
    }
}

void swap(PHANSO *x,PHANSO *y)
{
    PHANSO t=*x;
    *x=*y;
    *y=t;
}

//  Sắp xếp mảng tăng dần

void sapxep(PHANSO *a,int sl)
{
    cout<<"\n----Sap xep mang tang dan----\n";
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (1.0*a[i].tuso/a[i].mauso>1.0*a[j].tuso/a[j].mauso)
            {
                swap(a+i,a+j);
            }
        }
    }
}

//  Ghi n phan so da sap xep xuong file nhi phan

void GhiFile(char *filename,PHANSO *a,int sl)
{
    ofstream file(filename, ios::out | ios:: binary);
    if (file.is_open())
    {
        cout<<"\nMo file thanh cong\n";
    }

    file.write((char*) a,sl*sizeof(*a));
    cout<<"\nGhi file xong...\n";

    file.close();
}

//  Viết hàm đọc file văn bản input, sau đó xuất file văn bản output với mỗi dòng trong file output ghi số lượng từ xuất hiện trên dòng tương ứng của file input 

void DocFile(char *inp,char *outp)
{
    ofstream file_w(outp,ios::out);
    ifstream file_r(inp,ios::in);
    if (!file_r.is_open()|| !file_w.is_open())
    {
        cout<<"/nMo file that bai\n";
    }
    char c;
    int d=0;
    while (file_r.get(c))
    {
        d++;
        if (c=='\n')
        {
            file_w<<" : "<<d<<endl;
            d=0;
        }
        file_w.put(c);

    }


}


int main()
{

}