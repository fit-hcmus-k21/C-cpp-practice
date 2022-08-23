#include <stdio.h>
#define MAX 100

void nhap(int a[][MAX],int *m,int *n)
{
    printf("Nhap so dong (m) : ");
    scanf("%d",m);
    printf("Nhap so cot (n) : ");
    scanf("%d",n);
    printf("Nhap ma tran:\n");
    for (int i=0;i<*m;i++)
    {
        for (int j=0;j<*n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void xuat(int a[][MAX],int m,int n)
{
    printf("Ma tran: \n");
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void HangMin(int a[][MAX],int m,int n)
{
    //  Khởi tạo giá trị min là tổng của dòng đầu tiên :

    int min=0;
    for (int j=0;j<n;j++)
    {
        min=min+a[0][j];
    }
    //  Tìm hàng có tổng nhỏ nhất 

    for (int i=0;i<m;i++)
    {
        int sum=0;
        for (int j=0;j<n;j++)
        {
            sum=sum+a[i][j];
        }
        if (sum<min)
        {
            min=sum;
        }
    }
    //  Duyệt lại ma trận và tìm tất cả các hàng có tổng bằng min và lưu vào mảng vt chỉ số hàng
    
    int vt[MAX];
    int sl=0;   // sl: số số hàng có tổng bằng min
    for (int i=0;i<m;i++)
    {
        int sum=0;
        for (int j=0;j<n;j++)
        {
            sum=sum+a[i][j];
        }
        if (sum==min)
        {
            vt[sl++]=i;
        }
    }
    //  In ra màn hình hàng có tổng nhỏ nhất và các số trên hàng đó
    printf("Hang co tong nho nhat cua ma tran : \n");
    for (int i=0;i<sl;i++)
    {
        printf("Hang thu %d : ",vt[i]+1);
        for (int j=0;j<n;j++)
        {
            printf("%d ",a[vt[i]][j]);
        }
        printf("\n");
    }
}

void TimMT(int a[][MAX],int m,int n)
{
    int r,s;
    printf("Nhap kich thuoc ma tran con M [rxs] : ");
    scanf("%d%d",&r,&s);
    //  Tìm ma trận con M [rxs] có tổng lớn nhất

    int max=0;
    for (int i=0;i<=m-r;i++)
    {
        for (int j=0;j<=n-s;j++)
        {
            int sum=0;
            for (int h=i;h<i+r;h++)     //  Lần lượt duyệt từ vị trí ô (i,j) tìm tổng ma trận con
            {
                for (int c=j;c<j+s;c++)
                {
                    sum=sum+a[h][c];
                }
            }
            if (i==0 && j==0)       //  khởi tạo giá trị max là tổng của ma trận ở lần duyệt đầu tiên
            {
                max=sum;
            }
            if (sum>max)
            {
                max=sum;
            }
        }
    }

    //      Duyệt lại mảng và tìm các ma trận con bằng tổng max

    printf("Ma tran con co tong lon nhat bang %d :\n",max);
    for (int i=0;i<=m-r;i++)
    {
        for (int j=0;j<=n-s;j++)
        {
            int sum=0;
            for (int h=i;h<i+r;h++)     
            {
                for (int c=j;c<j+s;c++)
                {
                    sum=sum+a[h][c];
                }
            }
            if (sum==max)
            {
                //  Xuất ma trận con bắt đầu từ vị trí ô (i,j)

                for (int h=i;h<i+r;h++)     
                {
                    for (int c=j;c<j+s;c++)
                    {
                        printf("%d ",a[h][c]);
                    }
                    printf("\n");
                }
                
            }
        }
    }
    
}

int main()
{
    int a[MAX][MAX];
    int m,n;
    int luachon;
    do
    {
        printf("-------------------MENU-----------------\n");
        printf("1. Nhap ma tran \n");
        printf("2. Xuat ma tran \n");
        printf("3. Tim hang co tong nho nhat ma tran\n");
        printf("4. Tim ma tran con M co kich thuoc rxs co tong lon nhat tu ma tran\n");
        printf("5. Dung chuong trinh\n");
        printf("Moi ban lua chon [1->5]: ");
        scanf("%d",&luachon);
        switch(luachon)
        {
            case 1:
            {
                nhap(a,&m,&n);
                printf("Hoan thanh..\n");
                break;
            }
            case 2:
            {   
                xuat(a,m,n);
                printf("Hoan thanh...\n");
                break;
            }
            case 3:
            {
                HangMin(a,m,n);
                printf("Hoan thanh...\n");
                break;
            }
            case 4:
            {
                TimMT(a,m,n);
                printf("Hoan thanh...\n");
                break;
            }
            case 5:
            {
                break;
            }
        }
    }
    while (luachon!=5);
    printf("\nKet thuc...\n");
    return 225;
}