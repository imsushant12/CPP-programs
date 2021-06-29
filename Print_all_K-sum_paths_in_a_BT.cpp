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

void printPath(vector<int> &path , int start)
{
    for (int i = start; i < path.size(); i++)
    {
        cout << path[i] << "  ";
    }
    cout << endl;
}

void sumPath(Node *root, int K, vector<int> &path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);
    
    sumPath(root->right, K, path);
    sumPath(root->left, K, path);

    int sum = 0;
    for (int i = path.size()-1; i>=0 ;  i--)
    {
        sum += path[i];
        if (sum == K)
            printPath(path , i);
    }

    path.pop_back();
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    vector<int> path;
    int sum = 5;
    cout << "Sum paths are : \n";
    sumPath(root, sum, path);

    return 0;
}