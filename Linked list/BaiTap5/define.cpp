#include "lib.h"

//  Hàm nhập vào các phần tử danh sách liên kết
void input(Node *&list, int value)
{
    Node *node=new Node;
    node->data=value;
    node->pNext=NULL;
    if (list==NULL)
    {
        list=node;
    }
    else
    {
        Node *p=list;
        while (p->pNext!=NULL)
        {
            p=p->pNext;
        }
        p->pNext=node;
    }
}

//  Hàm chèn phần tử vào danh sách liên kết mà vẫn giữ nguyên trật tự sắp xếp
void insertSort(Node *&list, int value)
{
    if (value<list->data)
    {
        //  Chèn vào đầu danh sách
        Node *node=new Node;
        node->data=value;
        node->pNext=list;
        list=node;
    }
    else
    {
        Node *p=list;
        Node *nodePrv=NULL;
        while (p!=NULL && p->data<=value)
        {
            nodePrv=p;
            p=p->pNext;
        }
        Node *newNode=new Node;
        newNode->data=value;
        nodePrv->pNext=newNode;
        newNode->pNext=p;
    }
}


//  Hàm xuất danh sách liên kết
void output(Node *list)
{
    Node *node=list;
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->pNext;
    }
    cout<<endl;
}

//  Hàm giải phóng bộ nhớ cho các phần tử danh sách liên kết
void deleteList(Node *&list)
{
    Node *p=list;
    while (list!=NULL)
    {
        list=list->pNext;
        delete p;
        p=list;
    }
}