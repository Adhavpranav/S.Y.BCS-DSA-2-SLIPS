/*Q 1) Write a menu driven program to implement hash table using array (insert,display). Use any of the abovementioned hash functions. 
In case of collision apply linear probing.
*/#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE];  // Hash table array

void init() 
{
    for(int i=0; i<TABLE_SIZE; i++)
     {
        h[i] = -1;  // -1 means empty
    }
}

void insert()
 {
    int key, index, i, hkey;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for(i=0; i<TABLE_SIZE; i++)
     {
        index = (hkey + i) % TABLE_SIZE;
        if(h[index] == -1)
         {
            h[index] = key;
            printf("Inserted at index %d\n", index);
            return;
        }
    }
    printf("Element cannot be inserted, Hash Table is full!\n");
}


void display()
 {
    printf("\nElements in the Hash Table:\n");
    for(int i=0; i<TABLE_SIZE; i++)
     {
        printf("Index %d --> ", i);
        if(h[i] != -1)
            printf("%d\n", h[i]);
        else
            printf("Empty\n");
    }
}

int main() {
    int ch;
    init();

    do
    {
        printf("\n1-Insert\n2-Display\n3-Exit\nEnter choice:");
        scanf("%d", &ch);

        switch(ch) {
            case 1: insert();
                     break;
            case 2: display();
                  break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(ch<4);
    return 0;
}
