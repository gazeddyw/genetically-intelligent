/* 
 * File:   parser.c
 * Author: Gareth Williams
 *
 * Created on 20 March 2014
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"


/**
 * Scan opened file to read the dimensionality (number of nodes)
 * of the current file.
 * 
 * @return 
 */
int parseTSPDimensionality(FILE *fp)
{
    bool dimensionRecord = false;
    char buffer[MAX_LINE_LENGTH];
    int dimen = 0;
    
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
    {
        char *str1, *str2, *token, *subtoken;
        char *delimiter = "\n";
        char *subdelim = ": ";
        int i;

        for (i = 0, str1 = buffer; ; i++, str1 = NULL)
        {
            token = strtok(str1, delimiter);
            if (token == NULL)
            {
                break;
            }
            
            for (str2 = token; ; str2 = NULL)
            {
                subtoken = strtok(str2, subdelim);
                if (subtoken == NULL)
                {
                    break;
                }
                if (dimensionRecord == true)
                {
                    // If dimensionality has been recorded, return it.
                    int dim = (int) strtol(subtoken, NULL, 0);
                    printf(" --> %d\n", dim);
                    return dim;
                }
                if (strncmp(subtoken, "DIMEN", 5) == 0)
                {
                    dimensionRecord = true;
                    printf(" --> %s\n", token);
                }
            }
            
        }
    }
    
    return 0;
}


/**
 * Parse the file opened by openFile function.
 * 
 * @param fp
 */
void parseTSPNodes(FILE *fp, location *locArray[])
{
    bool dimensionRecord = false;
    bool nodeRecord = false;
    char buffer[MAX_LINE_LENGTH];
    int locationCounter = 0;
    //location **locArray;
    
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
    {
        char *str1, *str2, *token, *subtoken;
        char *delimiter = "\n";
        char *subdelim = ": ";
        int i;

        for (i = 0, str1 = buffer; ; i++, str1 = NULL)
        {
            token = strtok(str1, delimiter);
            if (token == NULL)
            {
                break;
            }
            
            printf("Entering next line...\n");
            int count = 0;
            
            long id;
            double x;
            double y;
            for (str2 = token; ; str2 = NULL)
            {
                subtoken = strtok(str2, subdelim);
                if (subtoken == NULL)
                {
                    break;
                }
                if (nodeRecord == true)
                {
                    /*
                     * Adds the ID, X and Y coords to each struct in the 
                     * location array, on each pass of the outer for loop.
                     * Prints out the ID, X and Y coord on a separate line,
                     * one subtoken each time through the loop. 
                     */
                    switch (count)
                    {
                        case 0:
                            id = strtol(subtoken, NULL, 10);
                            //printf("%ld\n", locArray[i]->id);
                            break;
                        case 1:
                            x = strtod(subtoken, NULL);
                            //printf("%f\n", locArray[i]->x);
                            break;
                        case 2:
                            y = strtod(subtoken, NULL);
                            //printf("%f\n", locArray[i]->y);
                            locArray[locationCounter] = createLocation();
                            setLocationId(locArray[locationCounter], id);
                            setLocationXPos(locArray[locationCounter], x);
                            setLocationYPos(locArray[locationCounter], y);
                            locationCounter++;
                            break;
                    }
                    count++;
                }
                if (strncmp(subtoken, "NODE", 4) == 0)
                {
                    nodeRecord = true;
                }
            }   
        }
    }
}
