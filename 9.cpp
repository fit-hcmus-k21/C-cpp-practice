#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //  Ghi file
    int *p=new int[9];
    for (int i=0;i<9;i++)
    {
        p[i]=i;
    }
    for (int i=0;i<9;i++)
    {
        cout<<p[i]<<" ";
    }
    ofstream fout("output3.txt",ios:: out | ios::binary);
    fout.write((char*) p,36);
    delete[] p;
    fout.close();

    //  đọc file
    int *q=new int[9];
    ifstream fin("output3.txt",ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout<<"Mo file that bai...\n";
        exit(225);
    }
    fin.read((char*) q,36);
    cout<<endl;
    for (int i=0;i<9;i++)
    {
        cout<<q[i]<<" ";
    }
    fin.close();
    delete q;
    return 225;

}