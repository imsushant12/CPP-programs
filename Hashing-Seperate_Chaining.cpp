#include <bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;

class Chaining
{
private:
    list <int> hashTable[10];
    int SIZE;

public:
    list <int> :: iterator it;

    Chaining()
    {
        SIZE = 10;
    }

    int hashIndex(int data)
    {
        return (data % SIZE);
    }

    int insertChaining(int data)
    {
        int index = hashIndex(data);
        hashTable[index].push_back(data);
        hashTable[index].sort();
    }

    bool searchKey(int data)
    {
        int index = hashIndex(data);

        for(auto i : hashTable[index])
            if(i == data)
                return true;

        return false;
    }

    bool deleteKey(int data)
    {
        int index = hashIndex(data);

        for(it = hashTable[index].begin() ; it != hashTable[index].end() ; it++)
            if(*it == data)
                break;

        if(it != hashTable[index].end())
        {
            hashTable[index].erase(it);
            return true;
        }

        return false;
    }

    void displayTable()
    {
        for(int i=0 ; i<SIZE ; i++)
        {
            cout << i;
            for (auto x : hashTable[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main()
{
    Chaining c;
    int choice,data;

    while(1)
    {
        cout<<"\n1.Insert \t 2.Search \t 3.Delete \t 4.Display table \t 5.EXIT"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                cout<<"Enter element : ";
                cin>>data;
                c.insertChaining(data);

                break;
            }

        case 2:
            {
                cout<<"Enter element : ";
                cin>>data;

                bool result = c.searchKey(data);

                if(result)
                    cout<<"Element is found"<<endl;
                else
                    cout<<"Element not found"<<endl;

                break;
            }

        case 3:
            {
                cout<<"Enter element : ";
                cin>>data;

                bool result = c.deleteKey(data);

                if(result)
                    cout<<"Element deleted"<<endl;
                else
                    cout<<"Element not found"<<endl;

                break;
            }


        case 4:
            {
                cout<<"Hash Table formed is"<<endl;
                c.displayTable();
                break;
            }

        case 5:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE\n";
        }
    }
    return 0;
}
