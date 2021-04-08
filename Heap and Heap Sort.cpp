#include <iostream>
#include <stdlib.h>
using namespace std;

//in place heap creation
void insert(int a[] , int n)
{
    int temp = a[n];
    int i = n;
    int parent = (i-1)/2;

    while(i>0 && temp > a[parent])
    {
        a[i] = a[parent];
        i = parent;
        parent = (i-1)/2;
    }
    a[i] = temp;
}

/*
OTHER WAY :
------------
void insert(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
*/

void createHeap(int a[] , int n)
{
    for(int i=1 ; i<n ; i++)
        insert(a , i);
}

void deleteHeap(int a[] , int n)
{
    int i=0 , j=0;
    int temp = a[n-1];
    int temp2 = a[0];
    a[i] = a[n-1];
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    while((temp < a[lchild] || temp < a[rchild]))
    {
        if(a[lchild] > a[rchild])
            j = lchild;
        else
            j = rchild;

        if(j < n)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        else
            break;

        temp = a[j];
        i = j;
        lchild = 2*i+1;
        rchild = 2*i+2;
    }
    a[n-1] = temp2;
}

void HeapSort(int a[] , int n)
{
    for(int i=(n/2)-1 ; i>=0 ; i--)
    {
        int j = 2*i+1;                 // Left child for current i-node
        while(j < n-1)
        {
            if(a[j] < a[j+1])
                j = j+1;

            if(a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                i = j;
                j = 2*i+1;
            }
            else
                break;
        }
    }
}


int main()
{
    int n,i,choice,data,m,k;
    int a[100];

    while(1)
    {
        cout<<endl;
        cout<<"1. To create heap"<<endl;
        cout<<"2. To insert an element"<<endl;
        cout<<"3. To delete element"<<endl;
        cout<<"4. To view the heap"<<endl;
        cout<<"5. View sorted data"<<endl;
        cout<<"6. Heap sort"<<endl;
        cout<<"7. Kth smallest element from max heap"<<endl;
        cout<<"8. Kth largest element from max heap"<<endl;
        cout<<"9. EXIT"<<endl;
        cout<<"ENTER CHOICE : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter the size of heap array : ";
                cin>>n;
                m=n;                        //for sorting purpose
                cout<<"\nEnter array : ";
                for(i=0 ; i<n ; i++)
                    cin>>a[i];
                createHeap(a , n);

                break;
            }

        case 2:
            {
                cout<<"\nEnter the element : ";
                cin>>data;
                a[n] = data;
                insert(a , n);
                n = n+1;

                break;
            }

        case 3:
            {
                deleteHeap(a , n);
                n=n-1;

                break;
            }

        case 4:
            {
                cout<<"\nHeap (level order-wise) : ";
                for(i=0 ; i<n ; i++)
                    cout<<a[i]<<"  ";
                cout<<endl;

                break;
            }

        case 5:
            {
                for(i=m ; i>0 ; i--)
                {
                    deleteHeap(a , i);
                    n = n-1;
                }
                cout<<"\nSorted data = ";
                for(i=0 ; i<m ; i++)
                    cout<<a[i]<<"  ";

                break;
            }

        case 6:
            {
                cout<<"\nEnter the size of heap array : ";
                cin>>n;
                                                    //for sorting purpose
                cout<<"\nEnter array : ";
                for(i=0 ; i<n ; i++)
                    cin>>a[i];
                HeapSort(a , n);

                break;
            }

        case 7:
            {
                cout<<"\nEnter the value of k : ";
                cin>>k;
                for(i=0 ; i<=k ; i++)
                {
                    deleteHeap(a , n);
                    n = n-1;
                }
                cout<<"\nKth smallest element from max heap = "<<a[0];

                break;
            }

        case 8:
            {
                cout<<"\nEnter the value of k : ";
                cin>>k;
                for(i=0 ; i<(k-1) ; i++)
                {
                    deleteHeap(a , n);
                    n = n-1;
                }
                cout<<"\nKth largest element from max heap = "<<a[0];

                break;
            }

        case 9:
            {
                exit(0);
                break;
            }

        default:
            cout<<"\nINVALID CHOICE"<<endl;
        }
    }

    return 0;
}
