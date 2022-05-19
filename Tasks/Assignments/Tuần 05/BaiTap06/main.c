#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[10];
    char mssv[10];
    int diemSo[3];
} SinhVien;

void Xuat(SinhVien *sv,int sl)
{
    for (int i=0;i<sl;i++)
    {
        printf("MSSV: %s\n",sv->mssv);
        printf("Ho ten: %s\n",sv->name);
        printf("Diem so: %d, %d, %d\n",(*sv).diemSo[0],(*sv).diemSo[1],(*sv).diemSo[2]);
    }
}


int main()
{
    FILE *file=fopen("sinhvien.bin","rb");
    if (!file)
    {
        printf("Mo file that bai...\n");
        return 225;
    }
    SinhVien *sv;
    int sl=0;
    while (fread(sv+sl,sizeof(SinhVien),1,file)==1)
    {
        sl++;
    }
    printf("Xuat thong tin sinh vien: \n");
    Xuat(sv,sl);
    printf("Hoan thanh...\n");
    fclose(file);
    return 225;
}