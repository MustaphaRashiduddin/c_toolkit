#include <stdio.h>
#include "linked_list.h"

int main(int argc, char **argv) {
    double time_spent;
    
    char* n[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa",
        "Saif", "Ali", "Mahdi"
    };

    n[3] = "Bob";
    /*int n[] = {1,3,7,11,4,7,1024,21};*/
    Node *root = create(n[0]);
    push(root, n[1]);
    push(root, n[2]);
    push(root, n[3]);
    push(root, n[4]);
    push(root, n[5]);
    push(root, n[6]);
    push(root, n[7]);
    del(&root, n[0]);
    del(&root, n[1]);
    del(&root, n[7]);
    print(root);
    printf("\n");
    root = dealloc(root);

    return 0;
}
