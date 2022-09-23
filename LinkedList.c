#include <stdio.h>
#include <stdlib.h> 
#include "LinkedList.h"

void push(struct node ** head, int data)
{
    struct node * toAdd = malloc(sizeof(struct node));
    //printf("added\n");
    currentAllocs++;
    toAdd->data = data;
    toAdd->next = *head;
    *head = toAdd;
    
}

void print(struct node ** head)
{
    struct node * cur = *head;
    if(cur == NULL){
        printf("NULL");
    }
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("   current memory allocated: %d\n", currentAllocs);
}


void removeFromHead(struct node ** head)
{
    struct node * tmp = (*head)->next;
    free(*head);
    //printf("freed\n");
    currentAllocs--;
    *head = tmp;
}



void addAtX(struct node ** head, int data, int x)
{
    struct node * toAdd = malloc(sizeof(struct node));
    //printf("added\n");
    currentAllocs++;

    toAdd->data = data;
    struct node * cur = *head;
    for(int i = 0; i<x-1; i++){
        cur = cur->next;
    }
    toAdd->next = cur->next;
    cur->next = toAdd;
    

}

void removeAtX(struct node ** head, int x)
{
    struct node * cur = *head;
    for(int i = 0; i<x-1; i++){
        cur = cur->next;
    }
    struct node *tmp = cur->next->next;
    free(cur->next);
    //printf("freed\n");
    currentAllocs--;
    cur->next = tmp;

    /*

    in-class solution:

    if(x == 0){
        removeFromHead(head);
    }

    else{
        removeAtX(&(*head->next), x-1);
    }

    */
}

int getData(struct node ** head, int x)
{
    struct node * cur = *head;
    for(int i = 0; i<x; i++){
        cur = cur->next;
    }

    return(cur->data);
}

int sumData(struct node ** head)
{
    int sum = 0;
    struct node * cur = *head;
    while (cur != NULL)
    {
        sum += cur->data;
        cur = cur->next;
    }
    return sum;
}

int getMin(struct node ** head)
{
    struct node * cur = *head;
    int min = cur->data;
    while(cur != NULL){
        if(cur->data < min){
           min = cur->data;
        }
        cur = cur->next;
    }
    return min;
}

int getMax(struct node ** head)
{
    struct node * cur = *head;
    int max = cur->data;
    while(cur != NULL){
        if(cur->data > max){
           max = cur->data;
        }
        cur = cur->next;
    }
    return max;
}

void reverse(struct node ** head)
{
    struct node * cur = *head;
    struct node * new = NULL;
    while(cur != NULL){
        push(&new, cur->data);
        removeFromHead(head); // should free the memory
        cur = *head;
    }
    *head = new;

}

void destroy(struct node ** head)
{
    while(*head != NULL){
        removeFromHead(head);
        //printf("removed\n");
    }
}