#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout << "\nEnter data to be inserted or type -1 : ";
    cin >> data;

    if (data == -1)
        return 0;

    tree->data = data;

    cout << "Enter left child of " << data;
    tree->left = create();

    cout << "Enter right child of " << data;
    tree->right = create();

    return tree;
}

vector<int> v;
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "  ";
    // To store the data.
    v.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

Node *Balanced_BST(int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *root = new Node;
    root->data = v[mid];
    root->left = Balanced_BST(start, mid - 1);
    root->right = Balanced_BST(mid + 1, end);

    return root;
}

int main()
{
    Node *root = NULL;
    root = create();

    cout << "Preorder traversal of the tree is : ";
    preorder(root);
    // We will sort the array to create the balanced BST.
    sort(v.begin(), v.end());
    root = Balanced_BST(0, v.size() - 1);

    cout << "\nPreorder traversal of the tree after balancing : ";
    preorder(root);

    return 0;
}