/* 
 * File:   parser.h
 * Author: Gareth Williams
 *
 * Created on 20 March 2014, 16:12
 */

#ifndef PARSER_H
#define	PARSER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "location.h"

#define FILE_PATH "/home/gareth/tsp/"
#define MAX_LINE_LENGTH 127


int parseTSPDimensionality(FILE *fp);
void parseTSPNodes(FILE *fp, location *locArray[]);


#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_H */

