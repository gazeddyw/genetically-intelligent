/* 
 * File:   location.h
 * Author: gareth
 *
 * Created on 20 March 2014, 23:00
 */

#ifndef LOCATION_H
#define	LOCATION_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct
{
    int id;
    double x;
    double y;
}
location;


location* createLocation();
void destroyLocation(location *loc);

void setId(location *loc, int id);
int getId(location *loc, int id);

void setXPos(location *loc, double x);
double getXPos(location *loc);

void setYPos(location *loc, double y);
double getYPos(location *loc);


#ifdef	__cplusplus
}
#endif

#endif	/* LOCATION_H */

