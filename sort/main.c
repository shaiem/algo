/*
 * @file: main.c
 * @note: This file is just for testing different sort algorithms, the specific implement refers to src directory.
 * @author: shaiem
 * 
 * @version: 0.1     init version
 * @date: 2023/4/25
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "main.h"
#include "common.h"

static struct algo_func algo[] = {
    { .name = "bubble", .sort = bubble_sort},
    { /* Sentinel */ },
};

void print_help_info(void)
{
    printf("Usage: sort [option] [args]\n");
   	printf("-h, --help            Print help info and exit\n");
    printf("-s, --size            Array size\n");
    printf("    --max             Specify the max number of array, default is 2147483647\n");
    printf("    --min             Specify the min number of array, default is -2147483648\n");
    printf("    --algo            Specify a sort algorithm, this parameter can be\n");
    printf("                      bubble, ...\n");
}

int prepare_random_array(struct sort_data *sd)
{
    int ret = 0;
    int i = 0;
    struct timespec time;
    if (!sd) 
        return -EFAULT;

    sd->data = (int *)malloc(sizeof(int)*(sd->size));
    if (!sd->data) {
        return -ENOMEM;
    }
    
    for (; i != sd->size; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &time);
        srand(time.tv_nsec);
        (sd->data)[i] = rand() % (MAX - MIN + 1) + MIN;
    }
    
    return ret;
}

sort_func_t sort_init(char *name)
{
    int i = 0;
    for (; algo[i].name != NULL; ++i) {
        if (!strcmp(name, algo[i].name))
            return algo[i].sort;
    }
    return NULL;
}

static int lopt = 0;
static struct option opts[] = {
	{"size",	    required_argument,	NULL,	's'},
	{"algo",		required_argument,	&lopt,	'1'},
	{"help",		no_argument,		NULL,	'h'},
	{ /* Sentinel */ },
};

int main(int argc, char **argv)
{
    char ch = 0;
    int ret = 0;
    struct sort_data *sd = NULL;
    sort_func_t sort;

    sd = (struct sort_data *)malloc(sizeof(struct sort_data));
    if (!sd)
        return -ENOMEM;
    
    while((ch = getopt_long(argc, argv, "hs:", opts, NULL)) != -1) {
        switch (ch) {
            case 0: 
                switch (lopt) {
                    case '1':
                        sort = sort_init(optarg);
                        break;
                    default:
                        break;
                }
                break;
            case 's':
                sd->size = atoi(optarg);
                break;
            case 'h':
                print_help_info();
                break;
            default:
                break;
            }
    }

    ret = prepare_random_array(sd);
    if (ret < 0) {
        ret = -ENOMEM;
        goto fail_gen_arr;
    }
    dump_array(sd);

    ret = sort(sd);
    dump_array(sd);
    
    if (sd->data) 
        free(sd->data);
    if (sd)
        free(sd);
    return ret;

fail_gen_arr:
    if (sd->data)
        free(sd->data);
    if (sd)
        free(sd);

    return ret;
}
