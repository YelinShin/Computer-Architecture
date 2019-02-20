typedef struct node{
	int data;
	struct node *next;
} node;

void insert(struct node* newnode);
struct node* createnewnode (int data);
struct node* delete(int data);
void printList();