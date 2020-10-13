#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
    char data[50];
    struct node *left,*right;
}*root;

struct node* createNode(char val[])
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    (*newNode).left=NULL;
    (*newNode).right=NULL;
    strcpy((*newNode).data,val);
     return newNode;
}

struct node* insertname(struct node* root,char data[])
{
    if (root==NULL)
    {
        return createNode(data);
    }
    
    int x=strcmpi(data,((*root).data));
    if(x<0)
        (*root).left=insertname((*root).left,data);
    else
        (*root).right=insertname((*root).right,data);
    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
    inorder((*root).left);
    cout<<(*root).data<<"  ->  ";
    inorder((*root).right);
    }
}

int main()
{
    char val[50],rval[50];
    cout<<"\n\tEnter the Root Node Name : ";
    cin>>rval;
    struct node *root=createNode(rval);
    while(1)
    {
    int choice;
    	node *temp;
    	cout<<"\n\n\t\t----Binary Search Tree----";
   		 cout<<"\n\t\t1.Insert a Node ";
   		 cout<<"\n\t\t2.Display Tree ";
   		 cout<<"\nEnter the choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
            cout<<"\n\nEnter the Name to be inserted : ";
            cin>>val;
            insertname(root,val);
            break;
        case 2 :
            cout<<"\n\n\t\tBinary Search Tree Display : \n\n";
            cout<<"\n\n\t\t2.InOrder Traversal\n\n\t\t";
                    inorder(root);
            break;
	}
	
	}
}
