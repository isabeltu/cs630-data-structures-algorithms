struct node
{
    int data;
    struct node * next;
};

int currentAllocs;

void push(struct node ** head, int data);
void print(struct node ** head);
void removeFromHead(struct node ** head);
void addAtX(struct node ** head, int data, int x);
void removeAtX(struct node ** head, int x);
int getData(struct node ** head, int x);
int sumData(struct node ** head);
int getMin(struct node ** head);
int getMax(struct node ** head);
void reverse(struct node ** head);
void destroy(struct node ** head);