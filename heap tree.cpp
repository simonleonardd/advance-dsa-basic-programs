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

void Delete(int num)
{
	int l,r,i;
	int temp,p;
	for(i=0;i<n;i++)
	{
		if(num==arr[i])
		break;
	}
	if(num!=arr[i])
	{
		cout<<"\nElement Not Found";
		return;
	}
	arr[i]=arr[n-1];
	n=n-1;
	p=(i-1)/2;
	if(arr[i]>arr[p])
	{
		insert(arr[i],i);
		return;
	}
	l=2*i+1;;
	r=2*i+2;
	while(r<n)
	{
		if(arr[i]>=arr[l]&&arr[i]>=arr[r])
			return;
		if(arr[r]<=arr[l])
		{
			temp=arr[i];
			arr[i]=arr[l];
			arr[l]=temp;
			i=l;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[r];
			arr[r]=temp;
			i=r;
		}
		l=2*i+1;
		r=2*i+2;
	}	
	if(l=n-1&&arr[i]<arr[l])
		{
			temp=arr[i];
			arr[i]=arr[l];
			arr[l]=temp;
		}
	
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
	cout<<"NUll";
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
					cout<<"\n\tEnter the number to insert:";
					cin>>num;
					insert(num,n);
					n=n+1;
					break;
					
			case 2:
					display();
					break;
			
			case 3:
					cout<<"\n\tEnter the NUmber To Be Deleted :";
					cin>>num;
					Delete(num);
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
