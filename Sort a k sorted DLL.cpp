#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next, *prev;
};

void insert(struct Node** head, int data)
{
    Node* temp = new Node;

    temp->data = data;
    temp->next = temp->prev = NULL;

    if((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void printList(struct Node* head)
{
    if(head == NULL)
        return;

    while(head != NULL)
    {
        cout<<head->data<<"  ";
        head = head->next;
    }
}

struct compare
{
    bool operator()(Node* p1 , Node* p2)
    {
        return p1->data > p2->data;
    }
};

Node* sortKDLL(Node* head , int k)
{
    if(head == NULL)
        return head;

    priority_queue <Node* , vector<Node*> , compare> pq;

    Node* newHead = NULL , *last;

    for(int i=0 ; head != NULL && i<=k ; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while(!pq.empty())
    {
        if(newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }

        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if(head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return newHead;
}

int main()
{
    Node* head = NULL;

    insert(&head, 8);
    insert(&head, 56);
    insert(&head, 12);
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 3);

    cout<<"Initially DLL is : ";
    printList(head);

    int k = 2;
    Node *answer = sortKDLL(head , k);

    cout<<"\n\nDLL after sorting is : ";
    printList(answer);

    return 0;
}
