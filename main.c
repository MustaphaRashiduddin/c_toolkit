#include "sayf_debug/sayf_memory.h"

int main(int argc, char **argv)
{
    int *pNum = (int *)MALLOC(sizeof(int), 2);
    /*printf("%p---\n", pNum);*/
    char *l = (char *)MALLOC(sizeof(char), 3);
    /*printf("%p---\n", l);*/
    *pNum = 3;
    free(pNum);
    free(l);
    return 0;
}
