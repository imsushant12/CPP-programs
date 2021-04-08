#include <bits/stdc++.h>
using namespace std;

int hashTable[10] = {0};
int SIZE = 10;

int hashIndex_h1(int key)
{
    return(key % SIZE);
}

int hashIndex_h2(int key)
{
    return(7 - (key % 7));
}


void insertDoubleHashing(int data)
{
    int i=0;
    int index = (hashIndex_h1(data) + i * hashIndex_h2(data)) % SIZE;

    if(hashTable[index] == 0)
        hashTable[index] = data;

    else
    {
        i=0;
        while(hashTable[(hashIndex_h1(data) + (i*hashIndex_h2(data))) % SIZE] != 0)
            i++;

        hashTable[(hashIndex_h1(data) + (i*hashIndex_h2(data))) % SIZE] = data;
    }
}


int searchKey(int data)
{
    for(int i=0 ; i<SIZE ; i++)
    {
        int index = (hashIndex_h1(data) + i * hashIndex_h2(data)) % SIZE;
        if(hashTable[index] == data)
            return index;
    }
    return -1;
}


int deleteKey(int data)
{
    for(int i=0 ; i<SIZE ; i++)
    {
        int index = (hashIndex_h1(data) + i * hashIndex_h2(data)) % SIZE;
        if(hashTable[index] == data)
        {
            hashTable[index] = 0;
            return 1;
        }
    }
    return 0;
}


int main()
{
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
                insertDoubleHashing(data);

                break;
            }

        case 2:
            {
                cout<<"Enter element : ";
                cin>>data;
                int result = searchKey(data);
                if(result == -1)
                    cout<<"Element not found"<<endl;
                else
                    cout<<"Element is found at index : "<<result<<endl;

                break;
            }

        case 3:
            {
                cout<<"Enter element : ";
                cin>>data;
                int result = deleteKey(data);
                if(result == 1)
                    cout<<"Element deleted"<<endl;
                else
                    cout<<"Element is not found"<<endl;

                break;
            }


        case 4:
            {
                cout<<"Hash Table formed is"<<endl;
                for(int i=0 ; i<SIZE ; i++)
                    cout<< i <<" --> "<<hashTable[i]<<endl;

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

