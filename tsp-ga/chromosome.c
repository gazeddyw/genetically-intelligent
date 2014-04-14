/* 
 * File:   chromosome.c
 * Author: gareth
 *
 * Created on 14 April 2014, 12:52
 */

#include <stdlib.h>
#include <stdio.h>
#include "chromosome.h"


chromosome* createChromosome(location *loc[], int dimension, void (*funcPtr)())
{
    chromosome *chromo = malloc(sizeof(chromosome));
    for (int i = 0; i < dimension; i++)
    {
        // Loop through entire locationArray in main, add location
        // to random position in chromosome (list of locations).
        
    }
    
    funcPtr();
    return chromo;
}


void destroyChromosome(chromosome *chromo)
{
    free(chromo);
}
