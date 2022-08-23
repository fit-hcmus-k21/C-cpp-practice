#include<stdio.h>


/* Calculate the total money paying for renting room if knowing number of rental days and kind of room (1 in 3 kinds) ‘A’, ‘B’
or ‘C’) with rules bellow:
• kind ‘A’ : 450.000 đ/day
• kind ‘B’ : 350.000 đ/day
• kind ‘C’ : 250.00 đ/day
If renting more than 12 days, let discount :
• 10% of the total money if it's 'A' room
• 8% of the total money if they are 'B' or 'C' rooms */

int main()
{
    int days;
    char kind;
    double money;

    printf("Enter kind of room:");
    scanf("%c",&kind);
    printf("Enter number of days: ");
    scanf("%d",&days);
    
    while (days<0 || (kind!=65 && kind!=66 &&  kind!=67 && kind!=97 &&  kind!=98 && kind!=99))
       {
            printf("please :\n");
            printf("Enter kind of room:");
            _flushall();
            scanf("%c",&kind);
            printf("Enter number of days: ");
            scanf("%d",&days);      
       } 
    
    switch(kind)
        {
            case 65:
            case 97:
                {
                    money=days*450000;
                    if (days>12)
                        money=money*90/100;
                    printf("The total money that you have to pay: %f",money);
                    break;
                }
            case 66:
            case 98:
                {
                    money=days*350000;
                    if (days>12)
                        money=money*92/100;
                    printf("The total money that you have to pay: %f",money);
                    break;
                }
            case 67:
            case 99:
                {
                    money=days*250000;
                    if (days>12)
                        money=money*92/100;
                    printf("The total money that you have to pay: %f",money);
                    break;
                }
        }
    return 0;

}
