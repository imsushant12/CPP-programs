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

class NodeInfo
{
public:
    int sum;
    int minimum;
    int maximum;
    int largestSum;
};

int LargestSumBT(Node *root, int sum)
{
    if (root == NULL)
        return 0;

    return max(sum, root->data + LargestSumBT(root->left, sum) + LargestSumBT(root->right, sum));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
    /*
    Tree Formed:
                1
             /    \
           -2     3
          / \    / \
         4  5  -6  2
    */
    int result = INT_MIN;
    cout << "Largest subtree sum is : " << LargestSumBT(root, result);

    return 0;
}