#include <stdio.h>
#include <string.h>
int main()
{
    char mem_1;
    char mem_2;
    printf("The first player :");
    _flushall();
    scanf("%c",&mem_1);
    printf("The second player :");
    _flushall();
    scanf("%c",&mem_2);
    switch(mem_1)
    {
        case 80:
        case 112:
                {
                    switch(mem_2)
                    {
                        case 80:
                        case 112:
                                printf("Result: equal !");
                                break;
                        case 82:
                        case 114:
                                printf("Result : The first player win !");
                                break;
                        case 83:
                        case 115:
                                printf("Result: The second player win !");
                                break;
                    }

                }
                break;
        case 82:
        case 114:
                {
                    switch(mem_2)
                    {
                        case 80:
                        case 112:
                                printf("Result : The second player win !");
                                break;
                        case 82:
                        case 114:
                                printf("Result : equal !");
                                break;
                        case 83:
                        case 115:
                                printf("Result: The first player win !");
                                break;
                    }

                }
                break;
        case 83:
        case 115:
                {
                    switch(mem_2)
                    {
                        case 80:
                        case 112:
                                printf("Result: The first player win !");
                                break;
                        case 82:
                        case 114:
                                printf("Result: The second player win ! ");
                                break;
                        case 83:
                        case 115:
                                printf("Result : equal !");
                                break;
                    }

                }
                break;
    }
    return 0;
}