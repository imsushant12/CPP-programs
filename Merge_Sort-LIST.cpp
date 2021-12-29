#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
public:
    Node *head;
    Node *tail;
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
    }

    void printList()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *midNode(Node *head, Node *tail)
    {
        Node *fast = head;
        Node *slow = head;

        while (fast != tail and fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Linkedlist merge(Linkedlist firstList, Linkedlist secondList)
    {
        Node *head1 = firstList.head;
        Node *head2 = secondList.head;

        Linkedlist answerList;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                answerList.insertNode(head1->data);
                head1 = head1->next;
            }
            else
            {
                answerList.insertNode(head2->data);
                head2 = head2->next;
            }
        }

        // if any remaining element is there.
        while (head1 != NULL)
        {
            answerList.insertNode(head1->data);
            head1 = head1->next;
        }
        while (head2 != NULL)
        {
            answerList.insertNode(head2->data);
            head2 = head2->next;
        }

        return answerList;
    }

    Linkedlist mergeSort(Node *head, Node *tail)
    {
        if (head == tail)
        {
            Linkedlist currentList;
            currentList.insertNode(head->data);
            return currentList;
        }

        Node *mid = midNode(head, tail);

        Linkedlist firstHalf = mergeSort(head, mid);
        Linkedlist secondHalf = mergeSort(mid->next, tail);

        Linkedlist completeList = merge(firstHalf, secondHalf);

        return completeList;
    }
};

int main()
{
    Linkedlist list;

    list.insertNode(5);
    list.insertNode(2);
    list.insertNode(1);
    list.insertNode(4);
    list.insertNode(3);

    cout << "Original List: ";
    list.printList();

    list = list.mergeSort(list.head, list.tail);
    cout << "Sorted List: ";
    list.printList();

    return 0;
}

