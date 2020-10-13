#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int L=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if (l<n && arr[l]>arr[L])
        L=l;
    if (r<n && arr[r]>arr[L])
        L=r;
    if (L!=i)
    {
        swap(arr[i],arr[L]);
        heapify(arr,n,L);
    }
}

void print(int arr[],int n)
{
    cout<<"\n!@#$%^&*()_+\n";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n!@#$%^&*()_+\n";
    cout<<"\n";
}

void Delete1(int arr[],int &n)
{
    cout<<"Popping root:"<<arr[0]<<"\n";
    arr[0]=arr[n-1];
    n--;
    for (int i=(n/2)-1;i>=0;i--)
            heapify(arr,n,i);

}
int arr[100];

void tree(int arr[],int n)
{
    int j=n*10,in=n,p=0,index=0;

    while(n>=0)
    {
        for(int i=j;i>=0;i--)
            cout<<" ";
      
        for(int i=0;i<pow(2,p);i++)
        {
            if(index<in)
            {
                cout<<"         "<<arr[index];
               
                index++;
            }
        }
       
        cout<<"\n";
        
        n--;
        p++;
        j-=10;
    }
}

int main()
{
    int o,x,n=0;
    //int flag=0;
    //arr[0]=0;
    while(1)
    {
        cout<<"\n1.Insert\n2.Print\n3.Delete\n4.Exit\n\tEnter your option:";
        cin>>o;
        switch(o)
        {
            case 1:
                cout<<"\n\t\tEnter the element to be inserted:";
                cin>>arr[n];
                n++;
                //cout<<arr[flag];
                for (int i=(n/2)-1;i>=0;i--)
                    heapify(arr,n,i);
                break;
            case 2:
                //n=sizeof(arr)/sizeof(arr[0]);
                print(arr,n);
                tree(arr,n);
                break;
            case 4:
                exit(1);
            case 3:
                Delete1(arr,n);
        }
    }
    return 0;
}

