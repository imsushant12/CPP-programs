#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int index = 0;
Node* treeFromString(string s)
{
    if(s.size() == 0 or index >= s.size())
        return NULL;

    // Since root number or any number may be greater than
    // 9. So, we must consider whole number. Hence, we will
    // run a loop to get whole number.
    int number = 0;
    while(s[index] != '(' and s[index] != ')' and index < s.size())
    {
        int digit = (int)(s[index] - '0');
        number = number * 10 + digit;
        index++;
    }

    // creating node with the number formed.
    Node *root = newNode(number);

    // termination condition
    if(index >= s.size())
        return root;

    // constructing left sub-tree.
    if(s[index] == '(')
    {
        index++;
        root->left = treeFromString(s);
    }

    if(s[index] == ')')
    {
        index++;
        return root;
    }

    // constructing right sub-tree.
    if(s[index] == '(')
    {
        index++;
        root->right = treeFromString(s);
    }
    if(s[index] == ')' )
    {
        index++;
        return root;
    }

    return root;
}


int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str);
    preOrder(root);
}

/*
Time complexity = O(N)
Space Complexity = O(1)
*/
