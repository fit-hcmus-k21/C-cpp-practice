#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()  
{
    // Hàm khởi tạo ngẫu nhiên
    srand(time(NULL));
    // Đọc số lượng phần tử của mảng và lưu vào n1
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);
    // Khởi tạo mảng động a1 có n1 phần tử kiểu int
    int* a1 = (int*) calloc(n1,sizeof(int));
    int i;
    for(i=0; i<n1; i++)
    {
        // Gán các phần tử trong mảng bằng 100
        *(a1+i)=100;
        // Xuất các phần tử trong mảng ra màn hình
        printf("%d ",*(a1+i) );
    }
    // Đọc số lượng phần tử (mới) của mảng, lưu vào n2
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);
    // Cấp phát lại số lượng phần tử của a1
    a1 = (int*) realloc(a1,n2*sizeof(int));
    // Nếu có nhiều phần tử hơn ban đầu, gán các phần
    // tử mới bằng 0. Lý do, không muốn sử dụng các phần tử có giá trị rác.

    if (n2>n1)
    {
        for (i=n1;i<n2;i++)
        {
            *(a1+i)=0;
        }
    }

    for(i=0; i<n2;i++)
    {
        // Xuất các phần tử của mảng ra màn hình
        printf("%d ",*(a1+i));
    }
    printf("\n");
    free(a1);
    // Kết thúc chương trình
    return 0;
}