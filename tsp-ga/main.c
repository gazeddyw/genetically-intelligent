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


// Struct to store command line options
struct globalArgs_t
{
    char *fileName; /* -f option */
    char **inputFiles; /* input files */
    int numOfInputFiles; /* # of input files */
    int randomize; /* --randomize option */
}
globalArgs;

// option string
static const char *optString = "f:hv";

// Array of option structs to hold info about long options supported
static const struct option longOpts[] = {
    { "file-name", required_argument, NULL, 'f' },
    { "rand-int", no_argument, NULL, 0 },
    { "help", no_argument, NULL, 'h' },
    { "verbose", no_argument, NULL, 'v' },
    { "version", no_argument, NULL, 0 },
    { NULL, no_argument, NULL, 0 }
};


// Function Declarations
void displayUsage(void);
void displayVersion(void);
void runTSP(const char *fileName);


/*
 * 
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
        displayUsage();

    int opt;
    int longIndex;

    while((opt = getopt_long(argc, argv, optString,
                                longOpts, &longIndex)) != -1)
    {
        switch (opt)
        {
            case 'v':
                printf("Verbose mode!\n");
                break;
                
            case 'f':
                globalArgs.fileName = optarg;
                printf("-f selected\n");
                printf("File name is: %s\n", globalArgs.fileName);
                runTSP(globalArgs.fileName);
                break;

            case 'h': /* fall-through intentional */
            case '?':
                displayUsage();
                break;

            case 0: /* long option without a short equivalent */
                if (strcmp("version", longOpts[longIndex].name) == 0)
                {
                    displayVersion();
                }
                else if (strcmp("rand-int", longOpts[longIndex].name) == 0)
                {
                    globalArgs.randomize = 1;
                }
                break;

            default:
                displayUsage();
                break;
        }
    }
    return (EXIT_SUCCESS);
}


void displayUsage(void)
{
    puts("tsp-ga - A genetic algorithm to solve TSP problems.\n");
    puts("usage: tsp-ga [-f <filename>]");
    exit(EXIT_FAILURE);
}


void displayVersion(void)
{
    puts("tsp-ga: v0.9");
    exit(EXIT_SUCCESS);
}
