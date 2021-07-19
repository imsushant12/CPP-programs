#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *rear;
    Node *next;

    Node()
    {
        rear = NULL;
    }

    //This function will check if the Queue is empty or not.
    bool isEmpty()
    {
        if (rear == NULL)
            return true;
        else
            return false;
    }

    //This function will insert elements into the Queue.
    void insertQueue(int item)
    {
        Node *temp = new Node;
        temp->data = item;

        if (isEmpty()) //If queue is empty.
        {
            rear = temp;
            temp->next = rear;
        }
        else
        {
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
    }

    //This function will return the front element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        return rear->next->data;
    }

    //This function will delete the front element of Queue.
    int deleteElement()
    {
        int item;
        Node *temp;

        if (isEmpty())
            return -1;

        else if (rear->next == rear) //If only one element is present
        {
            temp = rear;
            rear = NULL;
        }

        else
        {
            temp = rear->next;
            rear->next = rear->next->next;
        }

        item = temp->data;
        delete temp;
        return item;
    }
    //This function will display elements of Queue
    void display()
    {
        Node *temp;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue formed : ";

        temp = rear->next;
        do
        {
            cout << temp->data << "  ";
            temp = temp->next;

        } while (temp != rear->next);
    }
};

int main()
{
    Node q;
    int choice, item;
    while (1)
    {
        cout << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the element to be inserted : ";
            cin >> item;
            q.insertQueue(item);

            break;
        }

        case 2:
        {
            int answer = q.deleteElement();
            if (answer == -1)
                cout << "\nQueue is empty.";
            else
                cout << "\nDeleted element : " << answer;

            break;
        }

        case 3:
        {
            if (q.peek() == -1)
                cout << "\nQueue is empty." << endl;
            else
                cout << "\nItem at the front of queue is : " << q.peek();

            break;
        }

        case 4:
            q.display();
            break;

        case 5:
            exit(0);

        default:
            cout << "IVALID CHOICE!";
        }
    }
}

/*
    Time Complexity:
    Insertion -  O(1)
    Deletion -   O(n)
    Peek -       O(1)
    isEmpty -    O(1)

    Test Cases:
    (1.) Output:

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 10

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 20

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 30

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 3
    Item at the front of queue is : 10
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 4
    Queue formed : 10  20  30
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 5

    (2.) Output:

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 50

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 78

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 3
    Item at the front of queue is : 50
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 4
    Queue formed : 50  78
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 5
*/
