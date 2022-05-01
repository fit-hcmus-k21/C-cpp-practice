#include <stdio.h>
#include <string.h>
#define MAX 100

int dem(char s[])
{
    char *p=strdup(s);
    int d=0;
    while((p=strtok(p," .,"))!=NULL)
    {
        d++;
        p=NULL;
    }
    return d;
}
void chuanhoa(char s[])
{
    char *p=NULL;
    while ((p=strstr(s,"  "))!=NULL)
    {
        strcpy(p,p+1);
    }
    if (s[0]==' ')
    {
        strcpy(s,s+1);
    }
    if (s[strlen(s)-1]==' ')
    {
        s[strlen(s)-1]='\0';
    }
}

int main()
{
    char s[]="     hihi      hehe  hom nay,...., chung,..ta     ....,lam de,,,,... hehe ";
    printf("So luong tu: %d\n",dem(s));
    chuanhoa(s);
    printf("Chuoi sau khi chuan hoa: %s\n",s);
    printf("Hoan thanh...\n");
    return 225;
}