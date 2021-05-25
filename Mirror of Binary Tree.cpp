#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
}root;

Node* createNode(int val)
{
    Node* newNode = new Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<"  ";
    inorder(root->right);
}

void mirror(Node* root , Node** mirrortree)
{
    if(root == NULL)
        return;

    *mirrortree  = createNode(root->val);
    mirror(root->left , &((*mirrortree)->right));
    mirror(root->right , &((*mirrortree)->left));
}

int main()
{

    Node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    cout<<"Inorder of original tree: ";
    inorder(tree);

    Node* mirrortree = NULL;
    mirror(tree , &mirrortree);

    cout<<"\nInorder of mirror tree: ";
    inorder(mirrortree);

    return 0;
}

