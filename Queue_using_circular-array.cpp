#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *queue;

public:
    Queue(int cap)
    {
        front = rear = -1;
        capacity = cap;
        queue = new int[capacity];
    }

    bool isEmpty()
    {
        if (rear == front)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % capacity == front)
            return true;
        return false;
    }

    void enQueue()
    {
        if (isFull())
            cout << "\nQueue is full." << endl;
        else
        {
            int data;
            cout << "\nEnter data to be inserted : ";
            cin >> data;

            if (rear == -1 and front == -1)
                front = 0;

            rear = (rear + 1) % capacity;
            queue[rear] = data;
        }
    }

    void deQueue()
    {
        if (isEmpty())
            cout << "\nQueue is empty." << endl;
        else
        {
            int data = queue[front];
            front = (front + 1) % capacity;
            cout << endl
                 << data << " is deleted from queue." << endl;
        }
    }

    void display()
    {
        int i;
        if (isEmpty())
            cout << "\nQueue is empty." << endl;
        else
        {
            cout << "\nElements in Circular Queue are: " << endl;

            for (i = front; i != rear; i = (i + 1) % capacity)
                cout << queue[i] << endl;
            cout << queue[rear] << endl;
        }
    }
};

int main()
{
    int choice, cap;

    cout << "Enter capacity of the queue : ";
    cin >> cap;

    Queue queue(cap);

    while (1)
    {
        cout << endl;
        cout << "1. To enter data into queue." << endl;
        cout << "2. To delete data from queue." << endl;
        cout << "3. To display the data." << endl;
        cout << "4. TO EXIT." << endl;

        cout << "\nENTER YOUR CHOICE... : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            queue.enQueue();
            break;

        case 2:
            queue.deQueue();
            break;

        case 3:
            queue.display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
    return 0;
}
