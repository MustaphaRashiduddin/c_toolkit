#include <stdio.h>
#include <stdlib.h>

#define MALLOC(T, N) malloc_and_log(__FILE__, __func__, __LINE__, T, N, #T)

void sayf_memory_start();
void sayf_memory_end();

void* malloc_and_log(const char* file, const char* func, const int line,
        const size_t size, const int n, const char* type);
