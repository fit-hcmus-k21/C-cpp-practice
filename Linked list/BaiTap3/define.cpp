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

//  Hàm đảo ngược danh sách liên kết
void reverseList(Node *&list)
{
    Node *newList=NULL;
    Node *node=list;
    
    while (node->pNext!=NULL)   //  Theo test case của bài thì phần tử cuối là 0 không bị đảo, chỉ đảo các phần tử trước 
    {
        list=list->pNext;
        node->pNext=newList;
        newList=node;
        node=list;
    }
    list=newList;

    //  Gắn node 0 vào lại cuối danh sách
    while (newList->pNext!=NULL)
    {
        newList=newList->pNext;
    }
    newList->pNext=node;
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

