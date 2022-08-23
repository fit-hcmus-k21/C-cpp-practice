#include "library.h"

// 1: Hàm khởi tạo danh sách rỗng
void khoiTao(NODE *&list)
{
    list=NULL;
}

// 2: Hàm thêm n công việc mới vào cuối danh sách 
void addTasks(NODE *&list)
{
    // Do file input1.txt được tạo ra dưới 12 công việc nên ta giới hạn số lượng công việc muốn thêm
    int n;
    do 
    {
        cout<<"Nhap so luong cong viec muon them vao danh sach (n<=11): ";
        cin>>n;
    } while (n<1 || n>11);
    
    // Đọc file input1.txt để lấy dữ liệu
    ifstream fin;
    fin.open("input1.txt",ios::in);
    if (!fin.is_open())
    {
        cout<<"Mo file that bai...\n";
        exit(225);
    }

    for (int i=0;i<n;i++)
    {
        NODE *p = new NODE;
        // Đây là cách lấy dữ liệu từ việc nhập bàn phím
        // cout<<"Nhap thong tin: ";
        // cout<<"ID: ";
        // cin>>p->data.ID;
        // cout<<"Ten cong viec: ";
        // fflush(stdin);
        // gets(p->data.tenCV);
        // cout<<"Thoi gian hoan thanh: ";
        // cin>>p->data.time;
        // cout<<"Ten nguoi thuc hien: ";
        // fflush(stdin);
        // gets(p->data.tenNTH);
        // cout<<"Do uu tien: ";
        // cin>>p->data.priority;
        
        // Lấy thông tin công việc từ file input
        fin>>p->data.ID;
        cout<<p->data.ID<<endl;
        cout<<fin.tellg()<<endl;
        fin.ignore(1);
        fin.getline((char*)p->data.tenCV,M);
        fin>>p->data.time;
        fin.ignore(1);
        fin.getline(p->data.tenNTH,M);
        fin>>p->data.priority;
        p->pNext=NULL;

        //  Thêm công việc vào danh sách
        if (list==NULL)
        {
            //  Nếu danh sách rỗng thì thêm vào đầu danh sách
            list=p;
        }
        else
        {
            // Ngược lại, thêm vào cuối danh sách
            NODE *q=list;
            while (q->pNext!=NULL)
            {
                q=q->pNext;
            }
            q->pNext=p;
        }
    }
    fin.close();
}

// Hàm xuất thông tin một công việc trong danh sách
void output(NODE *p)
{
    cout<<"Ma so: "<<p->data.ID<<endl;
    cout<<"Ten cong viec: "<<p->data.tenCV<<endl;
    cout<<"Thoi gian hoan thanh: "<<p->data.time<<endl;
    cout<<"Ten nguoi thuc hien: "<<p->data.tenNTH<<endl;
    cout<<"Do uu tien: "<<p->data.priority<<endl;
    cout<<endl;
}

// Hàm xuất thông tin cả danh sách công việc
void outputList(NODE *list)
{
    NODE *p=list;
    while (p!=NULL)
    {
        output(p);
        p=p->pNext;
    }
}

// 3: Hàm lấy ra 1 phần tử đầu danh sách và xóa phần tử đó  
void delNode(NODE *&list)
{
    NODE *p=list;
    list=list->pNext;
    delete[] p->data.tenCV;
    delete[] p->data.tenNTH;
    delete p;
    p=NULL;
}

// 4: Hàm tìm công việc có thời gian hoàn thành cao nhất, nếu có cùng nhiều công việc như thế thì return người tên Dung NGUYEN
void timMaxTime(NODE *list)
{
    NODE *p=list;
    int maxTime=0;
    NODE *max=NULL;
    while (p!=NULL)
    {
        if (p->data.time>maxTime)
        {
            maxTime=p->data.time;
            max=p;
        }
        p=p->pNext;
    }
    // Kiểm tra xem danh sách có nhiều công việc cùng maxTime hay không?
    p=list;
    int d=0;
    while (p!=NULL)
    {
        if (p->data.time==maxTime)
        {
            d++;
        }
        p=p->pNext;
    }
    
    // Nếu chỉ có 1 người thì return công việc đó
    if (d==1)
    {
        // Xuất thông tin 
        output(max);
    }
    else
    {
        p=list;
        while (p!=NULL)
        {
            if (p->data.time==maxTime )
            {
                if (strcmp(p->data.tenNTH,"Dung NGUYEN")==0)
                {
                    output(p);
                    return;
                }
            }
            p=p->pNext;
        }

        // Khi chương trinhg đi đến đoạn này tức là không có công việc nào có thời gian hoàn thành cao nhất do người tên Dung NGUYEN thực hiện
        // Khi đó trả về một công việc có thời gian hoàn thành cao nhất bất kì
        output(max);
    }
}

