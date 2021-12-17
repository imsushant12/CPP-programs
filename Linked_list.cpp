#include <bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node *link;
};
node *start = NULL;

void traverse()
{
    node *temp;
    if (start == NULL)
        cout << "\nList is empty" << endl;
    else
    {
        temp = start;
        while (temp != NULL)
        {
            cout << "Data = " << temp->info;
            temp = temp->link;
        }
    }
}

void insetatfirst()
{
    int data;
    node *temp = new node;
    cout << "\nEnter number to be inserted : ";
    cin >> data;
    temp->info = data;
    temp->link = start; // pointer of temp will be assigned to start
    start = temp;
}

void insertatend()
{
    int data;
    node *temp, *head;
    temp = new node;
    cout << "\nEnter number to be inserted : ";
    cin >> data;
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertposition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = new node;
    cout << "\nEnter position and data :";
    cin >> pos >> data;
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deletefirst()
{
    node *temp;
    if (start == NULL)
        cout << "\nList is empty" << endl;
    else
    {
        temp = start;
        start = start->link;
        delete temp;
    }
}

void deleteend()
{
    node *temp, *prevnode;
    if (start == NULL)
        cout << "\nList is empty" << endl;
    else
    {
        temp = start;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        delete temp;
        prevnode->link = 0;
    }
}

void deleteposition()
{
    node *temp, *position;
    int i = 1, pos;
    if (start == NULL)
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nEnter index : ";
        cin >> pos;
        position = new node;
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        delete position;
    }
}

void maximum()
{
    int a[10];
    int i;
    struct node *temp;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        temp = start;
        int max = temp->info;
        while (temp != NULL)
        {
            if (max < temp->info)
                max = temp->info;
            temp = temp->link;
        }
        cout << "\nMaximum number is :" << max;
    }
}

void mean()
{
    int a[10];
    int i;
    node *temp;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        temp = start;
        int sum = 0, count = 0;
        float m;
        while (temp != NULL)
        {
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }
        m = sum / count;
        cout << "\nMean is :" << m;
    }
}

void swap()
{
    node *temp, *position;
    int i = 0, pos, z;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        cout << "\nEnter index ";
        cin >> pos;
        temp = start;
        while (i < pos)
        {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        z = temp->info;
        temp->info = position->info;
        position->info = z;
    }
}

void sort()
{
    node *current = start, *index = NULL;
    int temp;
    if (start == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->link;
            while (index != NULL)
            {
                if (current->info > index->info)
                {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            current = current->link;
        }
    }
}

void concatenate(node *start, node *start2) // will pass start pointer of both linked list
{
    if (start == NULL & start2 == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        node *temp = NULL;
        temp = start;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = start2;
    }
}

void singletocircular()
{
    node *temp, *last;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        temp = start;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = start;
        last = temp;
    }
}

void reversal()
{
    node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        while (start != NULL)
        {
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        temp = start;
        cout << "Reversed linked list is : ";
        while (temp != NULL)
        {
            cout << temp->info;
            temp = temp->link;
        }
    }
}

int search(int data)
{
    node *temp;
    if (start == NULL)
        cout << "\nList is empty." << endl;
    else
    {
        temp = start;
        while (temp != NULL)
        {
            if (temp->info == data)
                return 1;
            temp = temp->link;
        }
    }
    return 0;
}

int main()
{
    int choice, data;
    while (1)
    {

        cout << "\n\t1  To see list" << endl;
        cout << "\t2  For insertion at starting" << endl;
        cout << "\t3  For insertion at end" << endl;
        cout << "\t4  For insertion at any position" << endl;
        cout << "\t5  For deletion of first element" << endl;
        cout << "\t6  For deletion of last element" << endl;
        cout << "\t7  For deletion of element at any position" << endl;
        cout << "\t8  To find maximum among the elements" << endl;
        cout << "\t9  To find mean of the elements" << endl;
        cout << "\t10 To swap element" << endl;
        cout << "\t11 To sort element" << endl;
        cout << "\t12 To concatenate two strings,pass start address of both the linked list" << endl;
        cout << "\t13 To covert singly linked list into circular list" << endl;
        cout << "\t14 To reverse the linked list" << endl;
        cout << "\t15 To search an element" << endl;
        cout << "\t16 To exit" << endl;
        cout << "\nEnter Choice :" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insetatfirst();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertposition();
            break;
        case 5:
            deletefirst();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deleteposition();
            break;
        case 8:
            maximum();
            break;
        case 9:
            mean();
            break;
        case 10:
            swap();
            break;
        case 11:
            sort();
            break;
        case 12:
            concatenate(NULL, NULL);
            break;
        case 13:
            singletocircular();
            break;
        case 14:
            reversal();
            break;
        case 15:
            cout << "\nEnter element to search : ";
            cin >> data;
            if (search(data) == 1)
                cout << "\nElement is found.";
            else
                cout << "\nElement is not found.";
            break;
        case 16:
            exit(0);
        default:
            cout << "Incorrect Choice" << endl;
        }
    }
    return 0;
}