
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
int * natToBinary(int value);

/*
 * returns the union of ar_1[] and ar_2[]
 */
int * unionOfArray(int ar_1[], int ar_2[]);


//meaby a function of union of arrays.

#endif


