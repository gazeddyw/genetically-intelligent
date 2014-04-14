/* 
 * File:   chromosome.c
 * Author: gareth
 *
 * Created on 14 April 2014, 12:52
 */

#include <stdlib.h>
#include "chromosome.h"


chromosome* createChromosome(int dimension)
{
    chromosome *chromo = malloc(sizeof(chromosome));
    for (int i = 0; i < dimension; i++)
    {
        // Loop through entire locationArray in main, add location
        // to random position in chromosome (list of locations).
    }
    
    return chromo;
}


void destroyChromosome(chromosome *chromo)
{
    
}
