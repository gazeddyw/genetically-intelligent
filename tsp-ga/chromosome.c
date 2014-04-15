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
    // Initialise empty chromosome of length = dimension first?
    chromosome *first;
    chromosome *current = malloc(sizeof(chromosome));
    for (int i = 0; i < dimension; i++)
    {
        // Loop through entire locationArray in main, add location
        // to random position in chromosome (list of locations).
        
        if (i == 0)
        {
            first = current;
        }
        // Got lost here... Stuck.
        current->index = i;
        current->loc = loc[i];
        if (i < (dimension - 1))
        {
            current->next = malloc(sizeof(chromosome));
            current = current->next;
        }
        else if (i == (dimension - 1))
        {
            current->next = NULL;
        }
    }
    
    funcPtr();
    return first;
}


void destroyChromosome(chromosome *chromo)
{
    free(chromo);
}


void insertLocation(chromosome *chromo, location *loc)
{
    // Insert the location into a random place
    // in the chromosome (location list).
}
