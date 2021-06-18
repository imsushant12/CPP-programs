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
    int BSTsize;
    int minimum;
    int maximum;
    int largestBSTsize;
    bool isBST;
};

NodeInfo BSTinBT(Node *root)
{
    // Base Case, NULL node is a BST and its size is -> null and range is -> maimum and minimum.
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    // In case of leaf node, each node is itself a BST and its range is the root itself.
    if (root->left == NULL and root->right == NULL)
        return {1, root->data, root->data, 1, true};

    // Recursively calculating left and right subtree.
    NodeInfo leftInfo = BSTinBT(root->left);
    NodeInfo rightInfo = BSTinBT(root->right);

    NodeInfo current;

    // Size of the current node.
    current.BSTsize = (1 + leftInfo.BSTsize + rightInfo.BSTsize);

    // Checking if the left and right subtree is BST or not & Checking if the current node is also a BST or not.
    if ((leftInfo.isBST == true and rightInfo.isBST == true) and
        (leftInfo.maximum < root->data and rightInfo.minimum > root->data))
    {
        current.minimum = min(leftInfo.minimum, min(rightInfo.minimum, root->data));
        current.maximum = max(leftInfo.maximum, max(rightInfo.maximum, root->data));

        current.largestBSTsize = current.BSTsize;
        current.isBST = true;

        return current;
    }

    current.largestBSTsize = max(leftInfo.BSTsize, rightInfo.BSTsize);
    current.isBST = false;

    return current;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    /*
    Tree Formed:
        15
       / \
      20 30
      / 
    5
    */

    cout << "Largest BST in the Binary Tree is of size : " << BSTinBT(root).largestBSTsize;

    return 0;
}