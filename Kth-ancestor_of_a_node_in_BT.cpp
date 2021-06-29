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

void printNode(vector<int> &path, int K)
{
    if (path[path.size() - K])
        cout << path[path.size() - K] << endl;
    else
        cout << "-1" << endl;
}

void Path(Node *root, int node, int K, vector<int> &path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    Path(root->right, node, K, path);
    Path(root->left, node, K, path);

    if (root->data == node)
    {
        printNode(path, K + 1);
        return;
    }

    path.pop_back();
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> path;
    int node = 4;
    int K = 2;
    cout << "Node at a distance of " << K << " from " << node << " is : ";
    Path(root, node, K, path);

    return 0;
}