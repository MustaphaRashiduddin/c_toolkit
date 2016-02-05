#include <stdio.h>
#include "linked_list.h"

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
