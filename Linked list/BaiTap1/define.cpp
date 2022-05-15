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

//  Hàm xóa tất cả các phần tử có giá trị value trong danh sách
void delElement(Node *&list, int value)
{
    Node *node=list;
    Node *nodePrv=NULL;
    while (node!=NULL)
    {
        if (list->data==value)
        {
            list=list->pNext;
            delete node;
            node=list;
        }
        else
        {
            nodePrv=node;
            node=node->pNext;
            if (node != NULL && node->data==value)
            {
                nodePrv->pNext=node->pNext;
                delete node;
                node=nodePrv;
            }
        }
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
