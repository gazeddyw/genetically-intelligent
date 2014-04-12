/* 
 * File:   weighting.c
 * Author: gareth
 *
 * Created on 12 April 2014, 17:54
 */

#include <math.h>
#include "weighting.h"


double calculateWeight(location *loc1, location *loc2)
{
    // NEED TO ADD -lm OPTION TO LINKER IN ORDER TO LINK pow() AND sqrt()
    // X2 + Y2 = Z2
    // Z = SQRT(X2 + Y2)
    double x = (loc2->x - loc1->x);
    double y = (loc2->y - loc1->y);
    x = pow(x, 2);
    y = pow(y, 2);
    double z = x + y;
    z = sqrt(z);
    
    return z;
}
