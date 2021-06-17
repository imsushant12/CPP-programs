// Median of BST in O(n) time and O(1) space.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key)
{
    if(node == NULL)
        return newNode(key);

    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int counter=0;
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    counter++;
    inorder(root->right);
}

int midCounter = 0;
void findMedianUtil(Node* root , int counter)
{
    if(root == NULL)
        return;
    findMedianUtil(root->left , counter);
    if(midCounter == counter)
    {
        cout<<root->data;
        midCounter++;
    }
    else
    {
        midCounter++;
    }
    findMedianUtil(root->right , counter);
}

void findMedian(Node* root)
{
    if(root == NULL)
        return;
    inorder(root);
    counter = counter/2;
    findMedianUtil(root , counter);
}

int main()
{
    /* 
    Let us create following BST
			  50
			/	 \
		   30	 70
		  /  \  /  \
		20  40 60  80 
    */
    struct Node *root = NULL;
    root = insert(root , 50);
    insert(root , 30);
    insert(root , 20);
    insert(root , 40);
    insert(root , 70);
    insert(root , 60);
    insert(root , 80);

    cout<<"\nMedian of the BST is ";
    findMedian(root);
    return 0;
}
