#include <iostream>
#include <string>
using namespace std;

class People{
    protected: 
    string name;
    int age;
    string address;

    public:
    People(){
        name="";
        age=0;
        address="";
    }
    ~People(){
        name="";
        age=0;
        address="";
    }
    void set(){
        cout<<"Nhap ten: ";
        fflush(stdin);
        getline(cin,this->name);
        cout<<"Nhap tuoi: ";
        fflush(stdin);
        cin>>this->age;
        cout<<"Nhap dia chi: ";
        fflush(stdin);
        getline(cin,this->address);
    }
    void get()
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Age: "<<this->age<<endl;
        cout<<"Address: "<<this->address<<endl;
    }
};

class Student: public People{
    private:
    int id;
    float math,physical,chemistry;
    public:
    Student()
    {
        id=0;
        math=physical=chemistry=0;
    }
    ~Student()
    {
        id=0;
        math=physical=chemistry=0;
    }
    void set(){
        People ::set();
        cout<<"Nhap mssv: ";
        cin>>this->id;
        cout<<"Nhap diem toan,ly,hoa: ";
        cin>>this->math>>this->physical>>this->chemistry;
    }
    void get(){
        People:: get();
        cout<<"Mssv: "<<this->id<<endl;
        cout<<"Toan,ly,hoa: "<<this->math<<" "<<this->physical<<" "<<this->chemistry<<endl;
        cout<<"GPA: "<<GPA();
    }
    float GPA()
    {
        return (this->math+this->physical+this->chemistry)/3;
    }
};

int main()
{
    Student A;
    A.set();
    cout<<endl;
    A.get();
    return 225;
}