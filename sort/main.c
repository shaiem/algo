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
    printf("    --algo            Sort algorithm\n");
    /* TODO */
}

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
    
    while((ch = getopt_long(argc, argv, "h", opts, NULL)) != -1) {
        switch (ch) {
            case 0: 
                switch (lopt) {
                    case '1':
                        /* TODO */
                        break;
                    default:
                        break;
                }
                break;
            case 's':
                /* TODO */
                break;
            case 'h':
                print_help_info();
                break;
            default:
                break;
            }
    }

    return ret;
}