// 5: Hàm reset thời gian hoàn thành của các công việc >300 phút thành 300 phút
void resetTime(NODE *&list)
{
    NODE *p=list;
    while (p!=NULL)
    {
        if (p->data.time>300)
        {
            p->data.time=300;
        }
        p=p->pNext;
    }
}

// 6: Tính tổng thời gian các công việc của người tên X, X là tên mình
void calTime(NODE *list)
{
    char name[M]="Bui Thi Thanh Ngan";
    int sumTime=0;
    NODE *p=list;
    while (p!=NULL)
    {
        if (strcmp(p->data.tenNTH,name)==0)
        {
            sumTime+=p->data.time;
        }
        p=p->pNext;
    }
    cout<<"Tong thoi gian hoan thanh cac cong viec cua "<<name<<" la: "<<sumTime<<endl;
}

// 7: Hàm sắp xếp danh sách công việc theo độ ưu tiên từ cao đến thấp tính từ đầu danh sách
void sapXep(NODE *&list)
{
    for (NODE *p=list;p!=NULL;p=p->pNext)
    {
        for (NODE *q=p->pNext;q!=NULL;q=q->pNext)
        {
            // Gía trị độ ưu tiên nhỏ hơn thì độ ưu tiên cao hơn
            if (p->data.priority>q->data.priority)
            {
                //  Hoán đổi dữ liệu hai node
                CongViec temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}

// 8: Ghi tất cả thông tin của các công việc có độ ưu tiên cao nhất ra tập tin nhị phân output1.bin
void ghiFile(NODE *list)
{
    ofstream fout;
    fout.open("output1.bin",ios::out|ios::binary);
    sapXep(list);
    int maxPri=list->data.priority;
    // Nếu có nhiều công việc có độ ưu tiên cao nhất băng nhau thì ghi ra các công việc đó
    NODE *p=list;
    while (p!=NULL)
    {
        if (p->data.priority==maxPri)
        {
            //  Ghi vào file
            fout.write((char*) p,sizeof(CongViec));
        }
        p=p->pNext;
    }
    fout.close();
}

// 9: Hàm đọc thông tin từ tập tin output1.bin và tạo danh sách mới từ thông tin đọc, xuất danh sách 
void docFile(NODE *&listMaxPri)
{
    // khởi tạo danh sách rỗng
    khoiTao(listMaxPri);

    ifstream fin;
    fin.open("output1.bin",ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout<<"\nMo file that bai...\n";
        exit(225);
    }
    while (!fin.eof())
    {
        NODE *temp=new NODE;
        fin.read((char *) temp,sizeof(CongViec));
        temp->pNext=NULL;
        if (listMaxPri==NULL)
        {
            // Thêm vào đầu danh sách
            listMaxPri=temp;
        }
        else
        {
            // Thêm vào cuối danh sách 
            NODE *p=listMaxPri;
            while (p->pNext!=NULL)
            {
                p=p->pNext;
            }
            p->pNext=temp;
        }
    }
    outputList(listMaxPri);
}

// Hàm làm rỗng danh sách và giải phóng bộ nhớ
void delList(NODE *&list)
{
    NODE *p=list;
    while (p!=NULL)
    {
        list=list->pNext;
        // Giải phóng cho vùng nhớ đã cấp phát động
        delete[] p->data.tenCV;     
        delete[] p->data.tenNTH;

        delete p;
        p=list;
    }
}
// 10: Viết hàm main sử dụng menu lựa chọn 
