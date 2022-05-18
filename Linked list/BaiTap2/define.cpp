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

//  Hàm xóa các phần tử xuất hiện nhiều lần để chỉ xuất hiện 1 lần
void delRepeat(Node *&list)
{
    Node *p1=list;
    while (p1!=NULL)
    {
        Node *p2=p1->pNext;
        Node *Prv=p1;
        while (p2!=NULL)
        {

            if (p2->data==p1->data)
            {
                //  Xóa node mà p2 trỏ vào
                Prv->pNext=p2->pNext;
                delete p2;
                p2=Prv->pNext;
            }
            else
            {
                Prv=p2;
                p2=p2->pNext;
            }
        }
        p1=p1->pNext;
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
