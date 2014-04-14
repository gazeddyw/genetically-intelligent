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
    long id;
    double x;
    double y;
}
location;


location* createLocation(void);
void destroyLocation(location *loc);

void setLocationId(location *loc, int id);
int getLocationId(location *loc, int id);

void setLocationXPos(location *loc, double x);
double getLocationXPos(location *loc);

void setLocationYPos(location *loc, double y);
double getLocationYPos(location *loc);


#ifdef	__cplusplus
}
#endif

#endif	/* LOCATION_H */

