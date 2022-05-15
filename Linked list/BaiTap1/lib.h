#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

//  Hàm nhập vào các phần tử danh sách liên kết
void input(Node *&list, int value);

//  Hàm xóa tất cả các phần tử có giá trị value trong danh sách
void delElement(Node *&list, int value);

//  Hàm xuất danh sách liên kết
void output(Node *list);

//  Hàm giải phóng bộ nhớ cho các phần tử danh sách liên kết
void deleteList(Node *&list);

