#include "lib.h"

//  Định nghĩa hàm bài toán chuyển tháp Hà Nội

void ChuyenThap(char src, char medium, char dest, int n)
{
    //  Nếu chỉ còn 1 đĩa thì chuyển sang tháp đích
    if (n==1)
    {
        cout<<src<<" -----> "<<dest<<endl;
    }
    else
    {
        //  Chuyển n-1 cái đĩa từ tháp nguồn sang tháp trung gian
        ChuyenThap(src,dest,medium,n-1);

        //  Chuyển 1 cái đĩa cuối từ tháp nguồn sang tháp đích
        ChuyenThap(src,medium,dest,1);

        //  Chuyển lại n-1 cái đĩa từ tháp trung gian sang tháp đích
        ChuyenThap(medium,src,dest,n-1);
    }
    
}