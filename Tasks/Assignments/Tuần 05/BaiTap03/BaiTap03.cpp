#include <iostream>
using namespace std;

int main()
{
    int dem=0;
    FILE *file=fopen("taptin.cpp","r");
    if (!file)
    {
        cout<<"Mo file that bai..."<<endl;
        return 225;
    }
    else
    {
        while ((getc(file))!=EOF)
        {
            dem++;
        }
    }
    cout<<"So luong ky tu cua tap tin tren la: "<<dem<<" ki tu "<<endl;
    cout<<"Hoan thanh..."<<endl;
    fclose(file);
    return 225;
}