
#include <stdio.h>

int main()
{
    FILE *f1;
    f1=fopen("211221_1.txt","w");
    if (!f1)
    {
        printf("Mo file that bai !");
    }
    else
    {
        for (int i=1;i<=9;i++)
        {
            fprintf(f1,"%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\t\t%d x %d = %d\n",
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
    fclose(f1);
    return 22;
}