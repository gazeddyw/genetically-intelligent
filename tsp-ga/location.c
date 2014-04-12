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


void setLocationId(location *loc, int id)
{
    loc->id = id;
}


int getLocationId(location *loc, int id)
{
    return loc->id;
}


void setLocationXPos(location *loc, double x)
{
    loc->x = x;
}


double getLocationXPos(location *loc)
{
    return loc->x;
}


void setLocationYPos(location *loc, double y)
{
    loc->y = y;
}


double getLocationYPos(location *loc)
{
    return loc->y;
}
