#include<stdio.h>
#include<stdlib.h>

struct stack{
struct node *arr[10];
int capacity,top;
    
};

struct node{
double data;
struct node* left;
struct node* right;};

struct stack* createStack(){
struct stack * s= (struct stack *)malloc(sizeof(struct stack));
s->top=-1;
s->capacity=10;
return s;
};

void push(struct stack *s,struct node* p){

    if(s->top==s->capacity-1)
        printf("Stack is full");
    else
    {



        s->top++;
        s->arr[s->top]=p;
    }
}

void pop(struct stack *s){


        s->top--;

}

struct node* top(struct stack *s){
    struct node* n=s->arr[s->top];
    return n;

}

struct node* newNode(double data){
struct node *n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->right=n->left=NULL;
return n;
};

int isEmpty(struct stack *s){
if(s->top==-1)
    return 1;
else
    return 0;
}

void ponr(struct node * root){
struct stack *s= createStack();
struct node * prev=NULL;
do{
    while(root!=NULL){
        push(s,root);
        root=root->left;
    }
    while(root==NULL && !isEmpty(s)){
        root=top(s);
        if(root->right==NULL || root->right== prev)
        {
        printf("%f\t",root->data);
        pop(s);
        prev=root;
        root=NULL;
        }else{
        root=root->right;}

    }
}while(!isEmpty(s));}


void kthSmallestElement(struct node* root,int k ){
    
static int count =1;
if(root){
kthSmallestElement(root->left,k);
if(k==count)
    printf(" %f \n",root->data);
count++;
kthSmallestElement(root->right,k);
    
}

}void inorder(struct node* root)
{
    if(root){
           inorder(root->left);
           printf("  %f  ",root->data);
           inorder(root->right);
           
    }
}


int  main(){
    float t;
    
    struct node* root=newNode(2.9);
    root->left=newNode(3.245);
    root->left->left=newNode(1.0975);
    root->right=newNode(5.555);
    root->left->right=newNode(3.333);

    ponr(root);
    inorder(root);
    printf("\n");
 
    printf("enter the kth element");
    scanf("%f",&t);
    
    kthSmallestElement(root,t);

return 0;
}
