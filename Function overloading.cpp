#include <iostream>
using namespace std;

class Sumofnos
{
public:

    int sum(int a,int b)
    {
        return (a+b);
    }

    float sum(float a,float b)
    {
        return (a+b);
    }
};

int main()
{
    Sumofnos s;
    cout<<"Sum = "<<s.sum(10,20)<<endl;
    cout<<"Sum = "<<s.sum(10.5F,20.5F)<<endl;
    return 0;
}
