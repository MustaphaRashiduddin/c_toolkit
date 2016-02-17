#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>
struct Node {
        void *data;
        struct Node *next;
};

struct Node *create(void *data);
void push(struct Node *current, void *data);
struct Node *dealloc(struct Node *current, void (*free_node)(struct Node *));
void print(struct Node *current, void (*ptr_print_node)(struct Node *current));
void del(struct Node **root, void *data, int (*comp)(void *node, void *dat), void (*free_node)(struct Node *));

#endif
