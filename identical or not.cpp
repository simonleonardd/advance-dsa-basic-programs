int i1=-1;
int count1=0,count2=0;
void store_preorder(struct node *r,int *xx,int xy)
{
     if (r != NULL)
    {
        i1++;
        xx[i1]=r->data;
        if(xy==1)count1++;
        if(xy==2)count2++;
       
        store_preorder(r->left,xx,xy);
        store_preorder(r->right,xx,xy);
    }
}

{
            cout<<"\tEnter root node value:";
            cin>>x;
            root1=insert(root1,x);
            while(ww==0)
            {
                cout<<"\n\t1.Insert Node\n\t2.Display\n\t3.Compare with previous Tree\n\tEnter your option:";
                cin>>o1;
                switch(o1)
                {
                    case 1:
                        cout<<"\t\tEnter Data to be inserted:";
                        cin>>d;
                        insert(root1,d);
                        break;
                    case 2:
                        cout<<"\t1.Pre-Order Traversal\n\t2.In-Order Traversal\n\t3.Post-order Traversal\n\tEnter your option:";
                        cin>>oo1;
                        if(oo1==1){
                                cout<<"\t\t";
                            preorder(root1);}
                        else if(oo1==2){
                            cout<<"\t\t";
                            inorder(root1);}
                        else if(oo1==3){
                            cout<<"\t\t";
                            postorder(root1);}
                        else
                            cout<<"Enter a Valid Option";
                        break;
                    case 3:
                        count1=0;count2=0;
                        i1=-1;
                        store_preorder(root,x1,1);
                        i1=-1;
                        store_preorder(root1,x2,2);
                        cout<<"\tNo. of elements:("<<count1<<","<<count2<<")";
                        if(count1==count2)
                        {
                            //cout<<"xx";
                            for(int jj=0;jj<count1;jj++)
                            {
                                //cout<<"ww";
                                cout<<"\n\t\t("<<x1[jj]<<","<<x2[jj]<<")";
                                if(x1[jj]!=x2[jj])
                                {
                                    //cout<<"yy";
                                    cout<<"\n\t\tTrees are not identical";
                                    w=0;
                                    break;
                                }
                                else
                                     w=1;//cout<<"xy";
                            }
                            if(w==1)
                                cout<<"\n\t\tTrees are Identical";//cout<<"yx";
                        }
                        else
                        {
                            cout<<"\n\t\tTree are not identical";
                        }
                        break;
                    default:
                        ww=1;
                        break;
                }
            }
            break;
            }
            
            
            int x1[50],x2[50];
            int c1=0,c2=0,a1,a2,ww=0;//count1=0,count2=0;
    		int o,d,x,oo,a,j,o1,oo1,w,dd;
