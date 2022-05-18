#include <iostream>
#pragma pack(2)
using namespace std;

typedef struct 
{
    char signature[2];
    int fsize;
    int reserved;
    int data;
} HEADER;

typedef struct 
{
    int fsize;
    int reserved;
    int data;
} header;

int main()
{
    HEADER image;
    cout<<"size of HEADER: "<<sizeof(HEADER)<<endl;
    cout<<"size of header: "<<sizeof(header)<<endl;
    return 225;
}