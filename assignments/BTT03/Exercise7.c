#include <stdio.h>

//Calculate the total money paying for electricity

int main ()
{
    float csc;
    float csm;
    printf("enter an old numeral :");
    scanf("%f", &csc);
    printf("enter a new numeral: ");
    scanf("%f",&csm);

    if (csc>csm || csc<0 || csm<0) 
        {
            printf("please:\n");
            return main();
        }
    
    float total;
    total=csm-csc;

    float money;
    if (total<=100) 
        money=total*1400;
    
    if (total>100 && total<=150)
        money=100*1400+(total-100)*1500;

    if (total>150 && total<=200)
        money=100*1400+50*1500+(total-150)*1700;
    
    if (total>200)
        money=100*1400+50*1500+50*1700+(total-200)*1900;

    printf("the total money paying for electricity: %f",money);
    
    return 0;
}