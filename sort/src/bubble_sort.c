#include <stdio.h>
#include "main.h"
#include "common.h"
   

int bubble_sort(void *data)
{
    int ret = 0;
    int i = 0, j = 0;
    int tmp = 0;
    struct sort_data *sd = (struct sort_data *)data;
    
    for (i = 0; i < sd->size - 1; ++i) {
        for (j = 0; j != sd->size - 1-i; ++j) {
            if ((sd->data)[j] > (sd->data)[j+1]) {
                tmp = (sd->data)[j];
                (sd->data)[j] = (sd->data)[j+1];
                (sd->data)[j+1] = tmp;
            }
        }
    }
    
    return ret;
}
