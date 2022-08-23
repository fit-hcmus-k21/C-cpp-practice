#include <stdio.h>


//Enter three values
//Can three values be lengths of three sides of a triangle?

int main()
{
    int value1;
    int value2;
    int value3;
    printf("enter the first value: ");
    scanf("%d",&value1);
    printf("enter the second value: ");
    scanf("%d",&value2);
    printf("enter the third value: ");
    scanf("%d",&value3);

    if (value1<=0 || value2<=0 || value3<=0)
        printf("These values can't be lengths of three sides of a triangle !");
    else 
        if (value1 + value2 >value3 && value1 + value3>value2 && value2 +value3>value1)
            printf("These values can be lengths of three sides of a triangle ! ");
    return 0;
}