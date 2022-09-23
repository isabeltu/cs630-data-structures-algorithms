#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "LinkedList.h"

int main(int argc, char ** argv)
{


    printf("Errors found:\n");

    struct node * head = NULL;
    currentAllocs = 0;
    int length = 0;
    //manually keeping track of length and comparing to memory allocation at end to see if memory is freed correctly

    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    //manually keeping track of sum, min, max to compare to return value of respective methods

    srand(time(0)); 
    int listLength = rand() % 100 + 1;


    for(int i = 0; i<listLength; i++){
        int value = rand();
        push(&head, value);
        length++;
        sum += value;
        if(value < min) min = value;
        if(value > max) max = value;

    }

    //linked list with random length between 1-100 and filled with random numbers

    //test push method allocation
    if(currentAllocs != length){
        printf("Memory allocated wrong during push\n");
        length = currentAllocs;
        //set them equal so it doesn't set off future allocation checks
    }

    //test sumData

    if(sumData(&head) != sum){
        printf("sumData failed\n");
    }

    //test getMin

    if(getMin(&head) != min){
        printf("getMin failed\n");
    }

    //test getMax

    if(getMax(&head) != max){
        printf("getMax failed\n");
    }

    //test removeFromHead

        int second = getData(&head, 1);

    removeFromHead(&head);
    length--;

    if(currentAllocs != length){
        printf("Memory allocated wrong during removeFromHead\n");
        length = currentAllocs;


    }
    if(getData(&head, 0) != second){
        //testing if new first value is equal to the old second value
        printf("removeFromHead failed\n");
    }

    //test addAtX
    int X = rand()%length;
    int value = rand();
    addAtX(&head, value, X);
    length++;

    if(currentAllocs != length){
        printf("Memory allocated wrong during addAtX\n");
        length = currentAllocs;
    }
    if(getData(&head, X) != value){
        printf("addAtX failed\n");
    }

    //test removeAtX

    X = rand()%length;

    //keep track of the value that was before and after the position we want to remove and verify that they are in the right place afterwards
    int before = getData(&head, X-1);
    int after = getData(&head, X+1);

    removeAtX(&head, X);
    length--;

    if(currentAllocs != length){
        printf("Memory allocated wrong during removeAtX\n");
        length = currentAllocs;
    }

    if(getData(&head, X-1) != before || getData(&head, X) != after){
        printf("removeAtX failed\n");
    }


    //test reverse

    //finding random value and checking to make sure it is in right spot after reversing
    X = rand()%length;
    value = getData(&head, X);

    reverse(&head);

    if(currentAllocs != length){
        printf("Memory allocated wrong during reverse\n");
        length = currentAllocs;
    }

    if(getData(&head, length-X-1) != value){
        printf("reverse failed\n");
    }

    //test destroy
    destroy(&head);

    if(currentAllocs != 0){
        printf("Some memory not freed during destroy method\n");
    }



    printf("End of errors\n");


    /*
    push(&head, 5);
    push(&head, 7);
    push(&head, 9);
    print(&head); // 9 7 5
    removeFromHead(&head);
    print(&head); // 7 5
    addAtX(&head, 1, 1);
    print(&head); // 7 1 5
    removeAtX(&head, 1);
    print(&head); // 7 5
    printf("Data at 1: %d\n", getData(&head, 1)); // 5
    printf("Sum of data: %d\n", sumData(&head)); // 12
    printf("Minimum: %d\n", getMin(&head)); // 5
    printf("Maximum: %d\n", getMax(&head)); // 7
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print(&head); // 1 2 3 7 5
    reverse(&head);
    print(&head); // 5 7 3 2 1
    destroy(&head);
    print(&head); // NULL
    */
}
