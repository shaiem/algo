#ifndef _MAIN_H
#define _MAIN_H

#define MAX     32768
#define MIN     0

#include <stdlib.h>

typedef int (*sort_func_t)(void *data);

struct sort_data {
    int *data;
    size_t size;
};

struct algo_func {
    char *name;
    sort_func_t sort;
};

extern int bubble_sort(void *data);

#endif  /* _MAIN_H */
