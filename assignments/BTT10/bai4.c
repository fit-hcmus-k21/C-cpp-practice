#include <stdio.h>
#include <string.h>
#define MAX 100

void chuanhoa(char s[])
{
    char *p=strstr(s,"  ");
    while (p!=NULL)
    {
        strcpy(p,p+1);
        p=strstr(s,"  ");
    }
    if (s[0]==32)
    {
        strcpy(s,s+1);
    }
    if (s[strlen(s)-1]==32)
    {
        s[strlen(s)-1]='\0';
    }
}

void hoten(char s[])
{
    s=strlwr(s);
    chuanhoa(s);
    s[0]=s[0]-32;
    int i=1;
    while (s[i])
    {
        if (s[i-1]==32)
        {
            s[i]=s[i]-32;
        }
        i++;
    }
}

int main()
{
    char s[MAX];
    printf("nhap ho ten :");
    fgets(s,MAX,stdin);
    if (s[strlen(s)-1]=='\n')
    {
        s[strlen(s)-1]='\0';
    }
    hoten(s);
    printf("sau khi chuan hoa: %s\n",s);
    return 225;
}