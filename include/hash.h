
#ifndef _HASH_H
#define _HASH_H

#include "./utils.h"

/*
 * returns the hashed string of msg using the sha-256 algorithm
 */
ArregloChars shaHashing(ArregloChars msg);

/*
 * returns the ascii value of a (decimal value)
 */
nat charToAsciiValue(char a);

/*
 * convert the value (decimal) into his binary [1,0,1,1]
 */
ArregloNats natToBinary(nat value);


//meaby a function of union of arrays.

#endif


