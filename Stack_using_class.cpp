#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *s;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->s = new int[size];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        return false;
    }

    void push(int data)
    {
        if (isFull())
            cout << "OverFlow Condition!" << endl;

        else if (top == -1)
        {
            top = 0;
            s[top] = data;
            cout << data << " is pushed into the stack." << endl;
        }

        else
        {
            top++;
            s[top] = data;
            cout << data << " is pushed into the stack." << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
            cout << "UnderFlow Condition!";
        cout << s[top--] << " is deleted or popped!" << endl;
    }

    void peek()
    {
        if (isEmpty())
            cout << "UnderFlow Condition!";
        cout << "\nElement at the top is : " << s[top] << endl;
    }

    void display()
    {
        if (isEmpty())
            cout << "UnderFlow Condition!" << endl;

        cout << "\nStack is : ";
        for (int i = 0; i <= top; i++)
            cout << s[i] << " ";
        cout << "\n\n";
    }
};

int main()
{
    int size;
    cout << "Enter the size of stack : ";
    cin >> size;

    Stack s(size);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.peek();
    s.display();
    s.pop();
    s.pop();
    s.peek();
    s.display();
    s.pop();
    s.display();

    return 0;
}