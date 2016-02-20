#include <stdio.h>
#include <string.h>
#include "linked_list.h"

/*The sole purpose of this main.c file is to test the linked list*/

void print_str_node(struct Node *current);
void print_int_node(struct Node *current);
void free_node(struct Node *n);
int cmp_int(void *dat, void *cmp);
int cmp_str(void *dat, void *cmp);
void delstat(int);
int main() {
        char* n[] = {"Alan", "Frank", "Mary", "John", "Lisa", "Saif", "Ali", "Mahdi"};
        /*int n[] = {1, 3, 7, 11, 4, 7, 1024, 21};*/
        struct Node *root = create(n[0]);
        push(root, n[1]);
        push(root, n[2]);
        push(root, n[3]);
        /*del(&root, n[2], cmp_str);*/
        push(root, n[4]);
        push(root, n[5]);
        push(root, n[6]);
        push(root, n[7]);
        /*del(&root, n[0], cmp_str);*/
        /*del(&root, n[1], cmp_str, free_node);*/
        delstat(del(&root, n[0], cmp_str, free_node));
        delstat(del(&root, n[0], cmp_str, free_node));
        delstat(del(&root, n[4], cmp_str, free_node));
        /*delstat(del(&root, "boom", cmp_str, free_node));*/
        /*delstat(del(&root, n[3], cmp_str, free_node));*/
        /*del(&root, n[6], cmp_str);*/
        /*del(&root, n[5], cmp_str);*/
        print(root, print_str_node);
        printf("\n");
        root = dealloc(root, free_node);
        return 0;
}

void delstat(int del)
{
        del ? printf("deleted\n") : printf("not found\n");
}

int cmp_int(void *dat, void *cmp)
{
        return (*(int *)dat == *(int *)cmp);
}

int cmp_str(void *dat, void *cmp)
{
        int val = strcmp((char *)dat, (char *)cmp);
        /*printf("%s ?= %s | val = %d\n", (char *)dat, (char *)cmp, val);*/
        return (val == 0) ? 1 : 0;
}

// do nothing
void free_node(struct Node *n)
{
        n = NULL;
}

// printing strings
void print_str_node(struct Node *current)
{
        printf("%s ", (char *)current->data);
}

// printing integers
void print_int_node(struct Node *current)
{
        printf("%d ", *(int *)current->data);
}
