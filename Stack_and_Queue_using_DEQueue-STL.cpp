#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;

    int choice, data;
    while (1)
    {
        cout << endl;
        cout << "1. To enter data into stack." << endl;
        cout << "2. To enter data into queue." << endl;
        cout << "3. To delete data from stack." << endl;
        cout << "4. To delete data from queue." << endl;
        cout << "5. To display the dequeue data." << endl;
        cout << "6. TO EXIT." << endl;

        cout << "\nENTER YOUR CHOICE... : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number to be inserted (STACK): ";
            cin >> data;
            d.push_front(data);
            break;

        case 2:
            cout << "\nEnter the number to be inserted (QUEUE) : ";
            cin >> data;
            d.push_back(data);
            break;

        case 3:
            cout << "\nDeleted element (STACK) : " << d.front();
            d.pop_front();
            break;

        case 4:
            cout << "\n Deleted element (QUEUE) : " << d.back();
            d.pop_back();
            break;

        case 5:
            for (auto i = d.begin(); i != d.end(); i++)
                cout << *i << "  ";
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\nINVALID CHOICE..." << endl;
        }
    }
}