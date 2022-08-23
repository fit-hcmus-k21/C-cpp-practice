#include <stdio.h>
#include <string.h>

typedef struct 
{
    char hs[255];
    float dtb;
}   HS;
HS input()
{
    HS hs;
    printf("Nhap Ho va ten hoc sinh :");
    _flushall();
    gets(hs.hs);
    printf("Nhap DTB :");
    scanf("%d",&hs.dtb);
    return hs;
}
void xoaxau(char str[])
{
    for (int i=0;i<strlen(str);i++) str[i]=' ';
}
void swap(HS a,HS b)
{
    HS temp;
    strcpy(temp.hs,a.hs);
    temp.dtb=a.dtb;
    xoaxau(a.hs);
    strcpy(a.hs,b.hs);
    a.dtb=b.dtb;
    xoaxau(b.hs);
    strcpy(b.hs,temp.hs);
    b.dtb=temp.dtb;
}
void hienthi(HS x)
{
    printf("Ho va ten : %s",x.hs);
    printf("\nDTB : %.1f\n",x.dtb);
}

int main()
{
    int n;
    printf("Nhap so luong hoc sinh :");
    scanf("%d",&n);
    HS A[1000]={};
    for (int i=0;i<n;i++) A[i]=input();
    for (int i=0;i<n;i++)
        for (int j=i;j<n-1;j++)
            if (A[j].dtb<A[j+1].dtb) swap(A[j],A[j+1]);
    printf("Danh sach hoc sinh gioi :\n");
    for (int i=0;i<n;i++) 
        hienthi(A[i]);
    return 225;

}