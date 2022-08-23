#include <stdio.h>
#include <math.h>

int main()
{
    float x1,y1,r1;
    float x2,y2,r2;
    printf("Enter the data of first circle (r1,x1,y1):");
    scanf("%f %f %f",&r1,&x1,&y1);
    printf("Enter the data of second circle (r2,x2,y2):");
    scanf("%f %f %f",&r2,&x2,&y2);
    float distance ;
    distance =sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    if (distance==r1+r2) 
        printf("Khong giao nhau !");
    else 
        if (distance>r1+r2) 
            printf("Nam ngoai nhau !");
        else
            if (distance==fabs(r1-r2))
                 printf("Nam trong nhau !");
            else
                printf("Giao nhau !");
    return 0;
}