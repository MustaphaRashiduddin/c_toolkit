#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node *walker(struct Node *current);
/*void death_walker(struct Node *current, void *data);*/
void death_walker(struct Node *current, void *data, int (*comp)(void *node, void *dat));

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

/*void del(struct Node **current, void *data)*/
/*{*/
    /*if ((*current)->data == data) {*/
        /*struct Node *next = (*current)->next;*/
        /*free(*current);*/
        /**current = next;*/
    /*} else {*/
        /*death_walker(*current, data);*/
    /*}*/
/*}*/
void del(struct Node **root, void *data, int (*comp)(void *node, void *dat))
{
    if (comp((*root)->data, data)) {
        if ((*root)->next != NULL) {
            struct Node *next = (*root)->next;
            free(*root);
            *root = next;
        } else {
            free(*root);
            *root = NULL;
        }
    } else {
        death_walker(*root, data, comp);
    }
}
/*void death_walker(struct Node *current, void *data) */
/*{*/
    /*if (current->next != NULL && current->next->data != data) {*/
        /*death_walker(current->next, data);*/
    /*} else if (current->next != NULL && current->next->data == data) {*/
        /*struct Node *next = current->next;*/
        /*current->next = next->next;*/
        /*free(next);*/
    /*} */
/*}*/
void death_walker(struct Node *current, void *data, int (*comp)(void *node, void *dat))
{
    if (current->next != NULL && !comp(current->next->data, data)) {
        death_walker(current->next, data, comp);
    } else if (current->next != NULL && comp(current->next->data, data)) {
        struct Node *next = current->next;
        current->next = next->next;
        free(next);
    } 

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
