//  Doc file van ban input2.txt va dem so luong tu moi dong
//  Ghi vao file output2.txt

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main()
{
    ifstream fin("input2.txt",ios::in);     //  file doc du lieu
    ofstream fout("output2.txt",ios::out);  //  file ghi du lieu
    if (!fin.is_open()||!fout.is_open())
    {
        cout<<"Mo file that bai...\n";
    }
    char s[256];
    int d=0;
    char *p;
    char *s1;
    while (!fin.eof())
    {
        fin.getline(s,256);
        //  Dem so luong tu
        s1=strdup(s);
        p=strtok(s1," ");
        while (p!=NULL)
    {
        d++;
        p=strtok(NULL," ");
    }
        cout<<s<<" : "<<d<<endl;
        fout<<s<<" : "<<d<<endl;
        d=0;
    }

    //  Dong file
    fin.close();
    fout.close();
    cout<<"Hoan thanh...\n";
    return 225;
}