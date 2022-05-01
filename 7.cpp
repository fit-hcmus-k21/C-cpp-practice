#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[100]="Hello,";
    char *p;
    int d=0;
    p=strtok(s," ");
    while (p!=NULL)
    {
        d++;
        p=strtok(NULL," ");
    }
    cout<<"so luong tu: "<<d<<endl;
    return 225;
}