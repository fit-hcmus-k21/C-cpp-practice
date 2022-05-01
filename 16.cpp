#include <iostream>
using namespace std;

typedef struct 
{
    int y;
    int *id = new int[y];
} TEST;

void xuat(TEST a)
{
    cout<<a.y<<endl;
    for (int i=0;i<a.y;i++)
    {
        cout<<a.id[i]<<" ";
    }
}

int main()
{   
    TEST hehe;
    hehe.y = 5;
    for (int i=0;i<hehe.y;i++)
    {
        hehe.id[i] = i;
    }
    TEST hihi;
    hihi = hehe;

    xuat(hehe);
    cout<<endl;
    xuat(hihi);

   
    delete[] hihi.id;
    delete[] hehe.id;

    return 225;



}