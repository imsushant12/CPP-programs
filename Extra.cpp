#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
};

struct treenode* create(int data)
{
    struct treenode *newnode = new treenode;
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct treenode* insertion(struct treenode *root , int data)
{
    if(root ==  NULL)
    {
        root = create(data);
        return root;
    }

    else if(data < root->info)
        root->left = insertion(root->left , data);

    else
        root->right = insertion(root->right , data);

    return root;
}

//Traversing(Printing) the linked list
void printList(struct treenode* start)
{
    cout<<"\Merged List is = ";
    while(start)
    {
        cout << start->info <<"  ";
        start = start->right;
    }
}

// Function to insert a BST node at the starting of linked list
void push(struct treenode* root , struct treenode* &start)
{
    // insert the given node at the front of the DDL
    root->right = start;

    //left pointer of the existing start node to point to the BST node
    if(start != NULL)
        start->left = root;

    // update the start pointer of linked list
    start = root;
}

struct treenode* convert(struct treenode* root , struct treenode* &start)
{
    //Base condition
    if (root == NULL)
        return NULL;

    //converting the right subtree
    convert(root->right , start);

    //pushing the current node at the front of the linked list
    push(root , start);

    //converting the left subtree
    convert(root->left , start);
}

//function to merge two doubly linked list into one doubly linked list
struct treenode* merge(struct treenode* a, struct treenode* b)
{
    //no first list then returning second list
    if(a == NULL)
        return b;

    //no second list then returning first list
    if (b == NULL)
        return a;

    //checking which one is smaller
    if (a->info < b->info)
    {
        a->right = merge(a->right, b);
        a->right->left = a;

        return a;
    }

    //if second list is smaller
    else
    {
        b->right = merge(a, b->right);
        b->right->left = b;

        return b;
    }
}

// Function to merge the trees
struct treenode* mergedlist(struct treenode* a , struct treenode* b)
{
    //Converting tree-1 to linked list
    struct treenode* first = NULL;
    convert(a , first);

    //Converting tree-2 to linked list
    struct treenode* second = NULL;
    convert(b , second);

    // Merge both doubly linked lists
    return merge(first, second);
}

int main()
{

    struct treenode *a = NULL;

    /*
    Tree-1
          8
         /  \
        2    10
       /
      1
    */
    a = insertion(a , 8);
    a = insertion(a , 2);
    a = insertion(a , 1);
    a = insertion(a , 10);

    /*
    Tree-2
          5
         /  \
        3    6
       / \
      0   4
    */

    struct treenode *b = NULL;
    b = insertion(b , 5);
    b = insertion(b , 3);
    b = insertion(b , 0);
    b = insertion(b , 4);
    b = insertion(b , 6);

    //Now merging of both the linked list
    struct treenode* root = mergedlist(a , b);
    printList(root);

    return 0;

}
