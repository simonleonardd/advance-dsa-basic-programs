#include<iostream>
#include<stdlib.h>
using namespace std;

bool s;
int i=0;
int y[100];

struct node
{
    int data;
    struct node *right;
    struct node *left;
}*root;

struct node* createnode(int data)
{
    node *t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->right=NULL;
    t->left=NULL;
    return t;
};
struct node* insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>=root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
 }

void inorder(struct node *root)
{
    
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<"\n";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    
    
    if (root != NULL)
    {
        cout<<root->data<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\n";
    }
}

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

bool leftskew(struct node *root)
{
    if(root->left!=NULL && root->right==NULL)
        {
            s=true;
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
            s=true;
            rightskew(root->right);
        }
        else if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
}

void findskewed(struct node *root)
{
    if(root->left!=NULL && root->right==NULL)
    {
        if(leftskew(root))
            cout<<"\nIt is a Left Skewed Tree";
        return;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        if(rightskew(root));
            cout<<"\nIt is a Right Skewed Tree";
        return;
    }
    else
        cout<<"\nIt is not a Skewed Tree";
}




int main()
{
    root=NULL;
    int o,d,x,oo,a,j;
    int in[100];
    cout<<"Enter root node value:";
    cin>>x;
    root=insert(root,x);
    while(1)
    {
        cout<<"\n1.Insert/Create Tree\n2.Display\n3.Display Successor and Predecessor\n4.Find if Tree is Skewed\nEnter your option:";
        cin>>o;
        switch(o)
        {
        case 1:
            cout<<"Enter Data to be inserted:";
            cin>>d;
            insert(root,d);
            break;
        case 2:
            cout<<"1.Pre-Order Traversal\n2.In-Order Traversal\n3.Post-order Traversal\nEnter your option:";
            cin>>oo;
            if(oo==1)
                preorder(root);//cout<<"root->data";
            else if(oo==2)
                inorder(root);
            else if(oo==3)
                postorder(root);
            else
                cout<<"Enter a Valid Option";
            break;
        case 3:
            
            cout<<"Enter the Node value:";
            cin>>a;            
            i=0;
            SP(root);
            
            SP2(a);
            break;
        case 4:
            findskewed(root);
            //if(s==1)
             //   cout<<"It is a left skewed tree";
            //else
              //  cout<<"It is not a left skewed tree";
              break;
        default:
            exit(1);
        }
    }
    return 0;
}
