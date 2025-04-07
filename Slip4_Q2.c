#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node* create(struct node* root){
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

int countLeaf(struct node* root){
    static int leaf_count=0;
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            leaf_count++;
        }
        countLeaf(root->left);
        countLeaf(root->right);
    }
    return leaf_count;
}

int counttotalnode(struct node*root){
    static int total_count=0;
    if(root!=NULL){
        total_count++;
        counttotalnode(root->left);
        counttotalnode(root->right);
    }
    return total_count;
}

int main(){
    struct node*root=NULL;
    root=create(root);
    printf("\nTOTAL NODES COUNT: %d",counttotalnode(root));
    printf("\nTOTAL LEAF NODE COUNT:%d",countLeaf(root));
    return 1;
}
