/* 
 * File:   chromosome.h
 * Author: gareth
 *
 * Created on 14 April 2014, 12:51
 */

#ifndef CHROMOSOME_H
#define	CHROMOSOME_H

#include "location.h"


#ifdef	__cplusplus
extern "C" {
#endif

//typedef struct locateNode chromosome;
typedef struct
{
    location *loc;
    location *next;
} chromosome;
    
    
chromosome* createChromosome(int dimension);
void destroyChromosome(chromosome *chromo);
void insertLocation(chromosome *chromo);
void deleteLocation(chromosome *chromo);


#ifdef	__cplusplus
}
#endif

#endif	/* CHROMOSOME_H */

