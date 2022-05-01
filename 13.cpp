#include <iostream>
using namespace std;

int vikhuan(int sogio,int socon)
{
    if (sogio==1)
    {
        return 2;
    }
    return 2*vikhuan(sogio-1,socon);
}
int main()
{

}