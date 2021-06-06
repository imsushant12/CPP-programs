#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int isPrimeNumber(int n)
{
   bool isPrime = true;

   for(int i = 2; i <= n/2; i++)
   {
       if (n%i == 0)
       {
           isPrime = false;
           break;
       }
   }
   return isPrime;
}

int main(void)
{
   bool isPrime;
   int n=0,x=2;
   cin>>n;

   while(n!=0)
   {
       isPrime = isPrimeNumber(x);

       if(isPrime == true)
       {
            cout<<x<<endl;
            n--;
            x++;
       }
   }
   return 0;
}



/*
int main()
{
    int i=0,n=0,count=0,tests=0,x=2;

    cin>>n;
    while(tests<n)
    {
        for(i=1;i<=x;i++)
        {
            if(x%i==0)
                count++;
        }
        if(count==2)
        {
            cout<<x<<endl;
            tests++;
        }
        count=0;
        x++;
        i=1;
    }
    return 0;
}
*/
