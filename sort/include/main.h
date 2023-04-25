#ifndef _MAIN_H
#define _MAIN_H

typedef int (*sort)(void *data);

struct sort_data {
    int data[];
    size_t size;
}

#endif  /* _MAIN_H */