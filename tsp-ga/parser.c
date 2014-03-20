/* 
 * File:   parser.c
 * Author: Gareth Williams
 *
 * Created on 20 March 2014
 */


#include <stdio.h>
#include <string.h>
#include "parser.h"


void read_file(char *fileName)
{
    FILE *fp;
    char *path = strcat(FILE_PATH, fileName);
    
    if ((fp = fopen(path, "r")) != NULL)
    {
        printf("File opened\n");
    }
    else 
    {
        printf("Error opening file\n");
    }
    
}