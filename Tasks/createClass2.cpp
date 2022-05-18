#include <iostream>
#include <string>
using namespace std;

class Color{
    protected:
    string tenMau;
    string maMau;
    public:
    Color(){
        tenMau=maMau="";
    }

    Color(string tenmau,string mamau)
    {
        this->tenMau=tenmau;
        this->maMau=mamau;
    }
    ~Color()
    {
        tenMau=maMau="";
    }

    friend istream &operator>>(istream &is, Color &obj)
    {
        cout<<"Nhap ten mau: "; 
        fflush(stdin);
        getline(is,obj.tenMau);
        cout<<"Nhap ma mau: ";
        fflush(stdin);
        getline(is,obj.maMau);
        return is;
    };
    friend ostream &operator<<(ostream &os, Color obj)
    {
       
        os<<"Ten mau: "<<obj.tenMau<<endl;
        os<<"Ma mau: "<<obj.maMau<<endl;
        return os;
    }

    string getTenMaU()
    {
        return this->tenMau;
    }

};

class Point{
    protected: 
    int x;
    int y;
    public:
    Point(){
        x=y=0;
    }
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    ~Point()
    {
        x=y=0;
    }

    friend istream &operator>>(istream &is, Point &obj)
    {
        cout<<"Nhap (x,y): ";
        is>>obj.x>>obj.y;
        return is;
    }
    friend ostream &operator<<(ostream &os,Point obj)
    {
        os<<"(x,y) : ("<<obj.x<<","<<obj.y<<")\n";
        return os;
    }

    bool CheoChinh()
    {
        return x==y?true:false;
    }
};

class Pixel: public Color,public Point{
    public:
    Pixel()
    {
        x=y=0;
        tenMau=maMau="";
    }
    Pixel(int x,int y,string tenmau,string mamau)
    {
        this->x=x;
        this->y=y;
        this->tenMau=tenMau;
        this->maMau=mamau;
    }
    ~Pixel()
    {
        x=y=0;
        tenMau=maMau="";
    }

    friend istream &operator>>(istream &is, Pixel &obj)
    {
        cout<<"Nhap toa do (x,y): ";
        is>>obj.x>>obj.y;
        cout<<"Nhap ma mau: ";
        fflush(stdin);
        is>>obj.maMau;
        cout<<"Nhap ten mau: ";
        fflush(stdin);
        is>>obj.tenMau;
        return is;
    }
    friend ostream &operator<<(ostream &os,Pixel obj)
    {
        os<<"toa do (x,y): "<<"("<<obj.x<<","<<obj.y<<")\n";
        os<<"ten mau: "<<obj.tenMau<<endl;
        os<<"ma mau: "<<obj.maMau<<endl;
        return os;
    }

    bool check()
    {
        return (x==y) && maMau=="#ccc"?true:false;
    }

};

int main()
{
    Pixel data;
    cin>>data;
    cout<<"output: \n";
    cout<<data<<endl;
    cout<<"\n hoan thanh\n";
    return 225;

}