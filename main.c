#include "sayf_debug/sayf_memory.h"

int main(int argc, char** argv)
{
    int* pNum = MALLOC(sizeof(int), 2);
    /*printf("%p---\n", pNum);*/
    char* l = MALLOC(sizeof(char), 3);
    /*printf("%p---\n", l);*/
    *pNum = 3;
    free(pNum);
    return 0;
}
