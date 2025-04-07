#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
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

int search(struct node* root,int num){
    if(root!=NULL){
        if(root->data==num){
            return 1;
        }
        if(num<root->data)
        return search(root->left,num);
        else
        return search(root->right,num);
    }
    return 0;
}

void inorder(struct node*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    }
}

int main(){
    struct node*root=NULL;
    int choice,num;
    while(1){
        printf("\n1:CREATE\n2:SEARCH\n3:INORDER\n4:EXIT");
        printf("\nENTER A CHOICE:");
        scanf("%d",&choice);
        switch(choice){
            case 1:root=create(root);
                    break;
            case 2:printf("\nENTER A NUMBER TO SEARCH:");
                    scanf("%d",&num);
                    if(search(root,num))
                    printf("\nNUMBER IS FOUND");
                    else
                    printf("\nNUMBER IS NOT FOUND");
                    break;    
            case 3:printf("\nELEMENTS OF TREE IN INORDER:");
                   inorder(root);
                   break;
            case 4:printf("\nEXIT SUCC !");
                    return 0;
                    break;
            default:printf("\nINVALID CHOICE");
        }
    }

}
