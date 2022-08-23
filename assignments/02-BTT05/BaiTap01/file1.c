#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fout;
    int c;
    if ((fout=fopen("file1.txt","w"))==NULL)
    {
        printf("Cannot open output file\n");
        exit(1);
    }
    printf("Input string\n");
    //  Với windows ta dùng Ctrl-z để thoát
    //  Với Linux ta sẽ dùng lệnh gì?

    //  Trả lời: 
    //  Với Linux ta sẽ dùng lệnh Ctrl-d
    printf("Ctrl-z if you want to exit \n");
    while ((c=getchar())!=EOF)
    {
        putc(c, fout);
    }
    fclose(fout);
    exit(0);
    return 225;
}