#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

unordered_map <Node *, int> dp;

int findSum(Node *root)
{
    if (root == NULL)
        return 0;

    if (dp[root])
        return dp[root];

    // Including the root of the tree then we have to skip
    // its children and consider its grand-children.
    int include = root->data;
    if (root->left)
    {
        include += findSum(root->left->left);
        include += findSum(root->left->right);
    }
    if (root->right)
    {
        include += findSum(root->right->left);
        include += findSum(root->right->right);
    }
    // When we are excluding the root node, then we will consider children.
    int exclude = findSum(root->left) + findSum(root->right);

    dp[root] = max(include, exclude);

    return dp[root];
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Maximum sum is : " << findSum(root);

    return 0;
}