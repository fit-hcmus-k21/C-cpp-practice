#include <stdio.h>

void pow(char str[],int a)
{
    while (a>0)
    {
        printf("%s ",str);
        a--;
    }
}

int main()
{
    pow("quyet tam",3);
    return 225;
}