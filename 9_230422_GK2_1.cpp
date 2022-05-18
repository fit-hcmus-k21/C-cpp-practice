#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;



int main()
{
    ifstream docfile("input.txt");
    if (!docfile.is_open())
    {
        cout<<"Mo file that bai...\n";
    }
    char s[100];
    char *s1=nullptr;
    int d=0;
    char *p=nullptr;
    while (docfile.tellg()!=EOF)
    {
        s1=strdup(s);
        d=0;
        p=strtok(s1," \n");
        while (p!=nullptr)
        {
            d++;
            p=strtok(NULL," \n");

        }
        cout<<d<<" : "<<s;
        d=0;
    }

    docfile.close();
    cout<<"\nHoan thanh...\n";
    return 225;

}