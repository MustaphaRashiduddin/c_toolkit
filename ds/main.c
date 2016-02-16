#include <stdio.h>
#include "linked_list.h"

/*The sole purpose of this main.c file is to test the linked list*/

void print_string_node(struct Node *current);
void print_int_node(struct Node *current);
int main() {
    
    char* n[] = {"Alan", "Frank", "Mary", "John", "Lisa", "Saif", "Ali", "Mahdi"};
    /*int n[] = {1, 3, 7, 11, 4, 7, 1024, 21};*/
    struct Node *root = create(n[0]);
    push(root, n[1]);
    push(root, n[2]);
    push(root, n[3]);
    push(root, n[4]);
    push(root, n[5]);
    push(root, n[6]);
    push(root, n[7]);
    /*del(&root, n[0]);*/
    /*del(&root, n[1]);*/
    /*del(&root, n[7]);*/
    print(root, print_string_node);
    printf("\n");
    root = dealloc(root);

    return 0;
}

// printing strings
void print_string_node(struct Node *current)
{
    printf("%s ", (char *)current->data);
}

// printing integers
void print_int_node(struct Node *current)
{
    printf("%d ", *(int *)current->data);
}
