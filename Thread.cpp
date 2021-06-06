#include <iostream>
#include <thread>
using namespace std;

void findSum(int x , int y)
{
    cout<<"Sum = "<<(x+y)<<endl;
}

void findDifference(int x , int y)
{
    cout<<"Difference = "<<(x-y)<<endl;
}

int main()
{
    //findSum(30 , 20);
    //findDifference(30 , 20);

    thread t1 (findSum , 30 , 20);
    thread t2 (findDifference , 30 , 20);
    t1.join();
    t2.join();

    return 0;
}
