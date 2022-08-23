#include <stdio.h>


//Enter a month of a year:
// How many days are there in that month ?

int main()
{
    int month;
    int year;
    printf("enter a month:");
    scanf("%d",&month);
    printf("enter a year: ");
    scanf("%d",&year);
     
    if (month<=0 || month>12 || year<=0)
        {
            printf("please :\n");
            return main();
        }
    //leap year:
    if (year%400==0 || (year%100!=0 && year%4==0))
        {
            switch(month)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12: 
                         {
                                printf("This month has 31 days !");
                                break;
                         }
                    case 2:
                        {
                            printf("This month has 29 days !");
                            break;
                        }
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        {
                            printf("This month has 30 days !");
                            break;
                        }
                }
            
        }
    else 
        {
            switch(month)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12: 
                         {
                                printf("This month has 31 days !");
                                break;
                         }
                    case 2:
                        {
                            printf("This month has 28 days !");
                            break;
                        }
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        {   printf("This month has 30 days !");
                            break;
                        }
                 }
        }
    return 0;
}