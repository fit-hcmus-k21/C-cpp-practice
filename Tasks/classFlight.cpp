#include <iostream>
#include <string>
using namespace std;

class Flight
{
private:
        string nameF;
        string date;
        int price;
public:
        Flight()
        {
            this->nameF="";
            this->date="";
            this->price=0;
        }

        ~Flight()
        {
            this->nameF="";
            this->date="";
            this->price=0;
        }

        void set()
        {
            cout<<"Nhap ten chuyen bay: ";
            fflush(stdin);
            getline(cin,this->nameF);
            cout<<"Nhap ngay bay: ";
            fflush(stdin);
            getline(cin,this->date);
            cout<<"Nhap gia: ";
            cin>>this->price;
        }

        void get()
        {
            cout<<"Ten chuyen bay: "<<this->nameF<<endl;
            cout<<"Ngay bay: "<<this->date<<endl;
            cout<<"Gia ve: "<<this->price<<endl;
        }

        int getPrice()
        {
            return this->price;
        }
};

class People
{
protected: 
        string name;
        string sex;
        int age;
public:
        People()
        {
            this->name="";
            this->sex="";
            this->age=0;
        }
        
        ~People()
        {
            this->name="";
            this->sex="";
            this->age=0;
        }

        void set()
        {
            cout<<"Nhap ten: ";
            fflush(stdin);
            getline(cin,this->name);
            cout<<"Nhap gioi tinh: ";
            fflush(stdin);
            getline(cin,this->sex);
            cout<<"Nhap tuoi: ";
            cin>>this->age;
        }

        void get()
        {
            cout<<"Ten: "<<this->name<<endl;
            cout<<"Gioi tinh: "<<this->sex<<endl;
            cout<<"Tuoi: "<<this->age<<endl;
        }
};

class HanhKhach: public People
{
private: 
        Flight *ve;
        int sl;
        int tongTien;
public:
        HanhKhach()
        {
            this->name="";
            this->sex="";
            this->age=0;
            this->sl=0;
            this->ve=NULL;
            this->tongTien=0;
        }
        
        ~HanhKhach()
        {
            this->name="";
            this->sex="";
            this->age=0;
            this->sl=0;
            this->ve=NULL;
            this->tongTien=0;
        }

        void set()
        {
            People:: set();
            cout<<"Nhap so luong ve da mua: ";
            cin>>this->sl;
            ve=new Flight[this->sl];
            for (int i=0;i<this->sl;i++)
            {
                ve[i].set();
                this->tongTien+=ve[i].getPrice();
            }
        }

        void get()
        {
            cout<<"Thong Tin khach hang:\n";
            People::get();
            cout<<"Thong tin chuyen bay: \n";
            for(int i=0;i<this->sl;i++)
            {
                ve[i].get();
                cout<<endl;
            }
            cout<<"Tong tien: "<<this->tongTien<<endl;
            cout<<endl;
        }

      bool operator < (HanhKhach obj)
      {
          if (this->tongTien<obj.tongTien)
          {
              return true;
          }
          return false;
      }

};

void swap(HanhKhach &hk1,HanhKhach &hk2)
{
    HanhKhach temp=hk1;
    hk1=hk2;
    hk2=temp;
}

void sapXep(HanhKhach *hk,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (hk[i]<hk[j])
            {
                swap(hk[i],hk[2]);
            }
        }
    }
}

int main()
{
    cout<<"Nhap so luong khach hang: ";
    int n;
    cin>>n;
    HanhKhach *arr=new HanhKhach[n];
    for (int i=0;i<n;i++)
    {
        arr[i].set();
    }
    cout<<"\n\nOUTPUT:\n";
    for (int i=0;i<n;i++)
    {
        arr[i].get();
    }

    sapXep(arr,n);
    cout<<"Sau khi sap xep: \n";
    for (int i=0;i<n;i++)
    {
        arr[i].get();
    }
    cout<<"\nHoan thanh...\n";
    return 225;
}