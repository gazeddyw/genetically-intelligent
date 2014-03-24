/* 
 * File:   location.h
 * Author: Gareth Williams
 *
 * Created on 20 March 2014
 */


#include <stdlib.h>
#include "location.h"


location* createLocation()
{
    location *loc = malloc(sizeof(location));
    
    return loc;
}


void destroyLocation(location *loc)
{
    free(loc);
}


void setXPos(location *loc, double x)
{
    loc->x = x;
}


void setYPos(location *loc, double y)
{
    loc->y = y;
}
