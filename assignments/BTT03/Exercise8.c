#include <stdio.h>

/* Enter the old numeral of water, the new numeral of water used and the number of users (old numeral<= new numeral)
  Calculate the total money having to pay for using water with the conditions of prices/person bellow:
• The first 4 m3: 4400 Đ/m3,
• The next 2 m3: 8300 Đ/m3,
• These m3 after: 10.500 Đ/m3.
For example : if there are 4 users:
• The first 16 m3 with price 4400 Đ/m3 ;
• The next 8 m3              8300 Đ/m3 ;
• these m3 after            10.500 Đ/m3 */

int main()
{
    float csc;
    float csm;
    int quantity;
    printf(" Enter the old numeral of water:");
    scanf("%f",&csc);
    printf(" Enter the new numeral of water:");
    scanf("%f",&csm);
    printf(" Enter the total users:");
    scanf("%d",&quantity);

    if (csc<0||csm<0||csm<csc||quantity<0)
    {
        printf("Please :\n");
        return main();
    }
    double money;
    float sum=csm-csc;
    if (sum>(4*quantity))
        {
            money=4*quantity*4400;
            sum=sum-4*quantity;
            if (sum>(2*quantity))
            {
                money=money+2*quantity*8300;
                sum=sum-2*quantity;
                money=money+sum*10500;
            }
            else
                money=money+sum*8300;
        }
    else
        money=sum*4400;
    
    printf("The total money that you have to pay for using water :%lf",money);
    return 0;

}