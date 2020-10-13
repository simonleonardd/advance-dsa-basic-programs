#include<iostream>
#include<stdlib.h>
using namespace std;
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
void preorder(struct node* root)
{
    if(root!=NULL)
    {
    cout<<(*root).data<<"  ->  ";
    preorder((*root).left);
    preorder((*root).right);
    }
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


int Height(struct node* root)
{
    if(root==NULL)
        return 0;
    int rh=Height((*root).right);
    int lh=Height((*root).left);
    
    if(lh>rh)
    	return lh+1;
    else
    	return rh+1;
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

void balance(struct node *root)
{
	node *temp1;
	temp1=(*root).data;
	(*root).left=balance(*root).left;
	(*root).right=balance(*root).right;
	}
}

void find_balanced(struct node *root)

{
	int i;
	int left=Height(root->left);
	int right=Height(root->right);
	if(left==right)
	{
		cout<<"\nIt is balanced";
		i=0;
	}
	else
	{
		cout<<"\nIt is not balanced";
		i=1;
	}
	if(i==1)
	{
		balance(root);
	}
}

int main()
{
	int rval,val;
	cout<<"\nEnter the root Node Value";
	cin>>rval;
	struct node *root=createNode(rval);
	while(1)
	{
		int choice;
		node *temp;
		cout<<"\n-----AVL tree-----";
		cout<<"\n 1.Insert a Node \n2.Display the node \n 3.Balance The Tree \n 4.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"Enter the value to be Inserted:";
					cin>>val;
					insertVal(root,val);
					break;
				
			case 2:
					cout<<"\n\n\t\t1.PostOrder Traversal\n\n\t\t";
                        postorder(root);
                	cout<<"\n\n\t\t2.InOrder Traversal\n\n\t\t";
                    	inorder(root);
                	cout<<"\n\n\t\t3.PreOrder Traversal\n\n\t\t";            //break;
                    	preorder(root);
					break;
					
			case 3:
					find_balanced(root);						
	}
}
}
