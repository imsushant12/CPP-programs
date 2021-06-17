#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printList(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << "  ";
        curr = curr->right;
    }
}

void flatenUtil(Node *root, Node* &dummy)
{
    if (root == NULL)
        return;
    flatenUtil(root->left, dummy);
    // simply making each node pointed by previous->right (dummy->right) 
    // and moving to next node its right node.
    dummy->left = NULL;
    dummy->right = root;
    dummy = root;
    flatenUtil(root->right, dummy);
}

Node* flaten(Node *root)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    flatenUtil(root, temp);
    root = dummy->right;
    delete dummy;

    return root;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Flaten Binary Tree as singly linked list : ";
    printList(flaten(root));

    return 0;
}
