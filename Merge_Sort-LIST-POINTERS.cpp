#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist
{
public:
	Node *head;
	Node *tail;
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
	}

	void insertNode(int data)
	{
		Node *newNode = new Node(data);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			return;
		}

		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		tail = newNode;
	}

	void printList()
	{
		Node *temp = head;

		if (head == NULL)
		{
			cout << "List is empty!" << endl;
			return;
		}

		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	void midNode(Node *current, Node **first, Node **second)
	{
		Node *slow = current;
		Node *fast = current->next;

		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*first = current;
		*second = slow->next;
		slow->next = NULL;
	}

	Node *merge(Node *firstList, Node *secondList)
	{
		Node *answerList = NULL;

		if (!firstList)
			return secondList;
			
		else if (!secondList)
			return firstList;

		if (firstList->data <= secondList->data)
		{
			answerList = firstList;
			answerList->next = merge(firstList->next, secondList);
		}
		else
		{
			answerList = secondList;
			answerList->next = merge(firstList, secondList->next);
		}
		return answerList;
	}

	void mergeSort(Node **head)
	{
		Node *current = *head;
		Node *first;
		Node *second;

		if (!current || !current->next)
			return;

		midNode(current, &first, &second);

		mergeSort(&first);
		mergeSort(&second);

		*head = merge(first, second);
	}
};

int main()
{
	Linkedlist list;

	list.insertNode(5);
	list.insertNode(2);
	list.insertNode(1);
	list.insertNode(4);
	list.insertNode(3);

	cout << "Original List: ";
	list.printList();

	list.mergeSort(&list.head);
	cout << "Sorted list: ";
	list.printList();

	return 0;
}