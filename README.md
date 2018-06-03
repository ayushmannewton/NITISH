# NITISH#include<stdio.h>
#include<stdlib.h>
# define size 40

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue{
    int info[size];
int front;
int rear;
};

struct node *root=NULL;

struct node* creatnode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    
    return(temp);
    
}

void insertree(int val)
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


void kthSmallestElement(struct node* root,int k ){
    
static int count =1;
if(root){
kthSmallestElement(root->left,k);
if(k==count)
    printf(" %d \n",root->data);
count++;
kthSmallestElement(root->right,k);
    
}

}

int main()
{struct node* temp;

    int option,val,t;
while(1){
  printf("\n     *****enter the option*****    \n");
  printf("1.insert in the tree\n");
  printf("2.preorder traversal\n");
  printf("3.inorder traversal\n");
  printf("4.kthsmallestelement traversal\n");
  printf("7. exit\n ");
  scanf("%d",&option);
           switch(option)
           {
                case 1 :   printf("enter the value to be entererd   ");
                          scanf("%d",&val);
                          insertree(val);
                          break;
                          
                case 2 :  preorder(root);
                          break;
                          
                case 3 :  inorder(root);
                          break;
                          
                          
                case 4 : printf("enter the kth no");
                         scanf("%d",&t);
                        kthSmallestElement(root,t);
                         break;
                         
                          
               
                           
                case 7 :   exit(0);
                    
                default :  printf("\n***invlaid command number****");
                         
           }
}
    return 0;
    
}
