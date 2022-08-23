#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct 
{
    char name[MAX];
    int id;
    float mark[3];
    float dtb;
} SV;

SV input()
{
    SV sinhvien;
    printf("Nhap ho va ten: ");
    fflush(stdin);
    fgets(sinhvien.name,MAX,stdin);
    sinhvien.name[strlen(sinhvien.name)-1]='\0';
    printf("Nhap mssv : ");
    scanf("%d",&sinhvien.id);
    printf("Nhap diem [bai tap, giua ki, cuoi ki] : ");
    scanf("%f%f%f",&sinhvien.mark[0],&sinhvien.mark[1],&sinhvien.mark[2]);
    return sinhvien;
}

void output(SV sv)
{
     printf("%d\t",sv.id);
     printf("%s\t",sv.name);
    printf("%.2f\t%.2f\t%.2f\n",sv.mark[0],sv.mark[1],sv.mark[2]);
    
}

void xuat(SV sv[],int n)
{
    printf("%-20s %-30s %-20s %-20s %-20s\n","MSSV","Ho va ten","Bai tap","Giua ki","Cuoi ki");
    for (int i=0;i<n;i++)
    {
        printf("%-20d",sv[i].id);
        printf("%-30s",sv[i].name);
        printf("  %-20.2f %-20.2f %-20.2f\n",sv[i].mark[0],sv[i].mark[1],sv[i].mark[2]);
    }
    
}

float dtb(float m1,float m2, float m3)
{
    return (m1*0.25+m2*0.25+m3*0.5);
}

int main()
{
    SV sv[MAX];
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        sv[i]=input();
    }
    printf("--------------------------------\n");
    xuat(sv,n);
    int ID;
    printf("\nnNhap ID sinh vien muon tim: ");
    scanf("%d",&ID);
    for (int i=0;i<n;i++)
    {
        if (sv[i].id==ID)
        {
            output(sv[i]);
        }
    }
    printf("\nNhap ho ten sinh vien can tim:");
    char ten[MAX];
    fflush(stdin);
    fgets(ten,MAX,stdin);
    ten[strlen(ten)-1]='\0';
    for (int i=0;i<n;i++)
    {
        if (strncmp(sv[i].name,ten,MAX)==0)
        {
            output(sv[i]);
        }
    }
    printf("\nDiem trung binh cao nhat:\n");
    
    for (int i=0;i<n;i++)
    {
        sv[i].dtb=dtb(sv[i].mark[0],sv[i].mark[1],sv[i].mark[2]);
    }
    float max=sv[0].dtb;
    for (int i=1;i<n;i++)
    {
        if (sv[i].dtb>max)
        {
            max=sv[i].dtb;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (sv[i].dtb==max)
        {
            output(sv[i]);
        }
    }
    printf("--------------end--------------\n");
    return 225;
}