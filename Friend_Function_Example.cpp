#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Box
{
private :
    int width;

public:
    void setwidth()
    {
        width = 20;
    }
    friend void printwidth(Box);
    // OR friend void printwidth(Box obj);
};

void printwidth(Box obj)
{
    cout<<"Width is = "<<obj.width<<endl;
}


int main()
{
    Box b;

    b.setwidth();
    printwidth(b);

    //ERROR -> b.printwidth(b);
    return 0;
}
