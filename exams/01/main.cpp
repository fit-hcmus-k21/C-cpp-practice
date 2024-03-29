#include "lib.h"
#pragma

int main()
{
    //  Khởi tạo danh sách rỗng

    MewMew *DS=NULL;
    int sl=0;

    //  Kiểm tra danh sách trước khi nhập thông tin có rỗng hay không

    printf("==========Truoc Khi Nhap Rong hay Khong ?==========\n");
    KiemTra(DS,sl);

    //  Khởi tạo danh sách

    KhoiTaoDS(DS,sl);

    //  Kiểm tra danh sách sau khi nhập thông tin có rỗng nữa hay không

    printf("==========Sau Khi Nhap Rong hay Khong ?==========\n");
    KiemTra(DS,sl);

    //  Xuất thông tin danh sách mèo vừa khởi tạo

    printf("==========Sau Khi Khoi Tao===========\n");
    for (int i=0;i<sl;i++)
    {
        XuatThongTin(DS[i]);
    }

    //  Thêm 1 con mèo vào cuối danh sách

    AddCat(DS,sl);

    //  Xuất danh sách sau khi thêm mèo

    printf("==========Sau Khi Them Meo===========\n");
    for (int i=0;i<sl;i++)
    {
        XuatThongTin(DS[i]);
    }

    //  Xóa con mèo cuối cùng trong danh sách

    DeleteCat(DS,sl);

    //  Xuất danh sách sau khi xóa mèo

    printf("==========Sau Khi Xoa Meo===========\n");
    for (int i=0;i<sl;i++)
    {
        XuatThongTin(DS[i]);
    }

    //  Tìm con mèo có cân nặng nhỏ nhất

    FindCat(DS,sl);

    //  Cập nhật màu lông cho mèo

    UpdateFur(DS,sl);

    //  Xuất danh sách sau khi cập nhật màu lông

    printf("==========Sau Khi Cap Nhat Mau Long===========\n");
    for (int i=0;i<sl;i++)
    {
        XuatThongTin(DS[i]);
    }

    //  Sắp xếp danh sách tăng dần theo cân nặng và xuất danh sách sau khi sắp xếp

    ArrrangeCat(DS,sl);

    //  Tìm và trả về danh sách 3 con mèo có cân nặng lớn nhất

    Find3Cat(DS,sl);

    //  Xóa rỗng danh sách

    DeleteDS(DS, sl);  

    //  Giải phóng vùng nhớ
    
    for (int i=0;i<sl;i++)
    {
        delete[] DS[i].KindCat;
        delete[] DS[i].FurCollor;
    }

    printf("**********Hoan thanh**********\n");
    free(DS);
    return 225;
}