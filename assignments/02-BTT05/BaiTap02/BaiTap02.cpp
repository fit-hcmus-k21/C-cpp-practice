#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fin;
    char c[256];
    if((fin = fopen("file1.txt", "r")) == NULL)
    {
        printf("Cannot open input file\n");
        exit(1);
    }
    printf("Contents of file1.txt:\n");
    while ((fgets(c,256,fin))!=NULL)
    {
        printf("%s",c);
    }
    fclose(fin);
    exit(0);
}
