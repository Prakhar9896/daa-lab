#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int arr[100];
    int top;
}Stack;

void push(Stack* s,int x){
    s->arr[++(s->top)]=x;
}

int pop(Stack* s){
    return s->arr[(s->top)--];
}

void display(int** adj_mat,int n){
    printf("the adjacent matrix is: ");
    for (int i = 0; i < n; ++i)
    {
        printf("\n");
        for (int j = 0; j < n; ++j)
        {
            printf("%d ",adj_mat[i][j]);
        }
    }
    printf("\n");
}

void topSort(int** adj_mat,int n,int x,Stack* s1,Stack* s2,int* visited){
    push(s1,x);
    visited[x]=1;
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[x][i]==1 && visited[i]!=1)
        {
            topSort(adj_mat,n,i,s1,s2,visited);
        }     
    }
    push(s2,(pop(s1)));
}   

int main(){
    int u,v;
    int n;
    printf("enter the number of vertix: ");
    scanf("%d",&n);
    int m;
    printf("enter the number of edges: ");
    scanf("%d",&m);
    int x;
    int* visited=(int*)calloc(n,sizeof(int));
    int** adj_mat=(int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; ++i)
    {
        adj_mat[i]=(int*)malloc(n*sizeof(int));
    }

    for (int i = 0; i <n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            adj_mat[i][j]=0;
        }
    }

    printf("enter the edges: ");
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d",&u,&v);
        adj_mat[u][v]=1;
    }

    display(adj_mat,n);
    printf("enter the starting vertex: ");
    scanf("%d",&x);

    Stack* s1=(Stack*)malloc(sizeof(Stack));
    Stack* s2=(Stack*)malloc(sizeof(Stack));
    s2->top=-1;
    s1->top=-1;
    
    topSort(adj_mat,n,x,s1,s2,visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i]!=1)
        {
            topSort(adj_mat,n,i,s1,s2,visited);
        }
    }
    printf("\nTopological Sort: ");
    while (s2->top>=0)
    {
        printf("%d ",pop(s2));
    }

    return 0;
}