#include <stdio.h>
#include <string.h>

typedef struct 
{
    char TenMH[20];
    int gia;
    int sl;
} mathang;

mathang input()
{
    mathang mh;
    printf("nhap ten mat hang: ");
    fflush(stdin);
    fgets(mh.TenMH,20,stdin);
    mh.TenMH[strlen(mh.TenMH)-1]='\0';
    printf("nhap don gia : ");
    scanf("%d",&mh.gia);
    printf("nhap so luong ton : ");
    scanf("%d",&mh.sl);
    return mh;    
}

void output(mathang mh)
{
    printf("Ten mat hang : %s\n",mh.TenMH);
    printf("Don gia : %d\n",mh.gia);
    printf("So luong ton : %d\n",mh.sl);
}

int main()
{
    mathang mh=input();
    output(mh);
    return 225;
}