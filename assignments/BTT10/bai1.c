#include <stdio.h>
#include <stdbool.h>
#define MAX 100


typedef struct 
{
    int tuso;
    int mauso;
}phanso;

phanso input()
{
    phanso ps;
    printf("\nNhap tu so:");
    scanf("%d",&ps.tuso);
    printf("Nhap mau so:");
    scanf("%d",&ps.mauso);
    return ps;
}

void output(phanso ps)
{
    if (ps.tuso==0)
    {
        printf(" 0 ");
    }
    else
    {
        if (ps.tuso==1 && ps.mauso==1)
        {
            printf(" 1 ");
        }
        else
        {
            printf("   %d/%d  ",ps.tuso,ps.mauso);
        }
    }
}

int ucln(int a, int b)
{
    for (int i=a;i>=1;i--)
    {
        if (a%i==0 && b%i==0)
        {
            return i;
        }
    }
}
int bcnn(int a,int b)
{
    return a*b/ucln(a,b);
}

phanso toigian(phanso *ps)
{
    int uc=1;
    while((uc=ucln((*ps).tuso,(*ps).mauso))>1)
    {
        (*ps).tuso/=uc;
        (*ps).mauso/=uc;
    }
    return *ps;
}

phanso tong(phanso ps1,phanso ps2)
{
    phanso sum;
    sum.tuso=0;
    sum.mauso=1;
    if (ps1.tuso==0)
    {
        return ps2;
    }
    if (ps2.tuso==0)
    {
        return ps1;
    }
    
    (sum).tuso=ps1.tuso*ps2.mauso+ps1.mauso*ps2.tuso;
    (sum).mauso=ps1.mauso*ps2.mauso;
    return sum;
}

void sosanh1(phanso ps1,phanso ps2)
{
    int mc=bcnn(ps1.mauso,ps2.mauso);
    ps1.tuso=ps1.tuso*(mc/ps1.mauso);
    ps2.tuso=ps2.tuso*(mc/ps2.mauso);
    if (ps1.tuso>ps2.tuso)
    {
        printf("Phan so %d/%d > %d/%d",ps1.tuso,ps1.mauso,ps2.tuso,ps2.mauso);
        
    }
    else
    {
        if (ps1.tuso<ps2.tuso)
        {
            printf("phan so %d/%d < %d/%d",ps1.tuso,ps1.mauso,ps2.tuso,ps2.mauso);
            
        }
        else
        {
            printf("Phan so %d/%d = %d/%d",ps1.tuso,ps1.mauso,ps2.tuso,ps2.mauso);
            
        }
    }
}

void nhap(phanso a[],int n)
{
    for (int i=0;i<n;i++)
    {
        a[i]=input();
    }
}

void xuat(phanso a[],int n)
{
    for (int i=0;i<n;i++)
    {
        output(a[i]);
    }
}

bool sosanh2(phanso ps1,phanso ps2)
{
    int mc=bcnn(ps1.mauso,ps2.mauso);
    ps1.tuso=ps1.tuso*(mc/ps1.mauso);
    ps2.tuso=ps2.tuso*(mc/ps2.mauso);
    if (ps1.tuso>ps2.tuso)
    {
        return true;
    }
    return false;
}

phanso psln(phanso a[],int n)
{
    phanso max=a[0];
    for (int i=1;i<n;i++)
    {
        if (sosanh2(a[i],max))
        {
            max=a[i];
        }
    }
    return max;
}

int main()
{
    phanso a[MAX];
    int n;
    printf("Nhap n : ");
    scanf("%d",&n);
    nhap(a,n);
    xuat(a,n);
    printf("\n phan so lon nhat la: ");
    phanso max=psln(a,n);
    output(max);
    phanso sum;
    sum.tuso=0;
    sum.mauso=1;
    for (int i=0;i<n;i++)
    {
        sum=tong(sum,a[i]);
    }
    printf("\nket qua: ");
    output(sum);
    printf("\nToi gian: ");
    output((sum=toigian(&sum)));
    return 225;
}
