/*
Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the 
adjacency list.  
*/
#include<stdio.h>
#include<stdlib.h>

int arr[20][20],i,j,limit;

struct node
{
	int data;
	struct node *next;
};

struct node *head[20];

void accept()
{
	printf("ENTER NO OF NODES:");
	scanf("%d",&limit);
	printf("ENTER MATRIX:");
	for(i=0;i<limit;i++)
	{
		for(j=0;j<limit;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

void create()
{
	struct  node *temp,*newnode;
	for(i=0;i<limit;i++)
	{
		head[i]=NULL;
		for(j=0;j<limit;j++)
		{
			if(arr[i][j]==1)
			{
				newnode=(struct node *)malloc(sizeof(struct node));
				newnode->data=j+1;
				newnode->next=NULL;
				if(head[i]==NULL)
				{
					head[i]=temp=newnode;
				}
                else
                {
				temp->next=newnode;
				temp=newnode;
                }
			}
		}
	}
}
void displist()
{
	struct node *temp;
	for(i=0;i<limit;i++)
	{
		printf("V%d---->",i+1);
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			printf("V%d-",temp->data);
		}
		printf("NULL\n");
	}
}
int main()
{
	accept();
	create();
	displist();
}

/*
    Input:
    Limit:5
    Matrix:
    0 1 1 0 1
    1 0 0 1 0
    1 0 0 1 0
    0 1 1 0 0
    1 0 0 0 0
*/
