#include<iostream>
#include<stdlib.h>
using namespace std;


struct node
{
    int data;
    struct node *left,*right;
}*root,*root1;



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


//void BalancedorNot(struct node* root,struct node* root1)


int main()
{
    int val,rval;
    cout<<"\n\tEnter the Root Node Value : ";
    cin>>rval;
    struct node *root=createNode(rval);
while(1)
{
    int choice,choice1;
    node *temp;
    cout<<"\n\n\t\t----Binary Search Tree----";
    cout<<"\n\t\t1.Insert a Node ";
    cout<<"\n\\t\t2.Second Tree";
   	cout<<"\nEnter the choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
            //temp = newnode;
            cout<<"\n\nEnter the element to be inserted : ";
            cin>>val;
            insertVal(root,val);
            //cout<<sizeof(node);
            break;
		case 2:
			cout<<"\n\t\t-----Binary Search Tree 2-----";
			cout<<"\n\t\t1.Insert a Node";
			cout<<"\n\t\t2.Display the Nodes";
			cout<<"\n \t\t3.Compare  with Previous Tree";
			cout<<"\n\n\t\tEnter your Choice :";
			cin>>choice1;
			switch(choice1)
			{
				case 1:
						cout<<"Enter the Element to be Inserted:";
						cin>>val;
						insertVal(root1,val);
						break;
				case 2:
						cout<<"In-Order Traversal:";
						inorder(root1);
						break;
						
			}
			
    }
}
return 0;
}
