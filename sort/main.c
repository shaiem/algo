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
#include <pthread.h>
#include "main.h"

void print_help_info(void)
{
    printf("Usage: sort [option] [args]\n");
   	printf("-h, --help            Print help info and exit\n");
    printf("-s, --size            Array size\n");
    printf("    --max             Specify the max number of array, default is 2147483647\n");
    printf("    --min             Specify the min number of array, default is -2147483648\n");
    printf("    --algo            Specify a sort algorithm, this parameter can be\n");
    printf("                      bubble, ...\n");
    /* TODO */
}

int prepare_random_array(struct sort_data *sd, int max, int min)
{
    int ret = 0;

    if ((!sd) || (max <= min)) 
        return -EFAULT;
    
    return ret;
}

static int lopt = 0;
static struct option opts[] = {
	{"size",	    required_argument,	NULL,	's'},
	{"algo",		required_argument,	&lopt,	'1'},
    {"max",		    required_argument,	&lopt,	'2'},
    {"min",		    required_argument,	&lopt,	'3'},
	{"help",		no_argument,		NULL,	'h'},
	{ /* Sentinel */ },
};

int main(int argc, char **argv)
{
    char ch = 0;
    int ret = 0;
    int max = 2147483647, min = -2147483648;
    struct sort_data *sd = NULL;

    sd = (struct sort_data *)malloc(sizeof(struct sort_data));
    if (!sd)
        return -ENOMEM;
    
    while((ch = getopt_long(argc, argv, "hs:", opts, NULL)) != -1) {
        switch (ch) {
            case 0: 
                switch (lopt) {
                    case '1':
                        /* TODO */
                        break;
                    case '2':
                        max = atoi(optarg);
                        break;
                    case '3':
                        min = atoi(optarg);
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

    ret = prepare_random_array(sd, max, min);
    if (ret < 0) {
        ret = -ENOMEM;
        goto fail_gen_arr;
    }
    
    free(sd);

fail_gen_arr:
    /* TODO */
    /* release array */
    if (sd)
        free(sd);

    return ret;
}