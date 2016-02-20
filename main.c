#include "sayf_debug/sayf_memory.h"
#include "ds/linked_list.h"

int main()
{
        START();
        ////////////////////////

        int r = 3;
        int c = 4;

        int **arr = MALLOC(sizeof(int *), r);
        for (int i=0; i<r; i++)
                arr[i] = MALLOC(sizeof(int), c);

        int count = 0;
        for (int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                        arr[i][j] = ++count;

        for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++)
                        printf("%d ", arr[i][j]);
                printf("\n");
        }

        for (int i=0; i<r; i++) {
                FREE(arr[i]);
                arr[i] = NULL;
        }
        FREE(arr);
        
        ////////////////////////
        REPORT();
        END();
        return 0;
}
