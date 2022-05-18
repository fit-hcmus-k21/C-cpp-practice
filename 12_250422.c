#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Nhap m,n: ");
    scanf("%d%d",&m,&n);
    int **p=(int**) malloc(m*sizeof(int));
    for (int i=0;i<m;i++)
    {
        p[i]=(int *) malloc(n*sizeof(int));
    }
    printf("Nhap ma tran :\n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    int s=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==j)
            {
                s=s+p[i][j];
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        free(p[i]);
    }
    free(p);
    printf("-----ket qua: %d\n",s);
    printf("\nHoan thanh...\n");
    return 225;
    
}