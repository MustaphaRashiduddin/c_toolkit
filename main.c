#include "sayf_debug/sayf_memory.h"
#include "ds/linked_list.h"

int main()
{
    sayf_memory_start();

    int *pNum = MALLOC(sizeof(int), 2);
    char *l = MALLOC(sizeof(char), 3);
    /*float *sorry = MALLOC(sizeof(float), 1);*/

    printer();

    /**pNum = 3;*/
    free(pNum);
    free(l);

    sayf_memory_end();

    return 0;
}
