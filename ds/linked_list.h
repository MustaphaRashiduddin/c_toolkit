typedef struct Node Node;
Node *create(int data);
void push(Node *current, int data);
Node *dealloc(Node *current);
void print(Node *current);
void del(Node **current, int data);
