#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a,int b);

struct node* creatnode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    
    return(temp);
    
}

struct node* insertree(struct node *root,int val)
{   struct node *temp,*parent=NULL;
    struct node *ptr=creatnode(val);
    if(root==NULL)
        root=ptr;
        
    else {   temp=root;
             //parent=temp;
             while(temp!=NULL)
             {    parent=temp;
               
                 if(val<temp->data)
                        temp=temp->left;
                        
                 else
                   temp=temp->right;
             }
             if(val<parent->data)
              parent->left=ptr;
              else 
                parent->right=ptr;
                
         }
         return(root);
}

int max(int a,int b){
    return (a > b)? a: b;
        
}
int height(struct node *root){
    if(root==NULL)
      return 0;
      else
       return(root->height );
       
}
int  getbalance(struct node *root)
{
    if(root==NULL)
    return 0;
    else 
    return(height(root->left)-height(root->right));
    
    
}

struct node *rotateright(struct node* root)
{
    struct node *x=root->left;
    struct node *t2=x->right;
    
    x->right=root;
    root->left=t2;
     
    root->height=(1+max(height(root->left),height(root->right)));
    x->height=(1+max(height(x->left),height(x->right)));

return(x);

}
struct node *rotateleft(struct node *root){
    struct node *y=root->right;
    struct node *t2=y->left;
    
    y->left=root;
    root->right=t2;
    
        root->height=(1+max(height(root->left),height(root->right)));
        y->height=(1+max(height(y->left),height(y->right)));

return(y);

}


struct node* avltreeinsert(struct node *root, int val){
    int balance;
    if(root==NULL)
    return(creatnode(val));
       if(val<root->data)
          root->left=avltreeinsert(root->left,val);
          else if(val>root->data)
               root->right=avltreeinsert(root->right,val);
               else
                 return root;
                 
         
    
    root->height=(1+max(height(root->left),height(root->right)));
     balance=getbalance(root);
    
    if(balance > 1 && val < root->left->data)
       return(rotateright(root));
       
       else if(balance>1 && val>root->left->data)
          {root->left=rotateleft(root);
            return(rotateright(root));
          }
          else if(balance<-1 && val < root->right->data)
          {
              root->right=rotateright(root);
              return(rotateleft(root));
          }
         else
       if(balance<-1 && val >root->right->data)
       return(rotateleft(root));
       
       return root;
       
}
void preorder(struct node* root)
{
    if(root!=NULL){
        printf("   %d   ",root->data);
        preorder(root->left);
        preorder(root->right);
        
    }
    
}
void inorder(struct node* root)
{
    if(root){
           inorder(root->left);
           printf("  %d  ",root->data);
           inorder(root->right);
           
    }
}

void postorder(struct node* root){
    if(root){
           postorder(root->left);
           postorder(root->right);
           printf("  %d  ",root->data);
    }
}

int main()
{struct node* root=NULL;

    int option,val,ele,del;
while(1){
  printf("\n     *****enter the option*****    \n");
  printf("1.insert in the tree\n");
  printf("2.preorder traversal\n");
  printf("3.inorder traversal\n");
  printf("4.postorder traversal\n");
  printf("5.insert as avltreeinsert\n");
 // printf("6. delete the given element\n");
  printf("6. exit\n ");
  scanf("%d",&option);
           switch(option)
           {
                case 1 :   printf("enter the value to be entererd   ");
                          scanf("%d",&val);
                          root=insertree(root,val);
                          break;
                          
                case 2 :  preorder(root);
                          break;
                          
                case 3 :  inorder(root);
                          break;
                          
                case 4 :  postorder(root);
                          break;
                          
               case  5 :  printf("enter the value to be entererd   ");
                          scanf("%d",&val);
                          root=avltreeinsert(root,val);
                          break;
                          
                           
                case 6:   exit(0);
                    
                default :  printf("\n***invlaid command number****");
                         
           }
}
    return 0;
    
}