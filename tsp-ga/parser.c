/* 
 * File:   parser.c
 * Author: Gareth Williams
 *
 * Created on 20 March 2014
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "location.h"


/**
 * Pass in file name from cmd-line and read it in.
 * 
 * @param fileName The file to be read in, const as it will not be modified.
 */
void read_file(const char *fileName)
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
    }
    
    
    location *city = createLocation();
    setXPos(city, 10.0);
    setYPos(city, 5.0);
    printf("CITY CO-ORDINATES:\tX: %f\tY: %f\n", city->x, city->y);
    destroyLocation(city);
    
    free(path);
    fclose(fp);
}
