#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

typedef struct 
{
    char name[50];
    int id;
    float diemLT;
    float diemTH;
    float DTB;
    char XL[50];    //  Xếp loại 
} SinhVien;

void XepLoai(SinhVien SV[],int sl)
{
    for (int i=0;i<sl;i++)
    {
        if (SV[i].DTB<5)
        {
            strcpy(SV[i].XL,"Yeu");
        }
        if (SV[i].DTB>=5 && SV[i].DTB<7)
        {
            strcpy(SV[i].XL,"Trung Binh");
        }
        if (SV[i].DTB>=7 && SV[i].DTB<8)
        {
            strcpy(SV[i].XL,"Kha");
        }
        if (SV[i].DTB>=8)
        {
            strcpy(SV[i].XL,"Gioi");
        }
    }
}

SinhVien input()
{
    SinhVien sv;
        printf("Ten : \n");
        fflush(stdin);
        fgets(sv.name,50,stdin);
        int len=strlen(sv.name)-1;
        sv.name[len]='\0';
        printf("MSSV: \n");
        scanf("%d",&sv.id);
        printf("Diem Ly thuyet: \n");
        scanf("%f",&sv.diemLT);
        printf("Diem Thuc Hanh: \n");
        scanf("%f",&sv.diemTH);
        printf("\n");
    return sv;

}

void nhap(SinhVien SV[],int *sl)
{
    printf("Nhap so luong sinh vien: ");
    scanf("%d",sl);
    for (int i=0;i<*sl;i++)
    {
        printf("Nhap thong tin sinh vien thu %d : \n",i+1);
        SV[i]=input();
    }

    //  Tính DTB của sinh viên

    for (int i=0;i<*sl;i++)
    {
        SV[i].DTB=SV[i].diemTH*0.3+SV[i].diemLT*0.7;
    }
}

void Xuat(SinhVien SV[],int sl)
{
    printf("Xuat danh sach sinh vien:\n");
    printf("%-20s%-40s%-10s%-10s%-10s%-15s\n","MSSV","Ho ten","Diem LT","Diem TH","DTB","Xep Loai");
    for (int i=0;i<sl;i++)
    {
        printf("%-20s",SV[i].id);
        printf("%-40s",SV[i].name);
        printf("   %.2f   ",SV[i].diemLT);
        printf("   %.2f   ",SV[i].diemTH);
        printf("   %.2f   ",SV[i].DTB);
        printf("%-15s",SV[i].XL);
        printf("\n");
    }
}

void XoaSV(SinhVien SV[],int *sl)
{
    for (int i=0;i<*sl;i++)
    {
        if (strcmp(SV[i].XL,"Yeu")==0)
        {
            memmove(SV+i,SV+i+1,(*sl-i-1)*sizeof(SV[0]));
            (*sl)--;
        }
    }
    Xuat(SV,*sl);
}

int main()
{
    SinhVien SV[MAX];
    int sl;
    nhap(SV,&sl);
    XepLoai(SV,sl);
    Xuat(SV,sl);
    XoaSV(SV,&sl);
    printf("Hoan thanh...\n");
    return 225;
}