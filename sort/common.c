/*
 * @file: main.c
 * @note: This file defines the interfaces which other source file might use.
 * @author: shaiem
 * 
 * @version: 0.1     init version
 * @date: 2023/4/26
 */

#include <stdio.h>
#include "common.h"

void dump_array(struct sort_data *sd)
{
    int i = 0;
    printf("%d\t", (sd->data)[i]);
    for (i= 1; i != sd->size; ++i) {
        if (i % 16 == 0)
            printf("\n");
        printf("%d\t", (sd->data)[i]);
    }
    printf("\n");
}