#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "BinTree.h"

int inOrder(struct node * root);
int maxValue(struct node * root);
int minValue(struct node * root);

int main(int argc, char ** argv)
{
    /*

    struct node * root = NULL;
    add(&root, 7, 15);
    add(&root, 2, 19);
    add(&root, 9, 12);
    add(&root, 3, 11);
    add(&root, 114, 10);
    add(&root, 17, 15);
    add(&root, 233, 19);
    add(&root, 90, 12);
    add(&root, -4, 11);
    add(&root, 113, 10);
    //printInOrder(&root);
    //removeKey(&root, 2);
    printInOrder(&root);
    printf("%d\n", destroyTree(&root));
    printInOrder(&root);
    */

    //TESTING

    printf("Errors found:\n");

    struct node * root = NULL;

    srand(time(0)); 
    int listLength = rand() % 100 + 1;


    for(int i = 0; i<listLength; i++){
        int key = rand()%10000;
        int value = rand();
        //key limitted to <10000
        add(&root, key, value);

    }

    //printInOrder(&root);

    //test add method is putting nodes in correct order

    if(!inOrder(root)) printf("nodes not added in correct order\n");

    //test hasKey method

    //add a random key and check to make sure hasKey detects it, repeat 100 times just to make sure
    for(int i = 0; i<100; i++){
        int randomKey = rand()%10000;
        add(&root, randomKey, 0);
        //value doesn't matter here
        if(!hasKey(&root, randomKey)){
            printf("hasKey failed to detect existing key\n");
            break;
        }

    }
    //check to make sure hasKey isn't detecting a key that isn't there (keys are limitted to <10000)
    if(hasKey(&root, 10000)){
        printf("hasKey detected key that isn't there\n");
    }

    //test valueAtKey

    //adds key value pair and checks to make sure it returns correct value (might fail if there are repeat keys)

    int randKey = rand()%10000;
    int randValue = rand();
    add(&root, randKey, randValue);

    if(valueAtKey(&root, randKey) != randValue){
        printf("valueAtKey returned wrong value\n");
    }

    //test removeKey

    //add one first to make sure we are removing one that exists then check to make sure tree is still in order


    randKey = rand()%10000;
    add(&root, randKey, 0); //value doesn't matter
    removeKey(&root, randKey);

    if(!inOrder(root)) printf("order messed up after removal\n");

    //check changeValueAtKey

    
    randKey = rand()%10000;
    randValue = rand();
    add(&root, randKey, 0); //value doesn't matter
    changeValueAtKey(&root, randKey, randValue);
    if(valueAtKey(&root, randKey) != randValue) printf("changeValueAtKey did not successfully change value\n");

    //check destroyTree

    destroyTree(&root);
    if(root != NULL){
        printf("destoyTree failed\n");
    }





    printf("End of errors\n");



}


int inOrder(struct node * root){
    if(root == NULL){
        return 1;
    }
    if (maxValue(root->left) > root->key){
        return 0;
    }
    if (minValue(root->right) < root->key){
        return 0;
    }
    if (!inOrder(root->left) || !inOrder(root->right)){
        return 0;
    }
    return 1;
}

int maxValue(struct node * root){
    int max = INT_MIN;
    if (root != NULL)
    {
        int leftMax = maxValue(root->left);
        int rightMax = maxValue(root->right);
        if(leftMax > max) max = leftMax;
        if(rightMax > max) max = rightMax;
        if(root->key > max) max = root->key;
    }

    return max;
}

int minValue(struct node * root){
    int min = INT_MAX;
    if (root != NULL)
    {
        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);
        if(leftMin < min) min = leftMin;
        if(rightMin < min) min = rightMin;
        if(root->key < min) min = root->key;
    }

    return min;
}