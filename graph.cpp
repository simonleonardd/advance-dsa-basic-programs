#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10];
int i,j,k,n;
int qu[10],stk[10];
int front,rare,v,top;
int visit[10],visited[10];

void BFS()
{
	cout<<"*****BFS*****";
	cout <<"enter initial vertex";
    cin >>v;
    cout <<"Visitied vertices\n";
    cout << v<<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        v=qu[front++];
        cout<<v << " ";
        k++;
        visit[v]=0; 
		visited[v]=1;
	}
}

void DFS()
{
	cout<<"*****DFS******";
	cout <<"enter initial vertex";
    cin >>v;
    cout <<"ORDER OF VISITED VERTICES";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n;j>=1;j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
		visited[v]=1;
	}
}

int main()
{
	int m,n;
    cout <<"\nEnter no of vertices:";
    cin >> n;
    cout <<"\nEnter no of edges:";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1;k<=m;k++)
    {
    	cout<<"Enter"<<k<<"adjacent Values";
        cin >>i>>j;
        cost[i][j]=1;
    }
    while(1)
    {
    	cout<<"\n\tOPTIONS:\n\t1.BFS\n\t2.DFS\n\t3.Exit\n\tEnter Your Choice:";
    	int Choice;
    	cin>>Choice;
    	switch(Choice)
    	{
    		case 1: BFS();
    				break;
    		case 2: DFS();
    				break;
    		case 3:
    			cout<<"*********Program Terminated*************";
    			exit(0);
    			break;
		}
	}
	return 0;
}

