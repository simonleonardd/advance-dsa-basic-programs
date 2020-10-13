#include<iostream>
#include<stdlib.h>
using namespace std;
void treedisplay(struct node* root);

struct node
{
    int data;
    struct node *left,*right;
}*root;

struct node* createNode(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    (*newNode).left=NULL;
    (*newNode).right=NULL;
    (*newNode).data=val;
     return newNode;
}

struct node* insertVal(struct node* root,int data)
{
    if (root==NULL)
    {
        return createNode(data);
    }
    if(data<(*root).data)
        (*root).left=insertVal((*root).left,data);
    else if(data>(*root).data)
        (*root).right=insertVal((*root).right,data);
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
void postorder(struct node* root)
{
    if(root!=NULL)
    {
    postorder((*root).left);
    postorder((*root).right);
    cout<<(*root).data<<"  ->  ";
    }
}

void treedisplay(struct node* root)
{
		if(root!=NULL)
		{
			int  i=10,i1=10;
			for(int j=1;j<=i;j++)
			{
				cout<<"\t";
			}
			cout<<"\n"<<(*root).data;
			cout<<"\n"<<"/"<<"\\";
			treedisplay((*root).left);
			treedisplay((*root).right);
			--i;				
		}
		
}




int main()
{
    int val,rval;
    cout<<"\n\tEnter the Root Node Value : ";
    cin>>rval;
    struct node *root=createNode(rval);
while(1)
{
    int choice;
    node *temp;
    cout<<"\n\n\t\t----Binary Search Tree----";
    cout<<"\n\t\t1.Insert a Node ";
    cout<<"\n\t\t2.Display the tree";
    cout<<"\n\t\t3.Display the tree in tree structure";
	cout<<"\nEnter the choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
            cout<<"\n\nEnter the element to be inserted : ";
            cin>>val;
            insertVal(root,val);
            break;
            
        case 2 :
                    cout<<"\n\n\t\tInOrder Traversal\n\n\t\t";
                    inorder(root);
               	    break;
               	    
        case 3 :
        		cout<<"\n\n\t\t Tree in tree structure";
        		treedisplay(root);
        		break;
        default:
        			cout<<"Enter a valid input";
        			exit(0);
	}
}
}
