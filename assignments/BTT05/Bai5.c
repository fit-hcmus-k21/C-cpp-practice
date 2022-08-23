#include <stdio.h>
/* Lưu ý : chương trình chỉ áp dụng được khi đổi từ số nguyên dương sang nhị phân :> */
int main()
{
    int decimal;
    printf("Enter a positive integer :");
    scanf("%d",&decimal);
    int duplicate=decimal;
    int reverse=0;
    int binary=0;
    int digit;
    while (decimal!=0)
    {
        digit=decimal%2;
        reverse=reverse*10+digit;
        decimal=decimal/2;
    }
    while (reverse!=0)
    {
        digit=reverse%10;
        binary=binary*10+digit;
        reverse=reverse/10;
    }
    printf("Result: %d => %d ",duplicate,binary);
    return 0;
}