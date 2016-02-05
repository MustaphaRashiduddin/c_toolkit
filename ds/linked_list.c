#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};

Node *create(int data);
void push(Node *current, int data);
Node *walker(Node *current);
Node *dealloc(Node *current);
void print(Node *current);
void death_walker(Node *current, int data);
void del(Node **current, int data);

int main(int argc, char **argv) {
    double time_spent;

    Node *root = create(1);
    push(root, 3);
    push(root, 7);
    push(root, 11);
    push(root, 4);
    push(root, 7);
    push(root, 1024);
    del(&root, 1);
    del(&root, 3);
    del(&root, 1024);
    print(root);
    printf("\n");
    root = dealloc(root);

    return 0;
}

Node *create(int data)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->next = NULL;
    return current;
}

void push(Node *current, int data)
{
    current = walker(current);
    current->next = create(data);
}

Node *walker(Node *current)
{
    if (current->next != NULL) 
        current = walker(current->next);
    return current;
}

void print(Node *current)
{
    printf("*%d", current->data);
    if (current->next != NULL)
        print(current->next);
}

void del(Node **current, int data)
{
    if ((*current)->data == data) {
        Node *next = (*current)->next;
        free(*current);
        *current = next;
    } else {
        death_walker(*current, data);
    }
}

void death_walker(Node *current, int data) {
    if (current->next != NULL && current->next->data != data) {
        death_walker(current->next, data);
    } else if (current->next != NULL && current->next->data == data) {
        Node *next = current->next;
        current->next = next->next;
        free(next);
    } 
}

Node *dealloc(Node *current)
{
    if (current->next != NULL)
        free(dealloc(current->next));
    return NULL;
}
