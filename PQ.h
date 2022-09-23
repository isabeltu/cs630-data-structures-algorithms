struct PQ{
	int curSize;
	int capacity;
	struct PQNode * queue;
};

struct PQNode{
	int priority;
	int data;
};

void print(struct PQ * pq);
void add(int priority, int data, struct PQ * pq);
int peek (struct PQ * pq);
void removeNode(struct PQ * pq);
void heapify(struct PQ * unsorted, int length);