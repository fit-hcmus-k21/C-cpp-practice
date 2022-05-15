#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

//  Hàm nhập vào các phần tử danh sách liên kết
void input(Node *&list, int value);

//  Hàm đảo ngược danh sách liên kết
void reverseList(Node *&list);


//  Hàm xuất danh sách liên kết
void output(Node *list);

//  Hàm giải phóng bộ nhớ cho các phần tử danh sách liên kết
void deleteList(Node *&list);


