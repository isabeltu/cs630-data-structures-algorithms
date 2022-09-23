#include <stdio.h>
#include <stdlib.h> 
#include "BinTree.h"


void add(struct node ** proot, int key, int data)
{
    if (*proot == NULL)
    {
        *proot = malloc(sizeof(struct node));
        (*proot)->key = key;
        (*proot)->data = data;
        (*proot)->left = NULL;
        (*proot)->right = NULL;
    }
    else
    {
        if (key > (*proot)->key)
        {
            add(&((*proot)->right), key, data);
        }
        else 
        {
            add(&((*proot)->left), key, data);
        }
    }
}

void printInOrder(struct node ** proot)
{
    if (*proot != NULL)
    {
        printInOrder(&((*proot)->left));
        printf("%d: %d\n", (*proot)->key, (*proot)->data);
        printInOrder(&((*proot)->right));
    }
}


//returns 0 for false, 1 for true
int hasKey(struct node ** proot, int key){
    if(*proot == NULL){
        return 0;
    }
    else if(key == (*proot)->key){
        return 1;
    }
    else if(key > (*proot)->key){
        return(hasKey(&((*proot)->right), key));
    }
    else{
        return(hasKey(&((*proot)->left), key));
    }
}

int valueAtKey(struct node ** proot, int key){
    if(key == (*proot)->key){
        return (*proot)->data;
    }
    else if(key > (*proot)->key){
        return(valueAtKey(&((*proot)->right), key));
    }
    else{
        return(valueAtKey(&((*proot)->left), key));
    }
}

void changeValueAtKey(struct node ** proot, int key, int data){
    if(key == (*proot)->key){
        (*proot)->data = data;
    }
    else if(key > (*proot)->key){
        changeValueAtKey(&((*proot)->right), key, data);
    }
    else{
        changeValueAtKey(&((*proot)->left), key, data);
    }
}

void removeKey(struct node ** proot, int key){
    if(key < (*proot)->key){
        removeKey(&((*proot)->left), key);
    }
    else if(key > (*proot)->key){
        removeKey(&((*proot)->right), key);
    }
    else{
        //no children
        if((*proot)->left == NULL && (*proot)->right == NULL){
            //printf("nochildren\n");
            free(*proot);
            *proot = NULL;
        }

        //only right child
        else if((*proot)->left == NULL){
            //printf("rightchild\n");
            struct node * temp = (*proot)->right;
            free(*proot);
            *proot = temp;
        }

        //only left child
        else if((*proot)->right == NULL){
            //printf("leftchild\n");
            struct node * temp = (*proot)->left;
            free(*proot);
            *proot = temp;
        }

        //two children
        else{

            struct node ** curr = proot;
            curr = &(*curr)->left;
            while((*curr)->right != NULL){
                curr = &((*curr)->right);
            }
            struct node * temp = (*curr)->left;
            int newKey = (*curr)->key;
            int newData = (*curr)->key;
            free(*curr);
            *curr = temp;
            (*proot)->key = newKey;
            (*proot)->data = newData;

        }
    }


}

//returns amount of memory freed for testing purposes
void destroyTree(struct node ** proot){
    if(*proot == NULL){
        return;
    }

    destroyTree(&((*proot)->right));
    destroyTree(&((*proot)->left));
    int temp = (*proot)->key;
    free(*proot);
    *proot = NULL;
    //printf("freed: %d\n", temp);

}