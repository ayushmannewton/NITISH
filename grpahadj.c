#include<stdio.h>
#include<stdlib.h>

struct adjlistnode{
    int dest;
    struct adjlistnode *next;
    
};

struct adjlist
{
    struct adjlistnode *head;
    
};

struct graph{
    int v;
struct adjlist *array;
    
};

struct adjlistnode* adjnewlist(int dest){
    struct adjlistnode *newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
    
}

 struct graph* newgraph(int v){
     struct graph *grap=(struct graph*)malloc(sizeof(struct graph));
     grap->v=v;
     grap->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
     
     int i;
     for(i=0; i<v; ++i)
         grap->array[i].shead=NULL;
         return grap;
         
 }
 
 void addedge(struct graph *graph,int src,int dest)
 {
     struct adjlistnode *newnode=adjnewlist(dest);
     newnode->next=graph->array[src].head;
     graph->array[src].head=newnode;
     
     newnode=adjnewlist(src);
     newnode->next=graph->array[dest].head;
     graph->array[dest].head=newnode;
     
 }
 
 void printgraph(struct graph *graph){
     int v;
     for(v=0; v< graph->v; ++v)
     {
         struct adjlistnode *pcrawl=graph->array[v].head;
         while(pcrawl)
         {
             printf("-> %d ",pcrawl->dest);
             pcrawl=pcrawl->next;
         }
         
            printf("\n");
            
     }
 }

int main(){
    int v=5;
    struct graph *graph=newgraph(v);
    addedge(graph,0,1);
    addedge(graph,0,4);
    addedge(graph,1,2);
    addedge(graph,1,3);
    addedge(graph,1,4);
    addedge(graph,2,3);
    addedge(graph,3,4);
    
    printgraph(graph);
    
    
    return 0;
    
}