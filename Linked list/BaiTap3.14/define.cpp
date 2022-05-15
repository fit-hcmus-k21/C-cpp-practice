#include "lib.h"

//  Hàm nhập thông tin từng quyển sách cho cửa hàng sách
void input(STORE *&list)
{
    //  Nhập thông tin sách
    STORE *temp=new STORE;
    cout<<"Title: ";
    fflush(stdin);
    gets(temp->book.title);
    cout<<"ISBN: ";
    fflush(stdin);
    gets(temp->book.isbn);
    cout<<"Author: ";
    fflush(stdin);
    gets(temp->book.author);
    cout<<"Language: ";
    fflush(stdin);
    gets(temp->book.language);
    cout<<"Year published: ";
    cin>>temp->book.yearPubl;
    cout<<"Price: ";
    cin>>temp->book.price;
    cout<<"Stock level: ";
    cin>>temp->book.stockLevel;

    //  Xử lí 
    if (list==NULL)
    {
        list=temp;
        list->bookNext=NULL;
    }
    else
    {
        STORE *p=list;
        while (p->bookNext!=NULL)
        {
            p=p->bookNext;
        }
        p->bookNext=temp;
        temp->bookNext=NULL;
    }
}

//  Hàm nhập thông tin 1 quyển sách và kiểm tra isbn xem nếu nó đã có trong store rồi thì cập nhật stock level của nó
void check(STORE *&list)
{
    //  Nhập thông tin sách
    STORE *temp=new STORE;
    cout<<"Title: ";
    fflush(stdin);
    gets(temp->book.title);
    cout<<"ISBN: ";
    fflush(stdin);
    gets(temp->book.isbn);
    cout<<"Author: ";
    fflush(stdin);
    gets(temp->book.author);
    cout<<"Language: ";
    fflush(stdin);
    gets(temp->book.language);
    cout<<"Year published: ";
    cin>>temp->book.yearPubl;
    cout<<"Price: ";
    cin>>temp->book.price;
    cout<<"Stock level: ";
    cin>>temp->book.stockLevel;

    //  Xử lí 
    STORE *p=list;
    while (p!=NULL)
    {
        if (strcmp(p->book.isbn,temp->book.isbn)==0)
        {
            (p->book.stockLevel)++;
            return;
        }
        p=p->bookNext;
    }
    //  Nếu chưa có thì thêm vào danh sách
    p=list;
    while (p->bookNext!=NULL)
    {
        p=p->bookNext;
    }
    p->bookNext=temp;
    temp->bookNext=NULL;
}

//  Hàm bán sách
void sellBook(STORE *&list)
{
    cout<<"Nhap ISBN cua sach: ";
    char isbn[10];
    fflush(stdin);
    gets(isbn);

    //  In ra tên và giá sách, rồi cập nhật stock level
    STORE *p=list;
    while (p!=NULL)
    {
        if (strcmp(p->book.isbn,isbn)==0)
        {
            cout<<"Title: "<<p->book.title<<endl;
            cout<<"Price: "<<p->book.price<<"$"<<endl;
            (p->book.stockLevel)--;
            return;
        }
        p=p->bookNext;
    }
    //  Ngược lại thì in ra "OUT OF STOCK"
    cout<<"OUT OF STOCK \n";
}

//  Hàm tìm sách: nhập name, in ra tất cả quyển sách (isbn và title) mà title của nó chứa name như subset
void findBook(STORE *list)
{
    cout<<"Nhap name: ";
    char name[200];
    fflush(stdin);
    gets(name);
    STORE *p=list;
    char *find=NULL;
    bool has=false;
    while (p!=NULL)
    {
        find=strstr(p->book.title,name);
        if (find!=NULL)
        {
            has=true;
            cout<<"+ ISBN: "<<p->book.isbn;
            cout<<"\n Title: "<<p->book.title<<endl;
            find=NULL;
        }
        p=p->bookNext;
    }
    //  Nếu không có thì in ra "Khong co"
    if (!has)
    {
        cout<<"\nKhong co\n";
    }
}

//  Hàm xóa các quyển sách có stock level ít hơn k
void delBook(STORE *&list)
{
    int k;
    cout<<"Nhap stock level k: ";
    cin>>k;
    STORE *p=list;
    STORE *prv=NULL;
    while (p!=NULL)
    {
        if (list->book.stockLevel<k)
        {
            //  Nếu đầu danh sách
            list=list->bookNext;
            delete p;
            p=list;
        }
        else
        {
            prv=p;
            p=p->bookNext;
            if (p!=NULL && p->book.stockLevel<k)
            {
                prv->bookNext=p->bookNext;
                delete p;
                p=prv;
            }
        }
    }
}

//  Hàm xuất thông tin các quyển sách
void output(STORE *list)
{
    cout<<"***Xuat danh sach:\n";
    STORE *p=list;
    while (p!=NULL)
    {
        cout<<"Title: "<<p->book.title<<endl;
        cout<<"ISBN: "<<p->book.isbn<<endl;
        cout<<"Author: "<<p->book.author<<endl;
        cout<<"Language: "<<p->book.language<<endl;
        cout<<"Year Published: "<<p->book.yearPubl<<endl;
        cout<<"Price: "<<p->book.price<<"$"<<endl;
        cout<<"Stock level: "<<p->book.stockLevel<<endl<<endl;
        p=p->bookNext;
    }
    cout<<endl;
}

//  Giải phóng bộ nhớ
void delStore(STORE *&list)
{
    STORE *p=list;
    while (p!=NULL)
    {
        list=list->bookNext;
        delete p;
        p=list;
    }
    list=NULL;
}
