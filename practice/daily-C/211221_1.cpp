#include <iostream>
using namespace std;

int main()
{
    FILE *file;
    file=fopen("211221_11.txt","w");
    if (!file)
    {
        cout <<"Mo file that bai !";
    }
    else
    {
        for (int i=1;i<=9;i++)
        {
            fprintf(file,"%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\n",
                        2,i,i*2,
                        3,i,i*3,
                        4,i,i*4,
                        5,i,i*5,
                        6,i,i*6,
                        7,i,i*7,
                        8,i,i*8,
                        9,i,i*9);
        }
    }
    return 22;
    
}