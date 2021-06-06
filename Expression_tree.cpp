//by Sushant Gaurav

#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct treenode
{
    char info;
    struct treenode *left;
    struct treenode *right;
};

struct treenode* create(char data)
{
    struct treenode *root = new treenode;
    root->info = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

struct treenode* preordercreate(vector <char> v , int &index)
{
    if( index == v.size() )
        return NULL;

    struct treenode *newnode = new treenode;
    newnode = create(v[index]);
    index++;

    if(v[index] == '+' || v[index] == '-' || v[index] == '*' || v[index] == '/')
    {
        newnode->left = preordercreate(v , index);
        newnode->right = preordercreate(v, index);
        return newnode;
    }
    else
    {
        return newnode;
    }

}

struct treenode* postordercreate(vector <char> v , int &index)
{
    if( index < 0 )
        return NULL;

    struct treenode *newnode = create(v[index]);
    index--;

    if(v[index] == '+' || v[index] == '-' || v[index] == '*' || v[index] == '/')
    {
        newnode->right = postordercreate(v, index);
        newnode->left = postordercreate(v , index);
    }
    return newnode;
}

void preorder(struct treenode *root)
{
    if(root == NULL)
        return;

    cout<<root->info<<"  ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    int choice,n;
    char data;

    vector <char> v1,v2;
    struct treenode *root = NULL;

    while(1)
    {
        cout<<"\n1. Create expression tree from pre-order"<<endl;
        cout<<"2. Create expression tree from post-order"<<endl;
        cout<<"3. Traverse the tree (pre-order)"<<endl;
        cout<<"4. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter the size of expression : ";
                cin>>n;
                cout<<"\nEnter the pre-order : ";
                for(int i=0 ; i<n ; i++)
                {
                    cin>>data;
                    v1.push_back(data);
                }
                n = 0;
                root = preordercreate(v1 , n);
                break;
            }

        case 2:
            {
                cout<<"\nEnter the size of expression : ";
                cin>>n;
                cout<<"\nEnter the post-order : ";
                for(int i=0 ; i<n ; i++)
                {
                    cin>>data;
                    v2.push_back(data);
                }
                n = n-1;
                root = postordercreate(v2 , n);
                break;
            }

        case 3:
            cout<<"\nPreorder order is : ";
            preorder(root);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE"<<endl;
        }
    }
}
