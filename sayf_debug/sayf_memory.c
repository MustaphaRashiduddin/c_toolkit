#include "string.h"
#include "sayf_memory.h"
#include "../ds/linked_list.h"

struct Node *root;

struct MallocedDataInfo {
    void *p;
    char *file;
    int line;
    size_t size;
    int n;
    char *type;
};

/*void sayf_memory_start(); */
void print_node(struct Node *cur);
char *getstr_m(char *s);
struct MallocedDataInfo *init_malloced_data_info(void *p, size_t size, int n, char *file, int line, char *type);
void free_node(struct Node *cur);

struct MallocedDataInfo *init_malloced_data_info(void *p, size_t size, int n, char *file, int line, char *type)
{
    struct MallocedDataInfo *init = NULL;
    init = malloc(sizeof(struct MallocedDataInfo));

    if (init) {
        init->p = p;
        init->file = getstr_m(file);
        init->line = line;
        init->size = size;
        init->n = n;
        init->type = getstr_m(type);
    } else {
        printf("fail");
        exit(1);
    }

    return init;
}

void sayf_memory_start() 
{
    root = NULL;
}

void sayf_memory_end() 
{
    root = dealloc(root, free_node);
}

char *getstr_m(char *s) 
{
    char *p = malloc(strlen(s)+1);
    if (p) strcpy(p, s);
    return p;
}

void print_node(struct Node *cur)
{
    struct MallocedDataInfo *dat = cur->data;
    printf("%s:%d | %p | %zu byte unit | %d allocations | %d bytes allocated | %s\n",
            dat->file, dat->line, dat->p, dat->size, dat->n, (int)dat->size * dat->n, dat->type);
}

void printer()
{
    print(root, print_node);
}

void *malloc_and_log(size_t size, int n, char *file, int line, char *type) 
{
    void *p = malloc(sizeof(size*n));
    struct MallocedDataInfo *dat = init_malloced_data_info(p, size, n, file, line, type);

    if (root == NULL)
        root = create(dat); 
    else
        push(root, dat);

    return p;
}

void free_node(struct Node *cur)
{
    struct MallocedDataInfo *dat = cur->data;
    free(dat->type);
    free(dat->file);
    free(dat);
}

int comp_mallocedData(void *p1, void *p2);

void free_and_log(void *p)
{
    del(&root, p, comp_mallocedData);
    free(p);
}

int comp_mallocedData(void *malloced_dat, void *p) {
    struct MallocedDataInfo *dat = malloced_dat;
    /*printf("%p ?= %p\n", dat->p, p);*/
    return (dat->p == p);
}
