/* 
 * File:   weighting.h
 * Author: gareth
 *
 * Created on 12 April 2014, 17:53
 */

#ifndef WEIGHTING_H
#define	WEIGHTING_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "location.h"

float calculateWeight(location *loc1, location *loc2);


#ifdef	__cplusplus
}
#endif

#endif	/* WEIGHTING_H */

