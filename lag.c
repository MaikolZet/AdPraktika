#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lag.h"


int searchElement(struct Node* head, int item)
{
    struct Node* current = head;  // Initialize current
    int index = 0;
    // traverse till then end of the linked list
    while (current != NULL)
    {
        if (current->data == item){
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void insert(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    //changing the new head to this freshly entered node
    *head = newNode;
}

void display(struct Node* node){

    //as linked list will end when Node is Null
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}