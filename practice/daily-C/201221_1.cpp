#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#define MAX 100
using namespace std;

struct quan_ly_ho_dan
{
    char ma_ho[MAX];
    char ten_chu_ho[MAX];
    int so_thanh_vien;
    float muc_thu_nhap;
    bool ho_ngheo;
    char _ho_ngheo_;
    float tro_cap;
};

void nhap(quan_ly_ho_dan ho[],int &n)
{
    cout<<"Nhap so ho dan n : ";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Nhap thong tin ho thu "<<i+1<<" :"<<endl;
        cout<<"Ma ho :";
        cin.ignore()>>ho[i].ma_ho;
       

        cout<<"Ten chu ho :";
        cin.ignore()>>ho[i].ten_chu_ho;
        
        cout<<"So thanh vien :";
        cin>>ho[i].so_thanh_vien;
        cout<<"Muc thu nhap:";
        cin>>ho[i].muc_thu_nhap;
        cout<<"Ho ngheo ? (1:true  0:false) : ";
        cin>>ho[i].ho_ngheo;
        cout<<"---------------------"<<endl;
    }

}



void tro_cap(quan_ly_ho_dan ho[],int n)
{
    for (int i=0;i<n;i++)
    {
        if (ho[i].ho_ngheo && ho[i].so_thanh_vien>=5)
        {
            ho[i].tro_cap=1000000;
        }

        if (ho[i].ho_ngheo && ho[i].so_thanh_vien>=3 && ho[i].so_thanh_vien<5)
        {
            ho[i].tro_cap==800000;
        }

        if (ho[i].ho_ngheo && ho[i].so_thanh_vien>=1 && ho[i].so_thanh_vien<3)
        {
            ho[i].tro_cap=500000;
        }

        if (!ho[i].ho_ngheo)
        {
            ho[i].tro_cap==0;
        }
    }
}

void in_danh_sach(quan_ly_ho_dan ho[],int n)
{
    cout<<"Ma ho\tTen chu ho\tSo thanh vien\tMuc thu nhap\tHo ngheo\tTro cap"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<"\n"<<ho[i].ma_ho;
        cout<<"\t"<<ho[i].ten_chu_ho;
        cout<<"\t\t"<<ho[i].so_thanh_vien;
        cout<<"\t\t"<<ho[i].muc_thu_nhap;
        cout<<"\t\t";
        if (ho[i].ho_ngheo)
        {
            cout<<"True";
        }
        else
        {
            cout<<"False";
        }
        cout<<"\t\t"<<ho[i].tro_cap<<"/nguoi";
        cout<<endl;
    }
}

void hoan_doi(quan_ly_ho_dan *a,quan_ly_ho_dan *b)
{
    quan_ly_ho_dan temp=*a;
    *a=*b;
    *b=temp;
}

void sap_xep_tv(quan_ly_ho_dan ho[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (ho[i].so_thanh_vien<ho[j].so_thanh_vien)
            {
                hoan_doi(&ho[i],&ho[j]);
            }
        }
    }
}

void nhap_them(quan_ly_ho_dan ho[],int &n)
{
    cout<<"Nhap thong tin ho thu "<<n<<" :"<<endl;
        cout<<"Ma ho :";
        cin.ignore()>>ho[n].ma_ho;
       

        cout<<"Ten chu ho :";
        cin.ignore()>>ho[n].ten_chu_ho;
        
        cout<<"So thanh vien :";
        cin>>ho[n].so_thanh_vien;
        cout<<"Muc thu nhap:";
        cin>>ho[n].muc_thu_nhap;
        cout<<"Ho ngheo ? (1:true  0:false) : ";
        cin>>ho[n].ho_ngheo;
        cout<<"---------------------"<<endl;
        n++;

}

void xoa_ho(quan_ly_ho_dan ho[],int n)
{
    char ten[MAX];
    cout<<"Nhap ten chu ho muon xoa :";
    cin.ignore()>>ten;
    for (int i=0;i<n;i++)
    {
        if (strncmp(ho[i].ten_chu_ho,ten,strlen(ten)-1)==0)
        {
            memmove(ho+i-1,ho+i+1,n-i-1);
        }
    }
}

void menu(quan_ly_ho_dan ho[],int n)
{
    cout<<"---------------MENU--------------"<<endl;
    cout<<"1.Nhap thong tin cac ho dan tu ban phim."<<endl;
    cout<<"2.Tinh tro cap cho cac ho."<<endl;
    cout<<"3.In danh sach thong tin cac ho dan day du."<<endl;
    cout<<"4.In thong tin cac ho dan thu nhap nho nhat."<<endl;
    cout<<"5.Sap xep cac ho dan theo thu tu giam dan so thanh vien."<<endl;
    cout<<"6.Them vao danh sach mot ho dan co thong tin duoc nhap tu ban phim."<<endl;
    cout<<"7.Xoa khoi danh sach ho dan co ten nhap tu ban phim."<<endl;
    cout<<"8.Luu danh sach cac ho dan ra tep ho_dan.dat"<<endl;
    cout<<"9.Doc thong tin tu tep ho_dan.dat va in ra man hinh."<<endl;
    cout<<"0.Ket thuc."<<endl;
    cout<<"-------------------------------"<<endl;
    int chon;
    do
    {
    
            cout<<"Moi ban chon :";
            
            cin>>chon;
            switch(chon)
            {
                case 1:
                    nhap(ho,n);
                    break;
                case 2:
                    tro_cap(ho,n);
                    break;
                case 3:
                    in_danh_sach(ho,n);
                    break;
                case 4:
                    
                case 5:
                    sap_xep_tv(ho,n);
                    in_danh_sach(ho,n);
                    break;
                case 6:
                    nhap_them(ho,n);
                    in_danh_sach(ho,n);
                    break;
                case 7:
                    xoa_ho(ho,n);
                    in_danh_sach(ho,n);
                    break;
                case 8:
                case 9:
                default : 
                    break;
            }
    } while (chon);

}

int main()
{
    int n;
    quan_ly_ho_dan ho[MAX];
    menu(ho,n);
    return 22;
}