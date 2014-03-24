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


#define FILE_PATH "/home/gareth/tsp/"


void openFile(const char *fileName);
void parseFile(FILE *fp);


#ifdef	__cplusplus
}
#endif

#endif	/* PARSER_H */

