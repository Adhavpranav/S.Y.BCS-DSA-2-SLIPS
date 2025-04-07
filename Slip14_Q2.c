/*
 Write a C program which uses Binary search tree library and displays nodes at each level, and total 
levels in the tree.
*/
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

struct node {
    int data;
    struct node *left, *right;
};

struct queue {
    struct node *d[maxsize];
    int front, rear;
};
struct queue q;

void init() {
    q.front = q.rear = -1;
}

int isEmpty() {
    return q.front == q.rear;
}

void add(struct node *temp) {
    q.d[++q.rear] = temp;
    if (q.front == -1)
        q.front = 0;
}

struct node *rm() {
    return q.d[q.front++];
}

struct node*create(struct node*root){
    struct node*newnode,*p,*q;
    int limit,i,j;
    printf("ENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL){
            root=newnode;
        }
        else
        {
            p=root;
            while(p!=NULL)
            {
                q=p;
                if(newnode->data<p->data)
                p=p->left;
                else
                p=p->right;
            }
            if(newnode->data<q->data)
            q->left=newnode;
            else
            q->right=newnode;
        }
    }
    return root;
}

void levelorder(struct node *root) {
    struct node *temp;
    int level = 0;
    init();
    add(root);
    add(NULL);
    printf("Level %d:\t", level);

    while (!isEmpty()) {
        temp = rm();
        if (temp == NULL) {
            if (!isEmpty()) {
                add(NULL);
                level++;
                printf("\nLevel %d:\t", level);
            }
        } else {
            printf("%d\t", temp->data);
            if (temp->left != NULL)
                add(temp->left);
            if (temp->right != NULL)
                add(temp->right);
        }
    }

    printf("\nTotal Levels = %d\n", level + 1);
}

int main() {
    struct node *root = NULL;
    root = create(root);
    levelorder(root);
    return 0;
}
