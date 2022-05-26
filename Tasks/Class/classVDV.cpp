#include <iostream>
#include <string>
using namespace std;

class VDV
{
private:
        string name;
        int age;
        string sub;
        float weight;
        float height;
public:
        VDV()
        {
            name="";
            age=0;
            sub="";
            weight=0;
            height=0;
        }
    
        ~VDV()
        {
            name="";
            age=0;
            sub="";
            weight=0;
            height=0;
        }

        VDV(string ten,int tuoi,string mon,float canNang,float chieuCao)
        {
            this->name=ten;
            this->age=tuoi;
            this->sub=mon;
            this->height=chieuCao;
            this->weight=canNang;
        }

        friend istream &operator>>(istream &is, VDV &obj)
        {
            cout<<"Nhap ten: ";
            fflush(stdin);
            getline(is,obj.name);
            cout<<"Nhap tuoi: ";
            fflush(stdin);
            is>>obj.age;
            cout<<"Nhap mon thi dau: ";
            fflush(stdin);
            getline(is,obj.sub);
            cout<<"Nhap chieu cao, can nang: ";
            is>>obj.height>>obj.weight;
        }

        friend ostream &operator<<(ostream &os,VDV obj)
        {
            os<<"Ten: "<<obj.name<<endl;
            os<<"Tuoi: "<<obj.age<<endl;
            os<<"Mon thi dau: "<<obj.sub<<endl;
            os<<"Chieu cao: "<<obj.height<<endl;
            os<<"Can nang: "<<obj.weight<<endl;
        }
        bool operator > (const VDV obj)
        {
            if (this->height>obj.height)
            {
                return true;
            }
            if (this->height==obj.height && this->weight>obj.weight)
            {
                return true;
            }
            return false;
        }
    
};

void swap(VDV &obj1,VDV &obj2)
{
    VDV temp=obj1;
    obj1=obj2;
    obj2=temp;
}

void sapxep(VDV *&q,int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (q[i]>q[j])
                swap(q[i],q[j]);
        }
    }
}


int main()
{
    VDV p("Thanh Ngan",19,"Code",1.58,45);
    cout<<p;
    int n;
    cout<<"Nhap so luong n: ";
    cin>>n;
    VDV *q=new VDV[n];
    for (int i=0;i<n;i++)
    {
        cin>>q[i];

    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<q[i]<<endl;
    }
    sapxep(q,n);
    for (int i=0;i<n;i++)
    {
        cout<<q[i]<<endl;
    }
    delete q;
    cout<<"\nhoan thanh...\n";
    return 225;
}