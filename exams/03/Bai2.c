#include <stdio.h>

void question_a()
{
    int a,F1,F2,F3,F4;
    F1=a=2;
    F2=18*a*a+10;
    F3=18*F2+10*F1;
    F4=18*F3+10*F2;
    printf("F3 = %d",F3);
    printf("\nF4 = %d",F4);
}
double Fn(int a,int n)
{
    double Fn=0;
    double F1,F2;
    double temp;
    F1=a;
    F2=18*a*a+10;
    for (int i=3;i<=n;i++)
    {
        Fn=18*F2+10*F1;
        temp=F2;
        F2=Fn;
        F1=temp;
    }
    if (n==1)
        return F1;
    if (n==2) 
        return F2;
    return Fn;
    
}

int main()
{
    int a;
    int n;
    do
    {
        printf("Enter a positive integer (a) :");
        scanf("%d",&a);
        printf("Enter a positive integer (n) :");
        scanf("%d",&n);
    }
    while (a<=0 || n<=0);
    printf("Result :\n");
    printf("Question a :\n");
    question_a();
    printf("\nQuestion b: \n");
    printf("Fn = %.0lf",Fn(a,n));
    return 225;
}