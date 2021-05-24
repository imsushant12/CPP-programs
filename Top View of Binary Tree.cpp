#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> um;

struct Node
{
    int info;
    struct Node *left, *right;
};

struct Node* create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout << "\nEnter data to be inserted or type -1 : ";
    cin >> data;

    if(data == -1)
        return 0;

    tree->info = data;

    cout << "Enter left child of " << data;
    tree->left = create();

    cout << "Enter right child of " << data;
    tree->right = create();

    return tree;
};

void topView(Node *root, int level)
{
    if(root == NULL)
        return;

    int i = um.count(level);

    if(i == 0)
        um[level] = root->info;

    topView(root->left, level-1);
    topView(root->right, level+1);

    um[level] = root->info;

    return;
}

int main()
{
    Node *root = NULL;
    root = create();

    topView(root, 0);

    for(auto x : um)
        cout<<x.first<<" --> "<<x.second<<endl;

    return 0;
}


