#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 30
#define N 30

//  Khai báo cấu trúc thông tin con mèo

typedef struct 
{
    int ID;
    char *KindCat = new char[M];
    char *FurCollor = new char[N];
    float Weight;
} MewMew;

MewMew NhapThongTin();
void KhoiTaoDS(MewMew *&DS, int &sl );
void XuatThongTin(MewMew meo);
void KiemTra(MewMew *&DS, int sl);
void AddCat(MewMew *&DS, int &sl);
void DeleteCat(MewMew *&DS,int &sl);
void FindCat(MewMew *&DS, int sl);
void UpdateFur(MewMew *&DS, int sl);
void Swap(MewMew *a, MewMew *b);
void ArrrangeCat(MewMew *&DS,int sl);
void Find3Cat(MewMew *&DS, int sl);
void DeleteDS(MewMew *&DS,int sl);
