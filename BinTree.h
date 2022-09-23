struct node
{
    int key;
    int data;
    struct node * left;
    struct node * right;
};

void add(struct node ** proot, int key, int data);
void printInOrder(struct node ** proot);
int hasKey(struct node ** proot, int key);
int valueAtKey(struct node ** proot, int key);
void changeValueAtKey(struct node ** proot, int key, int data);
void removeKey(struct node ** proot, int key);
void destroyTree(struct node ** proot);