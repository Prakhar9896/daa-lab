#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int a[100];
    int f;
    int r;
}queue;

queue* init(){
    queue* q=(queue*)malloc(sizeof(queue));
    q->f=0;
    q->r=-1;
    return q;
}

void enqueue(queue* q, int x){
    q->a[++(q->r)]=x;
}

int dequeue(queue* q){
    return q->a[(q->f)++];
}

void topoKahn(int** adj_mat,int v,int* id,queue* q,int* a,int* b,int* visited){

    for (int i = 0; i < v; i++)
    {
        if (id[i]==0 && visited[i]==0)
        {
            enqueue(q,i);
            visited[i]=1;
        }
        
    }
    int r=dequeue(q);
    a[++(*b)]=r;
    for (int i = 0; i < v; i++)
    {
        if (adj_mat[r][i]==1)
        {
            id[i]--;
        }
        
    }
    int flag=1;
    for (int i = 0; i < v; i++)
    {
        if (visited[i]==0)
        {
            flag=0;
            break;
        }
        
    }
    if (flag==1)
    {
        return;
    } 
      
    topoKahn(adj_mat,v,id,q,a,b,visited);
}

int main(){
    int v,e;
    printf("enter the number of vertex: ");
    scanf("%d",&v);
    printf("enter the number of edges: ");
    scanf("%d",&e);

    int** adj_mat=(int**)malloc(v*sizeof(int*));
    for (int i = 0; i < v; i++)
    {
        adj_mat[i]=(int*)calloc(v,sizeof(int));
    }
    
    int n,m;
    int sum;
    printf("enter the edges: ");
    for (int i = 0; i <e; i++)
    {
        scanf("%d %d",&n,&m);
        adj_mat[n][m]=1;
    }

    int* indegree=(int*)calloc(v,sizeof(int));
    for (int i = 0; i < v; i++)
    {
        sum=0;
        for (int j = 0; j < v; j++)
        {
            sum+=adj_mat[j][i];
        }
        indegree[i]=sum;
    }
    queue* q=init();
    int* a=(int*)malloc(v*sizeof(int));
    int k=-1;
    int* visited=(int*)calloc(v,sizeof(int));
    topoKahn(adj_mat,v,indegree,q,a,&k,visited);

    printf("\ntopological order: ");
    for (int i = 0; i <= k; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
    
}