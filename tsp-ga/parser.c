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
 * Pass in file name from cmd-line and read it in.
 * 
 * @param fileName The file to be read in, const as it will not be modified.
 */
void openFile(const char *fileName)
{
    FILE *fp;
    // +1 for NULL terminator '\0'
    char *path = malloc(sizeof(FILE_PATH) + sizeof(fileName) + 1);
    strcpy(path, FILE_PATH);
    strcat(path, fileName);
    
    // A pointer to an array of pointers to locations
    location **locationArray;

    if ((fp = fopen(path, "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("File %s opened\n", fileName);
        locationArray = parseTSPFile(fp);
    }
    
    printf("CITY %ld CO-ORDINATES:\tX: %f\tY: %f\n",
            locationArray[5]->id, locationArray[5]->x, locationArray[5]->y);
    
    //for (int i = 0; i < )
    
    free(path);
    fclose(fp);
}


/**
 * Parse the file opened by openFile function.
 * 
 * @param fp
 */
location** parseTSPFile(FILE *fp)
{
    bool dimensionRecord = false;
    bool nodeRecord = false;
    char buffer[1024];
    int locationCounter = 0;
    location **locArray;
    
    while (fgets(buffer, 1024, fp) != NULL)
    {
        //printf("%s", buffer);
        char *str1, *str2, *token, *subtoken;
        char *saveptr1, *saveptr2;
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
                if (dimensionRecord == true)
                {
                    int dim = (int) strtol(subtoken, NULL, 0);
                    printf(" --> %d\n", dim);
                    locArray = malloc(sizeof(location) * dim);
                    printf(" --> size of location: %ld\n", sizeof(location));
                    printf(" --> size of locArray: %ld\n", 
                            (sizeof(location) * dim));
                    dimensionRecord = false;
                }
                if (strncmp(subtoken, "DIMEN", 5) == 0)
                {
                    dimensionRecord = true;
                    printf(" --> %s\n", token);
                }
                else if (strncmp(subtoken, "NODE", 4) == 0)
                {
                    nodeRecord = true;
                }
            }   
        }
    }
    printf("CITY %ld CO-ORDINATES:\tX: %f\tY: %f\n",
            locArray[0]->id, locArray[0]->x, locArray[0]->y);
    return locArray;
}
