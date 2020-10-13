#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
	int height;
}*root;

struct node* Create(int d)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	(*root).left=NULL;
	(*root).right=NULL;
	(*root).data=d;
	
	return n;
}

struct node* Rrotate(struct node *root)
{
	struct node *x=(*root).left;
	struct node *y=(*x).right;
	(*x).right=root;
	if((*y).data<(*root).data)
		(*root).left=y;
	else if((*y).data>(*root).data)
		(*root).right=y;
	
	root=x;
	return root;
}

struct node* Lrotate(struct node *root)
{
	struct node *x=(*root).right;
	struct node *y=(*x).left;
	(*x).left=root;
	if((*y).data<(*root).data)
		(*root).left=y;
	else if((*y).data>(*root).data)
		(*root).right=y;
	
	root=x;	
	return root;
}

int max(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
	int rh=max((*root).right);
	int lh=max((*root).left);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}

struct node* Insert(struct node* root,int d)
{
	if(d<(*root).data)
		(*root).left=Insert((*root).left,d);
	else
		(*root).right=Insert((*root).right,d);
	return root;
}

struct node* Balance(struct  node* root)
{
	(*root).height=1+max(root->left->height,root->right->height);	
	int bf;
	bf=(root->left->height-root->right->height);
	
	if((bf>1)&&(root->data<root->left->data))
		return Rrotate(root);
	else if((bf<-1)&&(root->data>root->right->data))
		return Lrotate(root);
	else if((bf>1)&&(root->data>root->left->data))
	{
		(*root).left=Lrotate((*root).left);
		return Rrotate(root);
	}
	else
	{
		(*root).right=Rrotate((*root).right);
		return Lrotate(root);
	}
	return root;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder((*root).left);
		cout<<(*root).data<<" ->>";
		inorder((*root).right);
	}
}

int main()
{
	int val,rval,n,i,x;
	struct node *temp;
	cout<<"\n\t\tEnter the Root Node";
	cin>>rval;
	struct node *root=Create(rval);
	while(1)
	{
	cout<<"\n\t\t1.Insert a Node";
	cout<<"\n\t\t2.Display";
	cout<<"\n\t\t3.Balance a Node";
	cout<<"\n\t\t4.Exit";
	int choice;
	cout<<"\n\t\tEnter your Choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
				cout<<"\n\t\tEnter No.of.Times The values  should be Inserted :";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"\n\t\tEnter the Values one by one :";
					cin>>x;
					Insert(root,x);
				}
				break;
				
		case 2:
				cout<<"\n\t\t Inorder Traversal";
				inorder(root);
				break;
				
		case 3:
				cout<<"\n\t\t Balancing";
				Balance(root);
				break;
		
		case 4:
				exit(0);	
	}
	}
}
