#include <stdio.h>
#include <string.h>
char *tach_ten(char *name)
{
    char *p;
    strcpy(p,name);
    char *ten=strtok(p," ");
    while(ten!=NULL)
    {
        strtok(NULL," ");
    }
}
int main()
{
    char name1[50]="Bui Thi Thanh Ngan";
    char name2[50]="Bui Thanh Tien";

}