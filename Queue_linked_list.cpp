#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int info;
    node *next;
};

class Queue
{
private:
    node *rear;
    node *front;

public:
    Queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }

    // Queue cannot be full if it is implemented using linked list.

    void enQueue()
    {
        node *temp = new node; //temp is an object of class node
        //temp = new node;
        int data;

        cout << "\nEnter data to be inserted : ";
        cin >> data;

        temp->info = data;
        temp->next = NULL;

        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void deQueue()
    {
        int data;
        node *temp;

        temp = front;
        data = front->info; //temp->info

        front = front->next;

        delete temp;

        cout << endl
             << data << " has been deleted." << endl;
    }

    void display()
    {
        node *temp;
        temp = front;

        while (temp != NULL)
        {
            cout << endl
                 << "Data = " << temp->info;
            temp = temp->next;
        }
    }
};

int main()
{
    int choice;

    Queue queue;

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
