#include "library.h"
#pragma()

// 10: Viết hàm main sử dụng menu lựa chọn 
int main()
{
    // Khai báo các danh sách
    NODE *list;
    NODE *listMaxPri;

    int val;
    do 
    {
        cout<<"\n---------------------------------------------------MENU---------------------------------------------------\n";
        cout<<"0. Thoat chuong trinh.\n";
        cout<<"1. Khoi tao danh sach rong.\n";
        cout<<"2. Them n cong viec moi vao cuoi danh sach.\n";
        cout<<"3. Lay ra 1 phan tu dau danh sach va xoa phan tu do.\n";
        cout<<"4. Tim cong viec co thoi gian hoan thanh cao nhat.\n";
        cout<<"5. Cap nhat thoi gian cho cong viec co thoi gian hoan thanh >300' thanh 300'.\n";
        cout<<"6. Tinh tong thoi gian hoan thanh cac cong viec cua nguoi ten X (X: ten ban).\n";
        cout<<"7. Sap xep danh sach cong viec theo do uu tien tu cao den thap tinh tu dau danh sach.\n";
        cout<<"8. Ghi tat ca thong tin cua cac cong viec co do uu tien cao nhat ra tap tin nhi phan output1.bin\n";
        cout<<"9. Doc tat ca thong tin tu tap tin output1.bin va tao danh sach moi tu thong tin doc duoc. Xuat danh sach.\n";
        cout<<"10. Xuat danh sach.\n";
        cout<<"**********************************************************************************************************\n";
        cout<<"\nMoi ban lua chon : ";
        cin>>val;
        switch(val)
        {
            case 0:
                cout<<"\n***************KET THUC CHUONG TRINH******************\n";
                break;
            case 1:
                cout<<"\nKhoi tao danh sach rong:\n";
                khoiTao(list);
                break;
            case 2:
                cout<<"\nThem n cong viec vao cuoi danh sach:\n";
                addTasks(list);
                break;
            case 3:
                cout<<"\nLay ra 1 phan tu dau danh sach va xoa danh sach do:\n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Ban chua khoi tao danh sach ! \n";
                }
                else
                {
                    delNode(list);
                }
                break;
            case 4:
                cout<<"\nTim cong viec co thoi gian hoan thanh cao nhat:\n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Hay khoi tao danh sach truoc !\n";
                }
                else
                {
                     timMaxTime(list);
                }
                break;
            case 5:
                cout<<"\nCap nhat thoi gian hoan thanh cho cong viec tren 300 phut: \n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Hay khoi tao danh sach !\n";
                }
                else
                {
                    resetTime(list);
                }
                break;
            case 6:
                cout<<"\nTinh tong thoi gian hoan thanh cong viec cua nguoi thuc hien: \n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Hay khoi tao danh sach truoc !\n";
                }
                else
                {
                    calTime(list);
                }
                break;
            case 7:
                cout<<"\nSap xep danh sach cong viec theo do uu tien cao den thap :\n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Hay khoi tao danh sach truoc !\n";
                }
                else
                {
                    sapXep(list);
                }
                break;
            case 8:
                cout<<"\nGhi thong tin cac cong viec co do uu tien cao nhat ra tap tin output1.bin: \n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong ! Hay khoi tao danh sach truoc !\n";
                }
                else
                {
                    ghiFile(list);
                }
                break;
            case 9:
                cout<<"\nDoc thong tin tu tap tin output1.bin va tao danh sach moi. Xuat danh sach : \n";
                docFile(listMaxPri);
                break;
            case 10: 
                cout<<"\nXuat danh sach: \n";
                if (list==NULL)
                {
                    cout<<"Danh sach rong !\n";
                }
                else
                {
                    outputList(list);
                }
                break;
            default: 
                cout<<"\nKhong co yeu cau nay ! Moi ban nhap lai !\n";
                break;            
        }
    } while (val!=0);

    //  Giải phóng bộ nhớ
    delList(list);
    delList(listMaxPri);
    
    cout<<"...hoan thanh...\n";
    return 225;

}