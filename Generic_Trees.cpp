//by Sushant Gaurav

#include <bits/stdc++.h>
#include <map>
using namespace std;

map <int , int> HashMap;
map <int , int> :: iterator it;

struct treenode
{
    int info;
    struct treenode *first;
    struct treenode *next;
};


struct treenode* create(int data)
{
    struct treenode *root = new treenode;
    root->info = data;
    root->first = root->next = NULL;
}

//1-----------------------------------------------------------------------------------------------------------------------------------------------

void traverse(struct treenode *root)
{
    if(root == NULL)
        return;

    cout<<root->info<<" ";

    if(root->first)
        traverse(root->first);

    if(root->next)
        traverse(root->next);
}

//2-----------------------------------------------------------------------------------------------------------------------------------------------

void depth(struct treenode *root , int height)
{
    if(root == NULL)
        return ;

    if(root->first != NULL)
        HashMap[height] = root->info;

    if(root->first)
        depth(root->first,height+1);

    if(root->next)
        depth(root->next,height);
}

//3-----------------------------------------------------------------------------------------------------------------------------------------------

int nodesum(struct treenode *root)
{
    if(root == NULL)
        return 0;

    return (root->info + nodesum(root->first) + nodesum(root->next));
}

//4-----------------------------------------------------------------------------------------------------------------------------------------------

int siblings(struct treenode *root)
{
    int count=0;
    if(root == NULL)
        return 0;

    while(root)
    {
        count++;
        root = root->next;
    }
    return count;
}


int children(struct treenode *root)
{
    int count=0;
    if(root == NULL)
        return 0;

    root = root->first;

    while(root)
    {
        count++;
        root = root->next;
    }
    return count;
}


int main()
{
    int choice;

    struct treenode *root = create(10);
    root->first = create(20);
    root->first->next = create(30);
    root->first->next->first = create(60);
    root->first->next->next = create(40);
    root->first->next->next->next = create(50);
    root->first->next->next->next->first = create(70);
    root->first->next->next->next->first->next = create(80);
    root->first->next->next->next->first->next->next = create(90);
    root->first->next->next->next->first->next->next->first = create(100);

    while(1)
    {
        cout<<"\n1. Tree Traversal"<<endl;
        cout<<"2. Depth of the tree"<<endl;
        cout<<"3. Sum of elements"<<endl;
        cout<<"4. Number of siblings"<<endl;
        cout<<"5. Number of children"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                traverse(root);
                cout<<endl;
                break;

            case 2:
                depth(root,0);
                it = HashMap.end();
                cout<<"\nDepth = "<<it->second;
                cout<<endl<<it->first;
                break;

            case 3:
                cout<<"Sum of nodes = "<<nodesum(root)<<endl;
                break;

            case 4:
                cout<<"\nNumber of siblings = "<<siblings(root)<<endl;
                break;

            case 5:
                cout<<"\nNumber of children = "<<children(root)<<endl;
                break;

            case 6:
                exit(0);
                break;

            default:
                cout<<"\nINVALID CHOICE"<<endl;

        }
    }

    return 0;
}
