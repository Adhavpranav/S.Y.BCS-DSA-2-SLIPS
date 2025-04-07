/*
Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement function to traverse the graph using Depth First Search (DFS) traversal.  
*/

#include<stdio.h>
int arr[10][10],limit,visited[10]={0};
void DFS(int i){
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<limit;j++){
        if(visited[j]==0 && arr[i][j]==1){
            DFS(j);
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
    DFS(0);
}
/*
    Input:~
    limit=5
    matrix:     
    0 1 1 0 1
    1 0 0 1 0
    1 0 0 1 0
    0 1 1 0 0
    1 0 0 0 0
*/
