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
    double x;
    double y;
} location;


location* createLocation();
void destroyLocation(location *loc);

void setXPos(location *loc, double x);
void setYPos(location *loc, double y);

double getXPos(location *loc);
double getYPos(location *loc);


#ifdef	__cplusplus
}
#endif

#endif	/* LOCATION_H */

