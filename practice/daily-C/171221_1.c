#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int main()
{
    char chuoi[MAX];
    printf(" Nhap chuoi :");
    fgets(chuoi,MAX,stdin);
    bool hople =1;
    for (int i=0;i<strlen(chuoi)-1;i++)
    {
        switch(chuoi[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                    hople=0;
                    break;
        }
        if (!hople)
        {
            printf("Khong hop le \n");
            break;
        }
    }
    if (hople)
    {
        printf("Hop le \n");
    }
    printf("%s",chuoi);
    return 22;
}