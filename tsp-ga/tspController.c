/* 
 * File:   tspController.h
 * Author: gareth
 *
 * Created on 14 April 2014, 20:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chromosome.h"
#include "parser.h"
#include "tspController.h"
#include "weighting.h"


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
    
    double totalWeight = 0.0;
    for (int i = 0; i < (dimensionality - 1); i++)
    {
        double weight = calculateWeight(locationArray[i], locationArray[i+1]);
        printf("Location %d -> %d weight: %.3f\n", i, (i + 1), weight);
        totalWeight += weight;
    }
    printf("Total weight: %.3f\n", totalWeight);
    
    // NEED TO THINK ADOUT G.A. - SELECT RANDOM LOCATIONS TO ADD TO CHROMOSOMES
    chromosome *chromo = createChromosome(locationArray, 
            dimensionality, myFunc);
    
    // Free all locations in the 'chromo' chromosome.
    int i = 0;
    while(chromo != NULL)
    {
        printf("chromo: %d\tID: %ld\n", i, chromo->loc->id);
        chromosome *eraser = chromo;
        chromo = chromo->next;
        destroyChromosome(eraser);
        printf("chromo %d destroyed!\n", i++);
    }
    
    // Free all location nodes before exiting
    for (int i = 0; i < dimensionality; i++)
    {
        destroyLocation(locationArray[i]);
    }
    
    free(path);
    fclose(fp);
}


void myFunc(void)
{
    puts("COOL!");
}
