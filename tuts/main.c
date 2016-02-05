#include <stdio.h>
#include <stdlib.h>

void my_malloc(void** p, size_t size);

int main(int argc, char** argv)
{
    int*** p3DimInt;
    my_malloc((void**)(&p3DimInt), sizeof(int**));
    int** p2DimInt;
    my_malloc((void**)(&p2DimInt), sizeof(int*));
    int* pInt;    
    my_malloc((void**)(&pInt), sizeof(int));
    *pInt = 5;
    *p2DimInt = pInt;
    *p3DimInt = p2DimInt;

    printf("%d\n", ***p3DimInt);

    free(pInt);
    free(p2DimInt);
    free(p3DimInt);

}

void my_malloc(void** p, size_t size)
{
    *p = malloc(size);
}
