#include <stdio.h>
#include "linked_list.h"

void print_string_node(Node *current);
void print_int_node(Node *current);
int main(int argc, char **argv) {
    double time_spent;
    
    /*char* n[] = {"Alan", "Frank", "Mary", "John", "Lisa", "Saif", "Ali", "Mahdi"};*/
    int n[] = {1, 3, 7, 11, 4, 7, 1024, 21};
    Node *root = create((void *)&n[0]);
    push(root, (void *)&n[1]);
    push(root, (void *)&n[2]);
    push(root, (void *)&n[3]);
    push(root, (void *)&n[4]);
    push(root, (void *)&n[5]);
    push(root, (void *)&n[6]);
    push(root, (void *)&n[7]);
    /*del(&root, (void *)&n[0]);*/
    /*del(&root, (void *)&n[1]);*/
    /*del(&root, (void *)&n[7]);*/
    print(root, print_int_node);
    printf("\n");
    root = dealloc(root);

    return 0;
}

// printing strings
void print_string_node(Node *current)
{
    printf("%s ", (char *)current->data);
}

// printing integers
void print_int_node(Node *current)
{
    printf("%d ", *(int *)current->data);
}
