#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
    char data[50];
    int roll;
    struct node *left,*right;
}*root;

struct node* createNode(int roll,char val[])
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    (*newNode).left=NULL;
    (*newNode).right=NULL;
    strcpy((*newNode).data,val);
    (*newNode).roll=roll;
     return newNode;
}

struct node* insertname(struct node* root,int roll,char data[])
{
    if (root==NULL)
    {
        return createNode(roll,data);
    }
    
    int x=strcmpi(data,((*root).data));
    if(x<0)
        (*root).left=insertname((*root).left,roll,data);
    else
        (*root).right=insertname((*root).right,roll,data);
    return root;
}

struct node* insertroll(struct node* root,int roll,char data[])
{
    if (root==NULL)
    {
        return createNode(roll,data);
    }
    if(roll<(*root).roll)
        (*root).left=insertroll((*root).left,roll,data);
    else
        (*root).right=insertroll((*root).right,roll,data);
    return root;
}



void inorder(struct node* root)
{
    if(root!=NULL)
    {
    inorder((*root).left);
    cout<<(*root).data<<"\t"<<(*root).roll<<"  ->  ";
    inorder((*root).right);
    }
}

int main()
{
    char val[50],rval[50];
    int rroll,roll;
    cout<<"\n\tEnter the Root Node Name : ";
    cin>>rval;
    cout<<"\n\tEnter roll number of the root : ";
    cin>>rroll;
    struct node *root=createNode(rroll,rval);
    struct node *root1=createNode(rroll,rval);
    while(1)
    {
    int choice;
    	node *temp;
    	cout<<"\n\n\t\t----Binary Search Tree----";
   		 cout<<"\n\t\t1.Insert a Node ";
   		 cout<<"\n\t\t2.Display Tree ";
   		 cout<<"\n\t\t3.Exit ";
   		 cout<<"\nEnter the choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
            cout<<"\n\nEnter the Name to be inserted : ";
            cin>>val;
            cout<<"\n\nEnter the Roll number to be inserted : ";
            cin>>roll;
            insertname(root,roll,val);
            insertroll(root1,roll,val);
            break;
        case 2 :
        	cout<<"\nEnter 1 to sort the tree according to Name\n\t\tEnter 2 to sort it in roll number order\n\tEnter your choice : ";
        	int opt;
			cin>>opt;
            cout<<"\n\n\t\tBinary Search Tree Display : \n\n";
            cout<<"\n\n\t\t2.InOrder Traversal\n\n\t\t";
            if(opt==1)        
					inorder(root);
			else if(opt==2)
					inorder(root1);
			else
				cout<<"invalid option\n\n";
            break;
        case 3:
        	cout<<"***Progrm Terminated***\n\n";
        	exit(0);
        default:
        	cout<<"Invalid option..\n\n";
	}
	
	}
}
