#include "lib.h"
int main()
{
    //  Khởi tạo bookstore
        STORE *list=NULL;

    //  Nhập thông tin các quyển sách cho bookstore;
        cout<<"*** Nhap thong tin cho BookStore:\n";
        char tiepTuc;
        do 
        {
            cout<<"Tiep tuc (y/n) ?  ";
            fflush(stdin);
            tiepTuc=getchar();
            if (tiepTuc=='y'){
                input(list);
            }
        } while (tiepTuc=='y');

    //  Xuất danh sách
        cout<<endl;
        output(list);

    //  Nhập vào thông tin 1 quyển sách, kiểm tra isbn xem nếu nó đã có trong store rồi thì cập nhật stock level của nó
        cout<<"\n*** Nhap thong tin 1 quyen sach va kiem tra\n";
        check(list);
        output(list);

    /*  Bán 1 quyển sách: nhập vào isbn, in ra tên và giá của quyển sách , sau đó giảm số lượng stock level của sách đó
     *  Nếu quyển sách hết hàng thì in ra "OUT OF STOCK"                    */
        cout<<"\n*** Ban sach:\n";
        sellBook(list);

    //  Tìm sách: nhập name, in ra tất cả quyển sách (isbn và title) mà title của nó chứa name như subset
        cout<<"\n*** Tim sach: \n";
        findBook(list);

    //  Xóa tất cả sách mà stock level của nó ít hơn k
        cout<<"\n*** Xoa sach:\n";
        delBook(list);
        output(list);

    //  Giải phóng bộ nhớ nếu có
        delStore(list); 

    cout<<"\nHoan thanh...\n";
    return 225;
}
