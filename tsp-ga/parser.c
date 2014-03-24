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
#include "location.h"


/**
 * Pass in file name from cmd-line and read it in.
 * 
 * @param fileName The file to be read in, const as it will not be modified.
 */
void openFile(const char *fileName)
{
    FILE *fp;
    char *path = malloc(sizeof(FILE_PATH) + sizeof(fileName));
    strcpy(path, FILE_PATH);
    strcat(path, fileName);
    
    if ((fp = fopen(path, "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("File %s opened\n", fileName);
        parseFile(fp);
    }
    
    location *city = createLocation();
    setXPos(city, 10.0);
    setYPos(city, 5.0);
    //printf("CITY CO-ORDINATES:\tX: %f\tY: %f\n", city->x, city->y);
    destroyLocation(city);
    
    free(path);
    fclose(fp);
}


/**
 * Parse the file opened by openFile function.
 * 
 * @param fp
 */
void parseFile(FILE *fp)
{
    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL)
    {
        //printf("%s", buffer);
        char *str1, *str2, *token, *subtoken;
        char *saveptr1, *saveptr2;
        char *delimiter = "\n";
        char *subdelim = ": ";
        int i;

        for (i = 1, str1 = buffer; ; i++, str1 = NULL)
        {
            token = strtok(str1, delimiter);
            if (token == NULL)
            {
                break;
            }
            
            //printf("%d: %s\n", i, token);
            //puts("");
            bool dimensionRecord = false;

            for (str2 = token; ; str2 = NULL)
            {
                subtoken = strtok(str2, subdelim);
                if (subtoken == NULL)
                {
                    break;
                }
                if (dimensionRecord == true)
                {
                    int dim = (int) strtol(subtoken, NULL, 0);
                    printf(" --> %d\n", dim);
                    dimensionRecord = false;
                }
                if (strcmp(subtoken, "DIMENSION") == 0)
                {
                    dimensionRecord = true;
                    printf(" --> %s\n", token);
                }
                
                
            }
        }
        
    }
    
}
