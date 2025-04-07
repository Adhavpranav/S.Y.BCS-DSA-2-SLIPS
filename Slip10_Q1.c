/* Q 1) Write a C program for the implementation of Topological sorting.*/
#include<stdio.h>
#define MAX 20
struct stack
{
    int data[MAX];
    int top;
}s;

void init()
{
    s.top=-1;
}

void push(int key)
{
    s.data[++s.top]=key;
}

int pop()
{
    return s.data[s.top--];
}

int isempty()
{
    return s.top==-1;
}

void topo(int arr[10][10],int limit)
{
    int visit[20]={0};
    int ind[20]={0};
    int j,i,v;
    init();
    for(i=0;i<limit;i++)
    {
        ind[i]=0;
        for(j=0;j<limit;j++)
        {
            ind[i]=ind[i]+arr[j][i];
        }
    }
    while(1)
    {
        for(i=0;i<limit;i++)
        {
            if(ind[i]==0 && visit[i]==0)
            {
                push(i);
                visit[i]=1;
                printf("V%d\t",i+1);
            }
        }
        if(isempty())
        {
            break;
        }
        v=pop();
        for(i=0;i<limit;i++)
        {
            if(arr[v][i]==1)
            {
                ind[i]--;
            }
        }
    }

}

int main()
{
    int arr[10][10],i,j,limit;
    printf("ENTER VERTEX LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        for(j=0;j<limit;j++)
        {  
                scanf("%d",&arr[i][j]);
        } 
        printf("\n");
    } 
    printf("\nADJACENCY MATRIX:\n");
    for(i=0;i<limit;i++)
    {
        for(j=0;j<limit;j++)
        { 
         printf("%d\t",arr[i][j]);
           
        }
        printf("\n");
    }
    printf("\nTOPOLOGICAL ORDER:");
    topo(arr,limit);
}
/*
    input matrix
    0 1 1 0 0
    0 0 0 1 0
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0    
*/
