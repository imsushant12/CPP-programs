#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insert(int key)
{
    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = head;
    head = newNode;
}

void display()
{
    Node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
}
Node* addOne()
{
    Node *temp = head;

    string s;
    int i = 0;

    while(temp->next != NULL)
    {
        int a = temp->data;
        s.insert(i++ , to_string(a));
        temp = temp->next;
    }
    int a = temp->data;
    s.insert(i++ , to_string(a));
    stringstream geek(s);

    int x = 0;
    geek >> x;

    temp->data = x+1;
    temp->next = NULL;

    free(head);
    head = temp;
}

int main()
{
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);

    cout<<"The linked list is: ";
    display();

    addOne();

    cout<<"\nThe updated linked list after adding 1 to a number represented as linked list : ";
    display();
    cout<<endl;

    return 0;
}


