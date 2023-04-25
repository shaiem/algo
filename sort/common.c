#include <stdio.h>
#include "common.h"

void dump_array(struct sort_data *sd)
{
    int i = 0;
    for (; i != sd->size; ++i) {
        if (i % 16 == 0)
            printf("\n");
        printf("%d\t", (sd->data)[i]);
    }
    printf("\n");
}