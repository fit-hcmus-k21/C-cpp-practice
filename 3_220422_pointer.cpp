//  Viết chương trình sử dụng con trỏ
//      Nhập mảng số nguyên của N phần tử
//      Tạo mảng mới gồm các số nguyên tố từ mảng đã cho 
//      Sắp xếp mảng số nguyên tố theo thứ tự tăng dần hoặc giảm dần (con trỏ hàm)
//      Xuất mảng số nguyên tố ra màn hình

#include <iostream>
using namespace std;

bool snt(int a)
{
    if (a<=1)
    {
        return 0;
    }
    for (int i=2;i<=a/2;i++)
    {
        if (a%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void increase(int *a,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

void decrease(int *a,int sl)
{
    for (int i=0;i<sl-1;i++)
    {
        for (int j=i+1;j<sl;j++)
        {
            if (a[i]<a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

void xuat(int *a,int sl)
{
    for (int i=0;i<sl;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int *a=NULL;
    int n;
    cout<<"Nhap so phan tu n: ";
    cin>>n;
    a=new int[n];
    //  Nhập mảng số nguyên n phần tử
    cout<<"Nhap mang so nguyen "<<n<<" phan tu: \n";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //  Tạo mảng mới gồm các số nguyên tố từ mảng đã cho
    int *b=NULL;
    int sl=0;
    for (int i=0;i<n;i++)
    {
        if (snt(a[i]))
        {
            sl++;
            b=(int *) realloc(b,sl*sizeof(int));
            b[sl-1]=a[i];
        }
    }
    //  Sắp xếp mảng số nguyên tố theo tăng dần hoặc giảm dần (con trỏ hàm)
    void (*ptr) (int*,int) =NULL;
    ptr=increase;
    ptr(b,sl);
    xuat(b,sl);
    cout<<endl;
    ptr=decrease;
    ptr(b,sl);
    xuat(b,sl);

    //  Giải phóng bộ nhớ 
    delete[] a;
    delete[] b;
    
    cout<<"-------------------\n";
    cout<<"Hoan thanh...\n";
    return 225;
}