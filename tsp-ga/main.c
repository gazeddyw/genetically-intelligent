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
#include "weighting.h"


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
                if (strcmp("rand-int", longOpts[longIndex].name) == 0)
                {
                    globalArgs.randomize = 1;
                }
                else if (strcmp("version", longOpts[longIndex].name) == 0)
                {
                    displayVersion();
                }
                break;

            default:
                displayUsage();
                break;
        }
    }
    return (EXIT_SUCCESS);
}


/**
 * Pass in file name from cmd-line and read it in. Start main program execution.
 * 
 * @param fileName The file to be read in, const as it will not be modified.
 */
void runTSP(const char *fileName)
{
    FILE *fp;
    // +1 for NULL terminator '\0'
    char *path = malloc(sizeof(FILE_PATH) + sizeof(fileName) + 1);
    strcpy(path, FILE_PATH);
    strcat(path, fileName);

    if ((fp = fopen(path, "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    printf("File %s opened\n", fileName);
    int dimensionality = parseTSPDimensionality(fp);
    printf("Dimension: %d\n", dimensionality);
    
    // A pointer to an array of pointers to locations
    location *locationArray[dimensionality];
    
    parseTSPNodes(fp, locationArray);
    
    for (int i = 0; i < dimensionality; i++)
    {
        printf("CITY %ld CO-ORDINATES:\tX: %f\tY: %f\n",
                locationArray[i]->id, locationArray[i]->x, locationArray[i]->y);
    }
    
    for (int i = 0; i < (dimensionality - 1); i++)
    {
        double weight = calculateWeight(locationArray[i], locationArray[i+1]);
        printf("Location %d -> %d weight: %.3f\n", i, (i + 1), weight);
    }
    
    // NEED TO THINK ADOUT G.A. - SELECT RANDOM LOCATIONS TO ADD TO CHROMOSOMES
    
    
    // Free all location nodes before exiting
    for (int i = 0; i < dimensionality; i++)
    {
        destroyLocation(locationArray[i]);
    }
    
    free(path);
    fclose(fp);
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
