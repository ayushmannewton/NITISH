#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int v;
    int e;
    int **adj;
};

struct graph* adjecencymatrix()
{   int u,v,i,j;
    struct graph *G=(struct graph*)malloc(sizeof(struct graph));
    if(!G)
      printf("memory error");
      
      printf("enter the vertex and edge");
      scanf("%d %d",&G->v,&G->e);
      G->adj=malloc(sizeof(int)*(G->v *G->v));
      for(u=0; u<G->v; u++)
        for(v=0; v<G->e; v++)
            G->adj[u][v]=0;
      printf("enter the index for the matrix which fills the edges");
      for(i=0; i<G->e; i++)
      {
      scanf("%d %d",&u,&v);
      G->adj[u][v]=1;
      G->adj[v][u]=1;
      }
      
      
      return(G);
      
}
int main(){
    struct graph *G=NULL;
    int option;
    while(1)
    {
      printf("\n enter the options");
      printf("\n 1.adjecencymatrix");
      printf("\n 2.exit");
      scanf("%d",&option);
     switch(option){
             case 1 :    G=adjecencymatrix();
                         break;
             case 2 :    exit(0);
            
     }
}
return 0;


}