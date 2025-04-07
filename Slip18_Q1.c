/*
 Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. 
Display the adjacency matrix.  
*/

#include<stdio.h>
int main(){
    int arr[10][10],limit,i,j;
    printf("\nENTER NO OF VERTICES:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
	{
		for(j=0;j<limit;j++)
		{
			arr[i][j]=0;
			if(i!=j)
			{
				printf("ENTER EDGES BETWEEN V%d and V%d",i+1,j+1);
				scanf("%d",&arr[i][j]);
			}
		}
	}
    printf("ADJENCY MATRIX\n");
	for(int i=0;i<limit;i++){
		printf("\tV%d",i+1);
	}
	for(i=0;i<limit;i++)
	{
		printf("\nV%d\t",i+1);
		for(j=0;j<limit;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
