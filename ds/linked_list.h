#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include<stdlib.h>
typedef struct Node Node;
Node *create(void *data);
void push(Node *current, void *data);
Node *dealloc(Node *current);
void print(Node *current);
void del(Node **current, void *data);

#endif
