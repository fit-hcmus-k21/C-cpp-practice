#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    printf("Do dai canh thu nhat :");
    scanf("%f", &a);
    printf("Do dai canh thu hai :");
    scanf("%f", &b);
    printf("Do dai canh thu ba :");
    scanf("%f", &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
            printf("Tam giac deu !");
        else
        {
            if (a == b || a == c || b == c)
            {
                if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
                    printf("Tam giac vuong can !");
                else
                    printf("Tam giac can !");
            }

            else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
                printf("Tam giac vuong !");
            else
                printf("Tam giac thuong !");
        }
    }
    else
        printf(" Khong phai tam giac !");
    
    /* test */
    float eps=1e-9;


    printf("\n %f = %f", pow(a, 2) + pow(b, 2), pow(c, 2));

    if (fabs(pow(a,2)+pow(b,2)-pow(c,2))<eps)  printf(" Hihi");

    if (a * a + b * b == c * c ) printf(" Hehe");


    return 0;
}