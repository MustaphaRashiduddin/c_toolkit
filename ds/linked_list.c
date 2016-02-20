#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node *walker(struct Node *current);
int death_walker(struct Node *current, void *data, int (*comp)(void *node, void *dat), void (*free_node)(struct Node *node));

struct Node *create(void *data)
{
        struct Node *current = malloc(sizeof(struct Node));
        current->data = data;
        current->next = NULL;
        return current;
}

void push(struct Node *current, void *data)
{
        current = walker(current);
        current->next = create(data);
}

struct Node *walker(struct Node *current)
{
        if (current->next != NULL) 
                current = walker(current->next);
        return current;
}

void print(struct Node *current, void (*ptr_print_node)(struct Node *current))
{
        if (current != NULL) {
                ptr_print_node(current);
                if (current->next != NULL)
                        print(current->next, ptr_print_node);
        } else {
                printf("*EMPTY*");
        }
}

int del(struct Node **root, void *data, int (*comp)(void *node, void *dat), void (*free_node)(struct Node *node))
{
        if (*root == NULL) return 0;
        if (comp((*root)->data, data)) {
                if ((*root)->next != NULL) {
                        struct Node *next = (*root)->next;
                        free_node(*root);
                        free(*root);
                        *root = next;
                        return 1;
                } else {
                        free_node(*root);
                        free(*root);
                        *root = NULL;
                        return 1;
                }
        } else {
                return (death_walker(*root, data, comp, free_node));
        }
}

int death_walker(struct Node *current, void *data, int (*comp)(void *node, void *dat), void (*free_node)(struct Node *node))
{
        if (current->next != NULL && !comp(current->next->data, data)) {
                return (death_walker(current->next, data, comp, free_node));
        } else if (current->next != NULL && comp(current->next->data, data)) {
                struct Node *next = current->next;
                current->next = next->next;
                free_node(next);
                free(next);
                return 1;
        } 
        return 0;
}

struct Node *dealloc(struct Node *current, void (*free_node)(struct Node *))
{
        if (current != NULL) {
                if (current->next != NULL) {
                        dealloc(current->next, free_node);
                }
                free_node(current);
                free(current);
        }
        return NULL;
}
