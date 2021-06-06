#include <bits/stdc++.h>
using namespace std;

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

void zigZag(Node *root)
{
    if(root == NULL)
        return;

    stack <Node*> s1 , s2;

	s1.push(root);
	bool flag = true;

	while(!s1.empty())
	{
		Node* temp = s1.top();
		s1.pop();

		if(temp)
		{
			cout<<temp->info<<"   ";

			if(flag == true)
			{
				if (temp->left)
					s2.push(temp->left);
				if (temp->right)
					s2.push(temp->right);
			}
			else
			{
				if(temp->right)
					s2.push(temp->right);
				if(temp->left)
					s2.push(temp->left);
			}
		}

		if (s1.empty())
		{
			flag = !flag;
			swap(s1 , s2);
		}
	}
}

int main()
{
    Node *root = NULL;
    root = create();

    cout<<"Zig-zag view of the tree is : ";
    zigZag(root);

    return 0;
}


