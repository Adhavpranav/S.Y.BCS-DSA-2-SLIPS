/*Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement functions to print indegree, outdegree and total degree of all vertices of graph.*/

#include<stdio.h>
int main()
{
	int arr[20][20],limit,i,j,sumin=0,sumout=0;
	printf("ENTER THE NO OF VERTICES:");
	scanf("%d",&limit);
    printf("\nENTER ADJACENCY MATRIX");
	for(i=0;i<limit;i++)
	{
		for(j=0;j<limit;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	printf("ADJACENCY MATRIX:\n");
	for(i=0;i<limit;i++)
	{
		printf("V%d\t",i+1);
		for(j=0;j<limit;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	printf("\nVertex\t SumIn\tSumOut\tTotal\n");
	for(i=0;i<limit;i++)
	{
		sumin=0,sumout=0;
		for(j=0;j<limit;j++)
		{
			sumin=sumin+arr[j][i];
			sumout=sumout+arr[i][j];
		}
		printf("V%d\t%d\t%d\t%d\n",i+1,sumin,sumout,(sumin+sumout));
	}
}
/*
Input 
Limit 5
matrix:
    0 1 1 0 1
    1 0 0 1 0
    1 0 0 1 0
    0 1 1 0 0
    1 0 0 0 0

*/
