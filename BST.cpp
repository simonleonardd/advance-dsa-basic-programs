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
struct node* FindMax(struct node* root)
{
	while((*root).right != NULL)
        root = (*root).right;
	return root;
}

struct node* deleteVal(struct node *root, int data)
{
	if(root == NULL)
        return root;
	else if(data < (*root).data)
        (*root).left = deleteVal((*root).left,data);
	else if (data > (*root).data)
        (*root).right = deleteVal((*root).right,data);

	else
        {
		if((*root).left == NULL && (*root).right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if((*root).left == NULL)
		{
			struct node *temp = root;
			root = (*root).right;
			delete temp;
		}
		else if((*root).right == NULL)
		{
			struct node *temp = root;
			root = (*root).left;
			delete temp;
		}
		else
		{
			struct node *temp = FindMax((*root).left);
			(*root).data = (*temp).data;
			(*root).right = deleteVal((*root).right,(*temp).data);
		}
	}
	return root;
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

bool x;
bool leftskew(struct node *root)
{
    if(root->left!=NULL && root->right==NULL)
        {
            x=true;
            leftskew(root->left);
        }
        else if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
}

bool rightskew(struct node *root)
{
    if(root->left==NULL && root->right!=NULL)
        {
            x=true;
            rightskew(root->right);
        }
        else if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
}

bool isSkewed(struct node *root)
{
    if(root->left!=NULL && root->right==NULL)
    {
        if(leftskew(root))
        {
	   cout<<"\nIt is a Left Skewed Tree";
        return true;
    	}
    	else
    		return false;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        if(rightskew(root))
        	{
            cout<<"\nIt is a Right Skewed Tree";
        	return true;
    		}
    	else
    		return false;
    }
    else
        cout<<"\nIt is not a Skewed Tree";
}
int minDepth(node* root)
{
	if(root==NULL)
	 return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(!root->left)
		return minDepth(root->right)+1;
	if(!root->right)
		return minDepth(root->left)+1;
	else
		return min(minDepth(root->left),minDepth(root->right))+1;
}

void find_balanced(struct node *root)

{
	int left=Height(root->left);
	int right=Height(root->right);
	if(left==right)
		cout<<"\nIt is balanced";
	else
		cout<<"\nIt is not balanced";	
}

int i=0;
int y[100];
void SP(struct node *root)
{
    if (root != NULL)
    {
        SP(root->left);
        y[i]=root->data;
        i++;
        SP(root->right);
    }
}

void SP2(int a)
{
    for(int j=0;j<i;j++)
    {
        if(a==y[j])
        {
            if(y[j+1]==y[0])
                cout<<"\n\tSuccessor:NULL";
            else
                cout<<"\n\tSuccessor:"<<y[j+1];
            if(j==0)
                cout<<"\n\tPredecessor:NULL";
            else
                cout<<"\n\tPredecessor:"<<y[j-1];
            break;
        }
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
    cout<<"\n\t\t2.Delete a Node ";
    cout<<"\n\t\t3.Display Tree ";
    cout<<"\n\t\t4.Height of the Tree ";
    cout<<"\n\t\t5.Skewed Tree or not";
    cout<<"\n\t\t6.Minimum Depth of Tree";
    cout<<"\n\t\t7.Successor And Precessor ";
    cout<<"\n\t\t8.Balanced or Not";
    cout<<"\n\t\t9.Exit";
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
            int num;
            cout<<"\n\nEnter the number to be deleted : ";
            cin>>num;
            deleteVal(root,num);
            //cout<<num<<" has been deleted from the Tree\n";
            break;
        case 3 :
            cout<<"\n\n\t\tBinary Search Tree Display : \n\n";
   
                cout<<"\n\n\t\t1.PostOrder Traversal\n\n\t\t";
                    postorder(root);
                cout<<"\n\n\t\t2.InOrder Traversal\n\n\t\t";
                    inorder(root);
                cout<<"\n\n\t\t3.PreOrder Traversal\n\n\t\t";            //break;
                    preorder(root);
                            
            break;

         case 4 : int hiht;
                  hiht=Height(root);
                  cout<<"\n\tHeight of the Tree : "<<hiht;
                  break;
                  
         case 5 :cout<<"\n\n\nResult is :";
         		if(isSkewed(root))
         		break;
         		
         case 6:cout<<"\n\n The minimum depth of binary tree is:"<<minDepth(root)-1;
         		break;
         		
         case 7:
         		cout<<"Enter the Node value:";
         		int a;
            	cin>>a;            
           		 i=0;
            	SP(root);
            	SP2(a);
           		 break;
           		 
         case 8:
         		find_balanced(root);
         		break;

         case 9:exit(0);

    }
}
}
