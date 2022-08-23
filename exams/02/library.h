#include <iostream>
using namespace std;
#include <string.h>
#include <fstream>
#define M 50

// Khai báo cấu trúc công việc
typedef struct 
{
    int ID;                     // mã số (duy nhất khác nhau)
    char *tenCV = new char[M];  // tên công việc
    int time;                   //  thời gian hoàn thành công việc (phút)
    char *tenNTH = new char[M]; //  tên người thực hiện
    int priority;       // độ ưu tiên: giá trị 1-10, giá trị càng nhỏ ưu tiên càng cao
} CongViec;

// Khai báo cấu trúc NODE của danh sách
struct NODE
{
    CongViec data;
    NODE *pNext;
};

// 1: Hàm khởi tạo danh sách rỗng
void khoiTao(NODE *&list);

// 2: Hàm thêm n công việc mới vào cuối danh sách 
void addTasks(NODE *&list);

// Hàm xuất thông tin một công việc trong danh sách
void output(NODE *p);

// Hàm xuất thông tin cả danh sách công việc
void outputList(NODE *list);

// 3: Hàm lấy ra 1 phần tử đầu danh sách và xóa phần tử đó  
void delNode(NODE *&list);

// 4: Hàm tìm công việc có thời gian hoàn thành cao nhất, nếu có cùng nhiều công việc như thế thì return người tên Dung NGUYEN
void timMaxTime(NODE *list);

// 5: Hàm reset thời gian hoàn thành của các công việc >300 phút thành 300 phút
void resetTime(NODE *&list);

// 6: Tính tổng thời gian các công việc của người tên X, X là tên mình
void calTime(NODE *list);

// 7: Hàm sắp xếp danh sách công việc theo độ ưu tiên từ cao đến thấp tính từ đầu danh sách
void sapXep(NODE *&list);

// 8: Ghi tất cả thông tin của các công việc có độ ưu tiên cao nhất ra tập tin nhị phân output1.bin
void ghiFile(NODE *list);

// 9: Hàm đọc thông tin từ tập tin output1.bin và tạo danh sách mới từ thông tin đọc, xuất danh sách 
void docFile(NODE *&listMaxPri);

// Hàm làm rỗng danh sách và giải phóng bộ nhớ
void delList(NODE *&list);
// 10: Viết hàm main sử dụng menu lựa chọn 
