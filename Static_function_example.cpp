#include<iostream>
using namespace std;
class staticfunction
{
    static int count;     // count has become static so initialized to 0.
public:
    static void setcount()  //set-count is also a static function.
    {
        count++;
    }
    void displaycount()
    {
        cout<<count;
    }
};
int staticfunction::count=10;   //it must be used with use of scope resolution operator.
int main()
{
    staticfunction o1;
    o1.setcount();    // it will increment count to 11.
    staticfunction::setcount();   //it will increment count to 12. also setcount is used with scope resolution operator
    o1.displaycount();
    return 0;
}
