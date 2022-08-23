#include <stdio.h>
#define MAX 100
#include <stdbool.h>

typedef struct 
{
    char ten[MAX];
    float toan,ly;
    float dtb;
} hs;

hs nhap(int i)
{
    hs hocsinh;
    printf("Nhap ten hoc sinh thu %d :",i+1);
    fgets(hocsinh.ten,MAX,stdin);
    printf("Nhap diem toan,ly:");
    scanf("%f%f",&hocsinh.toan,&hocsinh.ly);
    return hocsinh;
}


int main()
{
    
    

}
