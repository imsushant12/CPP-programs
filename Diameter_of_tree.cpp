#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

pair <int,int> utilityDia(struct node* root)
{
    pair <int , int> p,lt,rt,answer;

    // first --> height
    // second --> diameter

    if(root == NULL)
    {
        p.first = -1;
        p.second = 0;
        return p;
    }

    lt = utilityDia(root->left);
    rt = utilityDia(root->right);

    //storing resultant height.
    answer.first = max(lt.first , rt.first) + 1;

    // passing through root
    int dia = lt.first + rt.first + 2;

    answer.second = max(dia, max(lt.second , rt.second));

    return answer;
}

int diameter(struct node* root)
{
    return (utilityDia(root).second + 1);
}

int height(struct node* root)
{
    return (utilityDia(root).first + 1);
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    /*root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left ->left = newNode(7);
    root->right->left ->right = newNode(8);*/

    cout<<"Diameter of the given binary tree is "<<diameter(root);
    cout<<"\nHeight of the given binary tree is "<<height(root);
    return 0;
}
