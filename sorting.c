#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print(int a [], int length);
void insertionSort(int a [], int length);
int isSorted(int a [], int length);
void merge(int a[], int start, int middle, int end);
void mergeHelper(int a [], int start, int end);
void mergeSort(int a [], int length);
int pivot(int a[], int start, int end);
void quickHelper(int a[], int start, int end);
void quickSort(int a [], int length);
void heapify(int a[], int length, int root);
void heapSort(int a[], int length);
void randomize(int a[], int length);


int main(int argc, char const *argv[])
{
	//int a [10] = {1,0,2,3,9,4,5,8,7,6};
	//insertionSort(a, 10);
	//mergeHelper(a, 0, 10);
	//mergeSort(a, 10);
	//quickSort(a, 10);
	//heapSort(a, 10);
	//print(a, 10);
	//printf("%d\n", isSorted(a, 10));
	int n = 1048576;
	int a[n];

	//print(a, n);


	randomize(a, n);
	clock_t t = clock();
	insertionSort(a, n);
	t = clock()-t;
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	if(isSorted(a, n) != 1) printf("INSERTION SORT FAILED\n");
	printf("insertion sort took %f seconds\n", time_taken);
	
	randomize(a, n);
	t = clock();
	quickSort(a, n);
	t = clock()-t;
	time_taken = ((double) t)/CLOCKS_PER_SEC;
	if(isSorted(a, n) != 1) printf("QUICK SORT FAILED\n");
	printf("quick sort took %f seconds\n", time_taken);
	
	randomize(a, n);
	t = clock();
	mergeSort(a, n);
	t = clock()-t;
	time_taken = ((double) t)/CLOCKS_PER_SEC;
	if(isSorted(a, n) != 1) printf("MERGE SORT FAILED\n");
	printf("merge sort took %f seconds\n", time_taken);
	

	randomize(a, n);
	t = clock();
	heapSort(a, n);
	t = clock()-t;
	time_taken = ((double) t)/CLOCKS_PER_SEC;
	if(isSorted(a, n) != 1) printf("HEAP SORT FAILED\n");
	printf("heap sort took %f seconds\n", time_taken);

}

void randomize(int a[], int length){
	srand(time(0));
	for(int i = 0; i<length; i++){
		a[length] = rand();
	}
}

void insertionSort(int a [], int length){
	for(int i = 0; i<length; i++){
		int j = i;
		while(j>0 && a[j] < a[j-1]){
			int temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j--;
		}
	}

}

void heapify(int a[], int length, int root){
	int max = root;
	int left = 2*root+1;
	int right = 2*root+2;
	if(left<length && a[left] > a[max]){
		max = left;
	}
	if(right<length && a[right] > a[max]){
		max = right;
	}
	int tmp = a[root];
	a[root] = a[max];
	a[max] = tmp;

	if(max != root) heapify(a, length, max);


}

void heapSort(int a[], int length){
	for(int i = length/2 - 1; i>-1; i--){
		heapify(a, length, i);
	}

	for(int i = length-1; i>-1; i--){
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		heapify(a, i, 0);
	}

}

void merge(int a[], int start, int middle, int end){

	
	int length1 = middle-start+1;
	int a1[length1];
	for(int i = 0; i<length1; i++){
		a1[i] = a[start+i];
	}

	int length2 = end-middle;
	int a2[length2];
	for(int i = 0; i<length2; i++){
		a2[i] = a[middle+i+1];
	}

	int read1 = 0;
	int read2 = 0;
	int write = start;

	while(read1<length1 && read2<length2){
		if(a1[read1] < a2[read2]){
			a[write] = a1[read1];
			read1++;
			write++;
		}
		else{
			a[write] = a2[read2];
			read2++;
			write++;
		}
	}

	for(int i = read1; i<length1; i++){
		a[write] = a1[i];
		write++;
	}

	for(int i = read2; i<length2; i++){
		a[write] = a2[i];
		write++;
	}
}


void mergeHelper(int a [], int start, int end){
	if(start<end){

		int middle = start + (end-start)/2;

		mergeHelper(a, start, middle);
		mergeHelper(a, middle+1, end);

		merge(a, start, middle, end);


	}
	
}

void mergeSort(int a [], int length){
	mergeHelper(a, 0, length);
}


int pivot(int a[], int start, int end){
	int pivot = a[end];
	int pivotPlace = start-1;
	for(int i = start; i<end; i++){
		if(a[i] < pivot){
			pivotPlace++;
			int tmp = a[i];
			a[i] = a[pivotPlace];
			a[pivotPlace] = tmp;
		}

	}

	pivotPlace++;
	int tmp = a[pivotPlace];
	a[pivotPlace] = a[end];
	a[end] = tmp;

	return pivotPlace;

}

void quickHelper(int a[], int start, int end){
	if(start<end){
		int p = pivot(a, start, end);
		quickHelper(a, start, p-1);
		quickHelper(a, p+1, end);
	}
}


void quickSort(int a [], int length){
	quickHelper(a, 0, length-1);

}

void print(int a [], int length){
	for(int i = 0; i<length; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");
}

int isSorted(int a [], int length){
	for(int i = 0; i<length-1; i++){
		if(a[i] > a[i+1]) return 0;
	}
	return 1;
}
