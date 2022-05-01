#include <iostream>
using namespace std;



int main()
{
    char c;
    do 
    {
        cout<<"-------------------MENU---------------------\n";
        cout<<"1. Bo sung danh sach\n";
        cout<<"2. Sap xep danh sach theo thu tu ABC\n";
        cout<<"3. In danh sach\n";
        cout<<"*** Bam phim bat ky de thoat ...\n";
        cout<<"---------------------------------------------\n";
        c=getchar();
        fflush(stdin);
        switch((int) c)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            default:
                break;
        }

    }
    while (c==1 || c==2 || c==3);
}