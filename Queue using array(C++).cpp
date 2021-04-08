#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *ptr;

public:
    /*Queue()
    {
        front=-1;
        rear=-1;
        capacity=10;
        ptr=new int [capacity];       //important
    }*/

    Queue(int cap)
    {
        front=-1;
        rear=-1;
        capacity=cap;
        ptr=new int [capacity];          //important
    }

    bool isEmpty()
    {
        if(front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if(rear == capacity-1)
            return true;
        return false;
    }

    void enQueue()
    {
        int data;
        if(isFull())
            cout<<"\nQueue is Full"<<endl;
        else
        {
            cout<<"\nEnter data to be inserted : ";
            cin>>data;
            rear++;
            ptr[rear]=data;
            if(front == -1)
                front++;
        }
    }

    void deQueue()
    {
        int data;
        if(isEmpty())
            cout<<"\nQueue is Empty"<<endl;
        else
        {
            data=ptr[front];
            cout<<endl<<data<<"  is deleted from Queue"<<endl;
            front++;
        }
    }

    void display()
    {
        int i;
        if(rear == front)
            cout<<"\nQueue is Empty"<<endl;
        else
        {
            for(i = front ; i <= rear ; i++)
                cout<<"Data = "<<ptr[i]<<endl;
        }
    }
};

int main()
{
    int cap,choice;

    cout<<"Enter the size or capacity of Queue : ";
    cin>>cap;

    Queue q(cap);

    while(1)
    {
        cout<<endl;
        cout<<"1. To enter data into queue."<<endl;
        cout<<"2. To delete data from queue."<<endl;
        cout<<"3. To display the data."<<endl;
        cout<<"4. TO EXIT."<<endl;

        cout<<"\nENTER YOUR CHOICE... : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            q.enQueue();
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE..."<<endl;
        }
    }
    return 0;
}
