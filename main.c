#include "sayf_debug/sayf_memory.h"
#include "ds/linked_list.h"

int main()
{
        sayf_memory_start();

        int *pNum = MALLOC(sizeof(int), 2);
        char *l = MALLOC(sizeof(char), 3);
        float *sorry = MALLOC(sizeof(float), 31);


        /**pNum = 3;*/
        FREE(pNum);
        /*free(pNum);*/
        FREE(l);
        /*free(l);*/
        FREE(sorry);

        double *dvar = MALLOC(sizeof(double), 100);
        free(dvar);
        printer();
        sayf_memory_end();
        return 0;
}
