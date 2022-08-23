/*
Đầu ra của chương trình sau là gi?
#include <iostream>
using namespace std;
void duplicate(int& a, int& b, int& c){
a *= 2;
b *= 2;
c *= 2;
}
int main(){
int x = 1, y = 3, z = 7;
duplicate(x, y, z);
cout << x << y << z;
return 0;
}
a. 2 5 10
b. 2 4 5
c. 2 6 14
d. Tất cả các câu trên đều sai


=>Chọn C: Hàm sử dụng tham chiếu , các thao tác trên hàm sẽ cho ra kết quả được lưu lại sau khi thực hiện hàm */