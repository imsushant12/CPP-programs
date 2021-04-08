#include <bits/stdc++.h>
using namespace std;

int hashTable[10] = {0};
int SIZE = 10;

int hashIndex(int key)
{
    return (key % SIZE);
}

/*
// When space is not free in hash table then it will return next available space
int probe(int key)
{
    int index = hashIndex(key);
    int i=0;

    while(hashTable[(index+i) % SIZE] != 0)
        i++;

    return((index+i) % SIZE);
}
*/


void insertLinearProbing(int data)
{
    int index = hashIndex(data);

    if(hashTable[index] == 0)
        hashTable[index] = data;

    else
    {
        int i=0;
        while(hashTable[(index+i)%SIZE] != 0)
            i++;
        hashTable[(index+i) % SIZE] = data;
    }
}


int searchKey(int data)
{
    for(int i=0 ; i<SIZE ; i++)
    {
        int index = (data + i)%10;
        if(hashTable[index] == data)
            return index;
    }
    return -1;
}


int deleteKey(int data)
{
    for(int i=0 ; i<SIZE ; i++)
    {
        int index = (data + i)%10;
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
                insertLinearProbing(data);

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
