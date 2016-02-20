#ifndef SAYF_MEMORY_H
#define SAYF_MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#ifndef NDEBUG
#define START() sayf_memory_start()
#define END() sayf_memory_end()
#define MALLOC(T, N) malloc_and_log(T, N, __FILE__, __LINE__, #T)
#define FREE(T) free_and_log(T, __FILE__, __LINE__)
#define REPORT() printer()
#else
#define START() rawstart();
#define END() rawend();
#define MALLOC(T, N) malloc_only(T, N)
#define FREE(T) free_only(T)
#define REPORT() print_nothing();
#endif

void rawstart(void);
void rawend(void);
void *malloc_only(size_t size, int n);
void free_only(void *p);
void print_nothing(void);

void sayf_memory_start(void); 
void sayf_memory_end(void);
void *malloc_and_log(size_t size, int n, char *file, int line, char *type);
void free_and_log(void *p, char *file, int line);
void printer(void);

#endif
