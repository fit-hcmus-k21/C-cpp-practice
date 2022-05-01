//  Đọc/ghi file nhị phân

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file=fopen("input1.txt","r");
    int x,y;
    fscanf(file,"%d %d",&x,&y);
    int **p=NULL;
    p=(int *)* malloc(x*sizeof(int));
    for (int i=0;i<x;i++)
    {
        p[i]=(int*) malloc(y*sizeof(int));
    }
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            fscanf(file,"%d",p[i][j]);
        }
    }
    //  Xuat ra man hinh
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }


    //  Giai phong bo nho
    for (int i=0;i<x;i++)
    {
        free(p[i]);
    }
    free(p);
    //  Dong file
    _fcloseall;
    printf("\nHoan thanh...\n");
    return 225;
}