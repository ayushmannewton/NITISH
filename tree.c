#include<stdio.h>
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

struct queue* creatqueue()
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    
    return q;
    
}

void enqueue(struct queue* q,int val){
    if(q->rear==size-1)
    printf("queue is fulll of memory");
    else if(q->front==-1)
           q->front++;
           q->rear++;
           q->info[q->rear]=val;
}

int isemptyqueue(struct queue* q)
{
    if(q->rear==-1)
       return 1;
       else
       return 0;
       
}

int dequeue(struct queue* q)
{int val;

    if(isemptyqueue(q)){
       printf("queue is empty");
       val=-1;
    }
       else{
       val=q->info[q->front++];
        if(q->front > q->rear)
          {   printf("resetiing queue");
             q->front=q->rear=-1;
          }
       }
       return val;
       
}
void levelorder(struct node* root)
{
    int val;
    struct node* temp=root;
    struct queue* q=creatqueue();
    enqueue(q,temp->data);
    while(!isemptyqueue(q))
    { 
        val=dequeue(q);
        printf("%d",val);
        if(temp->left)
              enqueue(q,temp->data);
        if(temp->right)
              enqueue(q,temp->data);
    }

}

struct node* find(struct node* root,int data){
    if(root==NULL)
      return(root);
      if(data<root->data)
        return(find(root->left,data));
        else if(data>root->data)
           return(find(root->right,data));
           
        return(root);
        
}

struct node *findmax(struct node* root){
    if(root==NULL || (root->right==NULL))
           return(root);
    else 
            return(root->right);
            
}

struct node* deleteElement(struct node *root,int data){
    struct node *temp;
    if(root==NULL)
         return(root);
         
          if(data<root->data)
               root->left=deleteElement(root->left,data);
         else if(data>root->data)
               root->right=deleteElement(root->right,data);
               
                        else{   temp=root;                    //one child case
                               if(root->left==NULL){
                                   root=root->right;
                                   free(temp);return(root);
                               }
                                  else if(root->right==NULL){
                                          root=root->left;
                                          free(temp);
                                           return(root);
                                  }
                           
                                                    //two child case
                          temp=findmax(root->left);
                          root->data=temp->data;
                           root->left=deleteElement(root->left,root->data);
                                   
                    }
                    return (root);
                    
} 

int main()
{struct node* temp;

    int option,val,ele,del;
while(1){
  printf("\n     *****enter the option*****    \n");
  printf("1.insert in the tree\n");
  printf("2.preorder traversal\n");
  printf("3.inorder traversal\n");
  printf("4.levelorder traversal\n");
  printf("5.search the given element\n");
  printf("6. delete the given element\n");
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
                          
                case 4 :  levelorder(root);
                          break;
                          
                case 5 :  printf("enter the value to be searched  ****");
                          scanf("%d",&ele);
                          temp=find(root,ele);
                          if(temp!= NULL)
                          {
                          printf("address of the given variable element is    \n");
                            
                          printf("%p",(void*)temp);
                          }else{
                                
                                printf("\n****not found*\n***adding***");
                                insertree(ele);
                          }
                           break;
                              
                case 6 :   printf("enter the no to be deleted***  ");
                           scanf("%d",&del);
                           temp=find(root,del);
                          if(temp!=NULL){
                            root=deleteElement(root,del);
                             printf("\n ****deleted****\nyou can check by inorder or preorder or postorder");
                          }
                          else
                           printf("\n****not found*\n***hence no deletion***");
                          
                           break;
                           
                case 7 :   exit(0);
                    
                default :  printf("\n***invlaid command number****");
                         
           }
}
    return 0;
    
}