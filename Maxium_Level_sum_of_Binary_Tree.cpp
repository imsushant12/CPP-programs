#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    int info;
    struct treenode *left,*right;
};

treenode* create()
{
    int data;
    struct treenode *tree = new treenode;

    cout<<"\nEnter data to be inserted or type -1 for no insertion : ";
    cin>>data;

    if(data == -1)
        return 0;

    tree->info = data;
    cout<<"\nEnter left child of "<<data;
    tree->left = create();
    cout<<"\nEnter right child of "<<data;
    tree->right = create();

    return tree;
}

void maxLevelSum(treenode* root)
{
    queue <treenode *> q1, q2;

    q1.push(root);
    int final_level = 0 , level = 0;
    int sum = 0 , maxsum = 10;

    while(!q1.empty() || !q2.empty())
    {
        if(!q1.empty())
        {
            level++;
            sum = 0;

            while(!q1.empty())
            {
                treenode* temp = q1.front();
                q1.pop();S

                if(temp->left)
                    q2.push(temp->left);

                if(temp->right)
                    q2.push(temp->right);

                sum = sum + temp->info;
            }

            if(maxsum < sum)
            {
                maxsum = sum;
                final_level = level;
            }
        }

        if(!q2.empty())
        {
            level++;
            sum = 0;

            while(!q2.empty())
            {
                treenode* temp = q2.front();
                q2.pop();

                if(temp->left)
                    q1.push(temp->left);

                if(temp->right)
                    q1.push(temp->right);

                sum = sum + temp->info;
            }

            if(maxsum < sum)
            {
                maxsum = sum;
                final_level = level;
            }
        }
    }

    cout<<"Maximum sum = "<<maxsum<<endl;
    cout<<"Maximum level is : "<<final_level<<endl;
}

int main()
{
    struct treenode *root =  NULL;
    root = create();

    maxLevelSum(root);

    return 0;
}
