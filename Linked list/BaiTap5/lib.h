#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

//  Hàm nhập vào các phần tử danh sách liên kết
void input(Node *&list, int value);

//  Hàm chèn phần tử vào danh sách liên kết mà vẫn giữ nguyên trật tự sắp xếp
void insertSort(Node *&list, int value);


//  Hàm xuất danh sách liên kết
void output(Node *list);

//  Hàm giải phóng bộ nhớ cho các phần tử danh sách liên kết
void deleteList(Node *&list);