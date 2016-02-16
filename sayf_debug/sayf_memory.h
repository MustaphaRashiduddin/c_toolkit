#include <stdio.h>
#include <stdlib.h>

#define MALLOC(T, N) malloc_and_log(T, N, __FILE__, __LINE__, #T)

void sayf_memory_start();
void sayf_memory_end();

void *malloc_and_log(size_t size, int n, char *file, int line, char *type);
void sayf_memory_start(void); 
void sayf_memory_end(void);
void printer(void);
