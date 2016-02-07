#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node *walker(Node *current);
void death_walker(Node *current, void *data);

Node *create(void *data)
{
    Node *current = (Node *)malloc(sizeof(Node));
    current->data = data;
    current->next = NULL;
    return current;
}

void push(Node *current, void *data)
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

void print(Node *current, void (*ptr_print_node)(Node *current))
{
    ptr_print_node(current);
    if (current->next != NULL)
        print(current->next, ptr_print_node);
}

void del(Node **current, void *data)
{
    if ((*current)->data == data) {
        Node *next = (*current)->next;
        free(*current);
        *current = next;
    } else {
        death_walker(*current, data);
    }
}

void death_walker(Node *current, void *data) 
{
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
