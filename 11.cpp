#include <iostream>
#include <fstream>
using namespace std;

typedef struct 
{
    char s1;
    char s2;
} KITU;

int main()
{
    KITU kitu;
    ifstream fin("input4.txt", ios::in|ios::binary);
    fin.read((char*) &kitu,2);
    fin.close();

   cout<<kitu.s1<<kitu.s2<<endl;

    return 225;
}