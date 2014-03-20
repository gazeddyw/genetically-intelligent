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


/**
 * 
 * @param fileName The file to be read in
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
    }
    printf("File %s opened\n", fileName);
    
    free(path);
    fclose(fp);
}