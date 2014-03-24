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


void setId(location *loc, int id)
{
    loc->id = id;
}


int getId(location *loc, int id)
{
    return loc->id;
}


void setXPos(location *loc, double x)
{
    loc->x = x;
}


double getXPos(location *loc)
{
    return loc->x;
}


void setYPos(location *loc, double y)
{
    loc->y = y;
}


double getYPos(location *loc)
{
    return loc->y;
}
