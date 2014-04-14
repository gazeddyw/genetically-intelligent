/* 
 * File:   tspController.h
 * Author: gareth
 *
 * Created on 14 April 2014, 20:19
 */

#ifndef TSPCONTROLLER_H
#define	TSPCONTROLLER_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * The controller for the G.A.
 * It expects the filename of a TSP file to be used in the program. 
 * 
 */
void runTSP(const char *fileName);
void myFunc(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TSPCONTROLLER_H */

