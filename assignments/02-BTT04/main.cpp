#include "BaiTap01.h"

int main()
{
    SINHVIEN sv;
    //  Nhập 1 sinh viên từ bàn phím
    cout<<"-----------------------------------"<<endl;
    cout<<"Nhap thong tin 1 sinh vien:"<<endl;
    sv=nhap();

    //  Xuất sinh viên ra màn hình
    cout<<"-----------------------------------"<<endl;
    cout<<"Xuat thong tin sinh vien:"<<endl;
    xuat(sv);

    //  Kiểm tra mssv có hợp lệ hay không
    cout<<"-----------------------------------"<<endl;
    cout<<"Kiem tra mssv co hop le hay khong: "<<endl;
    if (kiemtra_mssv)
    {
        cout<<"Mssv hop le..."<<endl;
    }
    else
    {
        cout<<"Mssv khong hop le..."<<endl;
    }

    //  Hiệu chỉnh tên sinh viên
    cout<<"-----------------------------------"<<endl;
    cout<<"Hieu chinh ho ten sinh vien:"<<endl;
    cout<<"Ten truoc khi hieu chinh: "<<sv.hoten<<endl;
    HieuChinh(sv.hoten);
    cout<<"Ten sau khi hieu chinh: "<<sv.hoten<<endl;

    //  Kiểm tra xem một chuỗi có xuất hiện trong tên sinh viên hay không
    char chuoikitu[50];
    cout<<"-----------------------------------"<<endl;
    cout<<"Kiem tra xem mot chuoi co  xuat hien trong ten sinh vien hay khong: "<<endl;
    cout<<"Nhap chuoi ki tu: ";
    cin.ignore()>>chuoikitu;
    if (kiemtra_Hoten(sv.hoten,chuoikitu))
    {
        cout<<"Chuoi ki tu XUAT HIEN trong ho ten..."<<endl;
    }
    else
    {
        cout<<"chuoi ki tu KHONG XUAT HIEN trong ho ten..."<<endl;
    }

    //  Nhập và xuất danh sách sinh viên n phần tử
    cout<<"-----------------------------------"<<endl;
    cout<<"Nhap va xuat danh sach sinh vien: "<<endl;
    SINHVIEN *DSSV;
    int sl;
    cout<<"Nhap so luong sinh vien: ";
    cin>>sl;
    DSSV= new SINHVIEN[sl];
    cout<<"Nhap danh sach sinh vien: "<<endl;
    Nhap_DSSV(DSSV,sl);
    cout<<"Xuat danh sach sinh vien: "<<endl;
    Xuat_DSSV(DSSV,sl);

    //  Tìm sinh viên có điểm trung bình cao nhất
    cout<<"-----------------------------------"<<endl;
    cout<<"Tim sinh vien co diem trung binh cao nhat: "<<endl;
    TimSV_DTB_Max(DSSV,sl);

    //  Sắp xếp danh sách sinh viên tăng dần theo mssv
    cout<<"-----------------------------------"<<endl;
    cout<<"Sap xep danh sach sinh vien tang dan theo mssv: "<<endl;
    SapXep_TangDan(DSSV,sl);
    Xuat_DSSV(DSSV,sl);

    //  Sắp xếp danh sách sinh viên giảm dần theo mssv
    cout<<"-----------------------------------"<<endl;
    cout<<"Sap xep danh sach sinh vien giam dan theo mssv: "<<endl;
    SapXep_GiamDan(DSSV,sl);
    Xuat_DSSV(DSSV,sl);

    //  Tìm 5 sinh viên có điểm trung bình cao nhất...
    cout<<"-----------------------------------"<<endl;
    cout<<"Tim 5 sinh vien co diem trung binh cao nhat: "<<endl;
    Tim_5sv(DSSV,sl);

    //  Kết thúc chương trình
    cout<<"-----------------------------------"<<endl;
    cout<<"Hoan thanh..."<<endl;

    delete[] DSSV;
    return 225;
}