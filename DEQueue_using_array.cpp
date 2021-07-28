#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *ptr;

public:
    Queue(int cap)
    {
        front = rear = -1;
        capacity = cap;
        ptr = new int[capacity];
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if (rear == capacity - 1)
            return true;
        return false;
    }

    void enqueue_front()
    {
        int data;
        if (front == -1)
            cout << "\nQueue is Full." << endl;

        else
        {
            cout << "\nEnter data to be inserted : ";
            cin >> data;
            ptr[front] = data;
            front--;
        }
    }

    void enqueue_rear()
    {
        int data;
        if (isFull())
            cout << "\nQueue is Full." << endl;

        else
        {
            cout << "\nEnter data to be inserted : ";
            cin >> data;
            rear++;
            ptr[rear] = data;
        }
    }

    void dequeue_front()
    {
        int data;
        if (isEmpty())
            cout << "\nQueue is Empty." << endl;

        else
        {
            data = ptr[front];
            front++;
            cout << endl
                 << data << " is deleted from Queue." << endl;
        }
    }

    void dequeue_rear()
    {
        int data;
        if (rear == -1)
            cout << "\nQueue is Empty." << endl;

        else
        {
            data = ptr[rear];
            rear--;
            cout << endl
                 << data << " is deleted from Queue." << endl;
        }
    }

    void display()
    {
        int i;
        if (isEmpty())
            cout << "\nQueue is Empty." << endl;
        else
        {
            for (i = front + 1; i <= rear; i++)
                cout << "Data = " << ptr[i] << endl;
        }
    }
};

int main()
{
    int choice, cap;

    cout << "Enter the size or capacity of Queue : ";
    cin >> cap;

    Queue q(cap);

    while (1)
    {
        cout << endl;
        cout << "1. To enter data into queue from rear." << endl;
        cout << "2. To enter data into queue from front." << endl;
        cout << "3. To delete data from front." << endl;
        cout << "4. To delete data from rear." << endl;
        cout << "5. To display the data." << endl;
        cout << "6. TO EXIT." << endl;

        cout << "\nENTER YOUR CHOICE... : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.enqueue_rear();
            break;

        case 2:
            q.enqueue_front();
            break;

        case 3:
            q.dequeue_front();
            break;

        case 4:
            q.dequeue_rear();
            break;

        case 5:
            q.display();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
    return 0;
}
