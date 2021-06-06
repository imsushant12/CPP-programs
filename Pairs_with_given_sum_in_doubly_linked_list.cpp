#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next , *prev;
};

void insertNode(struct Node **head , int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;

    if(!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void findPairSum(struct Node *head , int sum)
{
    struct Node *start = head;
    struct Node *last = head;

    while(last->next)
        last = last->next;

    while(start->next && last->prev)
    {
        if(start->data + last->data == sum)
        {
            cout<<"Pair sum is present : ("<<start->data<<" , "<<last->data<<")\n";
            start = start->next;
            last = last->prev;
        }

        else if(start->data + last->data > sum)
            last = last->prev;

        else
            start = start->next;
    }
}

int main()
{
    struct Node *head = NULL;
    insertNode(&head, 9);
    insertNode(&head, 8);
    insertNode(&head, 6);
    insertNode(&head, 5);
    insertNode(&head, 4);
    insertNode(&head, 2);
    insertNode(&head, 1);

    int sum = 15;

    findPairSum(head , sum);

    return 0;
}
