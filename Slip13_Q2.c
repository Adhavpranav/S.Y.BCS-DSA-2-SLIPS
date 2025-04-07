/*
 Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement function to traverse the graph using Breadth First Search (BFS) traversal. 
*/

#include<stdio.h>
#define SIZE 20

struct queue{
    int data[SIZE];
    int front,rear;
}q;

int limit,arr[10][10];

void init()
{
    q.front=q.rear=-1;
}

int isempty()
{
    if(q.rear==q.front)
    return 1;
    else
    return 0;
}

int isfull()
{
    if(q.rear==SIZE-1)
    return 1;
    else
    return 0;
}

void add(int key)
{
   q.rear++;
   q.data[q.rear]=key;
}

int remove_q()
{
    int val;
    val=q.data[++q.front];
    return val;
}

void Bfs(int v){
    init();
    int visit[20]={0};
    add(v);
    visit[v]=1;
    while(!isempty())
    {
        int i=remove_q();
        printf("V%d\t",i+1);
        for(int j=0;j<limit;j++)
        {
            if(arr[i][j]==1 && visit[j]==0)
            {
                add(j);
                visit[j]=1;
            }
        }
    }
}

int main(){
    int i,j;
     printf("\nENTER NO OF VERTICES:");
     scanf("%d",&limit);
     printf("ENTER ADJACENCY MATRIX:");
     for(i=0;i<limit;i++)
     {
         for(j=0;j<limit;j++)
         {
             scanf("%d",&arr[i][j]);
         }
     }
     printf("Breadth first search:");
     Bfs(0);
}

/*
Input:
    Limit: 5
    Matrix :
    0 1 1 0 1
    1 0 0 1 0
    1 0 0 1 0
    0 1 1 0 0
    1 0 0 0 0
*/
