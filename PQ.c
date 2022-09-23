#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>




//print in tree form?
void print(struct PQ * pq){
	for(int i = 0; i<((*pq).curSize); i++){
		printf("%d: %d\n", (*pq).queue[i].priority, (*pq).queue[i].data);
	}

} 

void add(int priority, int data, struct PQ * pq){
	int curSize = (*pq).curSize;
	int capacity = (*pq).capacity;

	//increase capacity if queue is full
	if(curSize >= capacity){
		//make new priority queue double the size
		struct PQ pqNew;
		pqNew.curSize = curSize;
		pqNew.capacity = capacity * 2;
		pqNew.queue = malloc(sizeof(struct PQNode) * (2*capacity));

		//copy over values
		for(int i = 0; i<curSize; i++){
			pqNew.queue[i] = (*pq).queue[i];
		}

		//free old queue
		free((*pq).queue);

		//printf("%d\n", pqNew.capacity);
		*pq = pqNew;
		//printf("%d/%d\n", (*pq).curSize, (*pq).capacity);

	}


	((*pq).queue[curSize]).priority = priority;
	((*pq).queue[curSize]).data = data;

	//bubble up
	int counter = curSize;
	while((*pq).queue[counter].priority < (*pq).queue[(counter-1)/2].priority){
		struct PQNode tmp = (*pq).queue[counter];
		(*pq).queue[counter] = (*pq).queue[(counter-1)/2];
		(*pq).queue[(counter-1)/2] = tmp;
		counter = (counter-1)/2;

	}


	(*pq).curSize++;


}

int peek (struct PQ * pq){
	return ((*pq).queue[0]).priority;
}

void removeNode(struct PQ * pq){
	(*pq).curSize--;
	(*pq).queue[0] = (*pq).queue[(*pq).curSize];
	int spot = 0;
	//enters loop if there is at least one child
	while(2*spot+1 < (*pq).curSize){
		//only one child, 2*spot+1 is range, 2*spot+2 is not
		if(2*spot+2 >= (*pq).curSize){
			if((*pq).queue[spot].priority <= (*pq).queue[2*spot+1].priority) break; //node is in right position (less than its only child)
			//swap with only child if larger
			struct PQNode tmp = (*pq).queue[spot];
			(*pq).queue[spot] = (*pq).queue[2*spot+1];
			(*pq).queue[2*spot+1] = tmp;

			spot = 2*spot+1;
		}

		//two children in range
		else{
			//current node is smaller or equal than both children (in the right place)
			if((*pq).queue[spot].priority <= (*pq).queue[2*spot+1].priority && (*pq).queue[spot].priority <= (*pq).queue[2*spot+2].priority){
				break;
			}

			//left child is smaller than right child (must be smaller than current node because at least one is smaller) swap with left
			else if((*pq).queue[2*spot+1].priority < (*pq).queue[2*spot+2].priority){
				struct PQNode tmp = (*pq).queue[spot];
				(*pq).queue[spot] = (*pq).queue[2*spot+1];
				(*pq).queue[2*spot+1] = tmp;

				spot = 2*spot+1;
			}
			//only remaining case is right child is smaller than left child and current node
			else{
				struct PQNode tmp = (*pq).queue[spot];
				(*pq).queue[spot] = (*pq).queue[2*spot+2];
				(*pq).queue[2*spot+2] = tmp;
				spot = 2*spot+2;
			}

		}
	}

}

void heapify(struct PQ * unsorted, int length){
	struct PQ pq;
	pq.curSize = 0;
	pq.capacity = length;
	pq.queue = malloc(sizeof(struct PQNode) * pq.capacity);
	for(int i = 0; i<length; i++){
		add((*unsorted).queue[i].priority, (*unsorted).queue[i].data, &pq);
	}

	//free old queue
	free((*unsorted).queue);

	*unsorted = pq;

}