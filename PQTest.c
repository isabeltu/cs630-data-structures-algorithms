#include "PQ.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <limits.h>

int isHeap(struct PQ * pq);
int isHeapHelper(struct PQ * pq, int x);

int main(int argc, char ** argv){


	//TESTING

	printf("Errors found:\n");

	struct PQ pq;
	pq.curSize = 0;

	srand(time(0));
	int listLength = rand() % 100 + 1;

	pq.capacity = listLength;
	pq.queue = malloc(sizeof(struct PQNode) * pq.capacity);

	int min = INT_MAX; //keep track of minimum value added to check peek later

	//add more than listLength to test ability to resize heap
	for(int i = 0; i<listLength + 1; i++){
		
		int priority = rand();
		//value of data is irrelevant
		add(priority, 0, &pq);

		if(priority < min) min = priority;
	}

	//curSize should be listLength+1

	if(pq.curSize != listLength+1) printf("curSize parameter is incorrect\n");

	if(pq.capacity != listLength*2) printf("capacity not increased correctly\n");

	if(isHeap(&pq) != 1) printf("not added in heap order\n");

	//print(&pq);

	//printf("%d %d\n", min, peek(&pq));

	if(peek(&pq) != min) printf("peek did not return the smallest priority of the heap\n");

	removeNode(&pq);
	if(isHeap(&pq) != 1) printf("removing an element ruined heap order :(\n");

	//curSize should be listLength

	//ruin the heap by randomizing priorities
	for(int i = 0; i<listLength; i++){
		pq.queue[i].priority = rand();
	}

	//print(&pq);

	heapify(&pq, listLength);

	//print(&pq);
	//printf("%d\n", isHeap(&pq));

	if(isHeap(&pq) != 1) printf("heapify did not return queue to heap order\n");


	printf("End of errors\n");


	/*
	struct PQ pq;
	pq.curSize = 0;
	pq.capacity = 2;
	pq.queue = malloc(sizeof(struct PQNode) * pq.capacity);

	add(0,19,&pq);
	add(1,20,&pq);
	//printf("%d/%d\n", pq.curSize, pq.capacity);
	add(-1,90,&pq);
	//printf("%d/%d\n", pq.curSize, pq.capacity);
	print(&pq);
	printf("\n");
	//printf("%d\n", peek(&pq));
	removeNode(&pq);
	print(&pq);
	printf("\n");
	pq.queue[0].priority = 2;
	heapify(&pq, pq.curSize);
	print(&pq);
	*/


}

int isHeap(struct PQ * pq){
	return isHeapHelper(pq, 0);
}

int isHeapHelper(struct PQ * pq, int x){
	int curSize = (*pq).curSize;
	int capacity = (*pq).capacity;

	//if no children return true
	if(2*x+1 >= curSize) return 1;

	//if one child
	else if(2*x+2 >= curSize){
		//return true if that child is a heap and if it is larger than parent
		if(isHeapHelper(pq, 2*x+1) == 1 && (*pq).queue[2*x+1].priority > (*pq).queue[x].priority){
			return 1;
		}
	}

	//two children

	else{
		//return true if both children are heaps and if both children are larger than parent
		if(isHeapHelper(pq, 2*x+1) == 1 && (*pq).queue[2*x+1].priority > (*pq).queue[x].priority && isHeapHelper(pq, 2*x+2) == 1 && (*pq).queue[2*x+2].priority > (*pq).queue[x].priority){
			return 1;
		}
	}

	return 0;
}