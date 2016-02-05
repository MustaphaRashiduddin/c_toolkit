#include "sayf_memory.h"

typedef struct MallocedDataInfo MallocedDataInfo;
typedef struct Node Node;

struct MallocedDataInfo {
    // need memory address
    const char* file;
    const char* func;
    const int line;
    const size_t size;
    const int n;
    const char* id;
};

struct Node {
    void* data;
    Node* next;
};

void sayf_memory_start() {
    
}

void sayf_memory_end() {

}

void* malloc_and_log(const char* file, const char* func, const int line,
        const size_t size, const int n, const char* type) {
    void* p = malloc(sizeof(size*n));
    fprintf(stderr, "%s:%s:%d\n", file, func, line);
    printf("%s: %zu bytes | %d allocation(s) | block of %zu bytes not freed from %p\n", type, size, n, n*size, p);
    return p;
}
