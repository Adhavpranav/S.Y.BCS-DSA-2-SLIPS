#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node*create(struct node*root){
    int limit,i;
    struct node*newnode,*p,*q;
    printf("\nENTER A LIMIT:");
    scanf("%d",&limit);
    for(i=0;i<limit;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("ENTER VALUE:");
        scanf("%d",&newnode->data);
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
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

struct node* insert(struct node*root,int num){
    struct node*newnode,*p,*q;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        return newnode;
    }
    p=root;
    while(p!=NULL){
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
    printf("\nINSERT SUCC!");
    return root;
}

void preorder(struct node*root){
    if(root!=NULL){
    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

int main(){
    struct node*root=NULL;
    int choice,num;
    while(1){
        printf("\n1:CREATE\n2:INSERT\n3:PREORDER\n4:EXIT");
        printf("\nENTER A CHOICE:");
        scanf("%d",&choice);
        switch(choice){
            case 1:root=create(root);
                    break;
            case 2:printf("\nENTER A NUMBER TO INSERT:");
                    scanf("%d",&num);
                    root=insert(root,num);
                    break;    
            case 3:printf("\nELEMENTS OF TREE IN PREORDER:");
                   preorder(root);
                   break;
            case 4:printf("\nEXIT SUCC !");
                    return 0;
                    break;
            default:printf("\nINVALID CHOICE");
        }
    }
}
