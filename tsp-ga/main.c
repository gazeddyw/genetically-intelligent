/* 
 * File:   main.c
 * Author: Gareth Williams
 *
 * Created on 20 March 2014, 15:51
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "parser.h"


// Struct to store command line options
struct globalArgs_t
{
    char *fileName; /* -d option */
    char **inputFiles; /* input files */
    int numOfInputFiles; /* # of input files */
    int randomize; /* --randomize option */
}
globalArgs;

// option string
static const char *optString = "f:h";

// Array of option structs to hold info about long options supported
static const struct option longOpts[] = {
    { "file-name", required_argument, NULL, 'f' },
    { "rand-int", no_argument, NULL, 0 },
    { "help", no_argument, NULL, 'h' },
    { NULL, no_argument, NULL, 0 }
};


// Function Declarations
void display_usage();


/*
 * 
 */
int main(int argc, char *argv[]) {

    int opt;
    int longIndex;

    while((opt = getopt_long(argc, argv, optString,
                                longOpts, &longIndex)) != -1)
    {
        switch (opt)
        {
        case 'f':
            globalArgs.fileName = optarg;
            printf("-f selected\n");
            printf("File name is: %s\n", globalArgs.fileName);
            read_file(globalArgs.fileName);
            break;

        case 'h': /* fall-through intentional */
        case '?':
            display_usage();
            break;

        case 0: /* long option without a short equivalent */
            if (strcmp("rand-int", longOpts[longIndex].name) == 0)
            {
                globalArgs.randomize = 1;
            }
            break;

        default:
            break;
        }
    }
    return (EXIT_SUCCESS);
}


void display_usage(void)
{
    puts("tsp - A program using a genetic algorithm to solve TSP problems.");
    exit(EXIT_FAILURE);
}
