#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 3;
    void *data = &x;
    printf("%d\n", *(int *)data);
    
    return 0;
}
