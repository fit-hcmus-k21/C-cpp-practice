#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct 
{
    float l;
    float r;
    float b;
    float t;
} HCN;

HCN input()
{
    HCN hcn;
    do
    {
        printf("Nhap cac thong so ");
        printf("( left,right,bottom,top ) : ");
        scanf("%f%f%f%f",&hcn.l,&hcn.r,&hcn.b,&hcn.t);
    } while (hcn.l>=hcn.r || hcn.b>=hcn.t);
    return hcn;
    
}

float max(float a,float b)
{
    return (a>b)? a:b;
}
float min(float a,float b)
{
    return (a<b)?a:b;
}

bool kiemtra(HCN h1,HCN h2)
{
    if (h2.l>h1.r || h2.r<h1.l) return 0;
    if (h2.b>h1.t || h2.t<h1.b) return 0;
    return 1;
}

HCN giaonhau(HCN h1,HCN h2)
{
    HCN giaonhau;
    giaonhau.l=max(h1.l,h2.l);
    giaonhau.r=min(h1.r,h2.r);
    giaonhau.b=max(h1.b,h2.b);
    giaonhau.t=min(h1.t,h2.t);
    return giaonhau;
}

float S(HCN hcn)
{
    return (fabs(hcn.r-hcn.l)*fabs(hcn.t-hcn.b));
}


int main()
{
    HCN h1,h2;
    printf("Hinh thu 1 :\n");
    h1=input();
    printf("Hinh thu 2 :\n");
    h2=input();
    if (kiemtra(h1,h2))
    {
        HCN h3;
        h3=giaonhau(h1,h2);
        printf("Dien tich phan giao nhau la : %.2f",S(h3));
    }
    else
    {
        printf("Hai hinh khong giao nhau \n");
    }
    
    return 225;

}