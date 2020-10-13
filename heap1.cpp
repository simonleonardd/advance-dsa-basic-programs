#include<iostream>
#include<stdlib.h>
using namespace std;

int arr[100],n;

void insert(int num,int loc)
{
	int p;//p->parent
	while(loc>0)
	{
		p=(loc-1)/2;
		if(num<=arr[p])
		{
			arr[loc]=num;
			return;
		}
		arr[loc]=arr[p];
		loc=p;
	}
	arr[0]=num;
}

void Delete()
{
	int l,r,i;
	int temp,p;
	
	temp=arr[0];
	arr[0]=arr[n-1];
	//arr[n-1]='\0';
	
	l=2*i+1;
	r=2*i+2;
	if(arr[0]<arr[l]&&arr[l]>=arr[r])
		swap(arr[0],arr[l]);
	else if(arr[0]<arr[r]&&arr[r]>=arr[l])
		swap(arr[0],arr[r]);
}
void display()
{
	int i;
	if(n==0)
	{
		cout<<"\nHeap is Empty\n";
		return;
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i];
		cout<<"->";
	}
	
}
void display1()
{
	int i;
	if(n==0)
	{
		cout<<"\nHeap is Empty\n";
		return;
	}
	for(i=0;i<n-1;i++)
	{
		cout<<arr[i];
		cout<<"->";
	}
	
}

int main()
{
	int choice,num;
	n=0;
	while(1)
	{
		cout<<"\n\t\t1.Insert\n\t\t2.Display\n\t\t3.Delete\n\t\t4.Exit\n\t\tEnter your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
					int i,j;
					cout<<"\n\tEnter No.of.Elements to Be Inserted :";
					cin>>j;
					cout<<"\n\tEnter the Elements one by one :";
					for(i=0;i<j;i++)
					{
					cin>>num;
					insert(num,n);
					n=n+1;
					}
					break;
					
			case 2:
					display();
					break;
			
			case 3:
					Delete();
					display1();
					break;
			case 4:
					cout<<"\n*****PROGRAM ENDS*****";
					exit(0);
					break;
					
			default:
				cout<<"\nEnter a Valid Number";
		}
	}
	return 0;
}
