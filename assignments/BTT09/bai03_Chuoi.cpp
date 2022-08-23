#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#define MAX 100

void nhap(char s[])
{
    cout<<"nhap chuoi :";
    fflush(stdin);
    fgets(s,MAX,stdin);
}

void xuat(char s[])
{
    printf("xuat chuoi : %s\n",s);
}

bool space(char c)
{
    if (c==32)
    {
        return true;
    }
    return false;
}

void chuan_hoa(char s[])
{
    for (int i=1;i<strlen(s);i++)
    {
        if (space(s[i-1]) && space(s[i]))
        {
            memmove(s+i-1,s+i,strlen(s)-i-1);
            s[strlen(s)-1]='\0';
             i--;
        }
    }
    s[strlen(s)-1]='\0';

}

void chuan_hoa_ht(char hoten[])
{
    
    for (int i=0;i<strlen(hoten);i++)
    {
        if (i==0)
        {
            if (hoten[i]>=97)
                {
                    hoten[i]=hoten[i]-32;
                }
        }
        else
        {
            if (space(hoten[i-1]))
            {
                if (hoten[i]>=97)
                {
                    hoten[i]=hoten[i]-32;
                }
            }
        }

    }

}

int main()
{
    char s[MAX];
    nhap(s);
    xuat(s);
    chuan_hoa(s);
    cout<<"sau khi chuan hoa:"<<s<<endl;
    nhap(s);
    chuan_hoa_ht(s);
    cout<<"sau khi chuan hoa :"<<s<<endl;
    return 225;
}