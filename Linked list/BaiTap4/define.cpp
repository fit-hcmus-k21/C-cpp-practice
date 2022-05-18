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

//  Hàm chèn số chẵn vào danh sách liên kết
void insertEven(Node *&list)
{
    int num=2;

    //  Chèn đầu danh sách
    Node *node=new Node;
    node->data=num;
    node->pNext=list;
    list=node;

    Node *l=list->pNext;
    while (l->pNext->data!=0)
    {
        Node *newNode=new Node;
        num+=2;
        newNode->data=num;
        newNode->pNext=l->pNext;
        l->pNext=newNode;
        l=newNode->pNext;
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
