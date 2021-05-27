#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}

Node* rotateDLL(Node* head)
{

}

int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    Node* answer = rotateDLL(head);

    return 0;
}


