#include <stdio.h>
#include <stdbool.h>

bool snt(int n)
{
    if (n==1) return false;
    for (int i=2;i<=n/2;i++)
        if (n%i==0) return false;
    return true;
}

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
        if (snt(i))
            for (int j=i+1;j<=n;j++)
            {   
                if (snt(j))
                {    
                    for (int k=j+1;k<=n;k++)
                    {
                            if(snt(k))
                            {  
                                if (j==(i+k)/2.0) 
                                    printf("%d ",j);
                                break;
                            }   
                    }
                    break;
                }
            }
    
    return 22;
}