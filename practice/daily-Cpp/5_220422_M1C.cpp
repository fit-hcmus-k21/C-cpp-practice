//  Cài đặt các hàm xử lý trên mảng động 1 chiều các số nguyên tương tự cấu trúc vector trong thư viện std
//      Tạo mảng động a gồm n số nguyên
//      Giải phóng vùng nhớ cho mảng động a
//      Nhập/xuất mảng động a gồm n số nguyên
//      Lấy phần tử tại vị trí index của mảng động a
//      Thêm 1 phần tử x vào trước/ sau mảng a
//      Xóa phần tử tại vị trí index của mảng a

#include <iostream>
using namespace std;

void taoMang(int *&a,int &sl)
{
    cout<<"---Tao mang dong gom n so nguyen---\n";
    cout<<"Nhap so phan tu n: ";
    cin>>sl;
    a=new int[sl];
}

void xuat(int *a,int sl)
{
    cout<<"\nXuat mang: \n";
    for (int i=0;i<sl;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void GiaiPhong(int *&a)
{
    cout<<"---Giai phong vung nho---\n";
    delete[] a;
}

void Nhap(int *&a, int sl)
{
    cout<<"---Nhap mang---\n";
    for (int i=0;i<sl;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
}

void Index(int *a,int index)
{
    cout<<"Lay phan tu tai vi tri "<<index<<" : "<<a[index-1];
    cout<<endl;
}

void add(int *&a,int &sl)
{
    //  Thêm 1 phần tử vào trước /sau mảng A
    sl++;
    a=(int *) realloc(a,(sl)*sizeof(a));
    cout<<"--Them phan tu vao truoc mang A--\n";
    int so;
    cout<<"Nhap so muon them: ";
    cin>>so;
    for (int i=sl;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=so;
    xuat(a,sl);

    //  Thêm 1 phần tử vào sau mảng A
    sl++;
    a=(int *) realloc(a,(sl)*sizeof(int));
    cout<<"--Them phan tu vao sau mang A--\n";
    int pt;
    cout<<"Nhap so muon them: ";
    cin>>pt;
    a[sl-1]=pt;
    xuat(a,sl);
}

void del(int *&a,int &sl)
{
    //  Xoa phan tu tai vi tri index
    int index;
    cout<<"vi tri cua phan tu muon xoa: ";
    cin>>index;
    for (int i=index-1;i<sl-1;i++)
    {
        a[i]=a[i+1];
    }
    sl--;
    a=(int*) realloc(a,(sl)*sizeof(int));
    cout<<"--Xuat mang sau khi xoa phan tu --\n";
    xuat(a,sl);
}

int main()
{
    int *a=nullptr;
    int sl;

    taoMang(a,sl);
    Nhap(a,sl);
    xuat(a,sl);
    Index(a,5);
    add(a,sl);
    del(a,sl);
    GiaiPhong(a);
    cout<<"\nHoan thanh...\n";
    return 225;

}