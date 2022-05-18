#include <iostream>
#include <string.h>
using namespace std;

struct BookStore{
    char title[200];        
    char isbn[10];
    char author[40];
    char language[30];
    int yearPubl;
    int price;          //  dollars $
    int stockLevel;
};

struct STORE{
    BookStore book;
    STORE *bookNext;
};

//  Hàm nhập thông tin từng quyển sách cho cửa hàng sách
void input(STORE *&list);

//  Hàm nhập thông tin 1 quyển sách và kiểm tra isbn xem nếu nó đã có trong store rồi thì cập nhật stock level của nó
void check(STORE *&list);
    
//  Hàm bán sách
void sellBook(STORE *&list);

//  Hàm tìm sách: nhập name, in ra tất cả quyển sách (isbn và title) mà title của nó chứa name như subset
void findBook(STORE *list);

//  Hàm xóa các quyển sách có stock level ít hơn k
void delBook(STORE *&list);

//  Hàm xuất thông tin các quyển sách
void output(STORE *list);

//  Giải phóng bộ nhớ
void delStore(STORE *&list);
