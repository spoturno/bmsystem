
#ifndef _HASH_H
#define _HASH_H

#include "./utils.h"
#include <stddef.h>

#define SHA256_BLOCK_SIZE 32

/**************** DATA TYPES ****************/
typedef unsigned char BYTE; // 8-bit byte
typedef unsigned int WORD; // 32-bit word, change to "long"

typedef struct{
    BYTE data[64];
    WORD lenght;
    unsigned long long bitlenght;
    WORD state[8];
} SHA256_CTX;

//to implement
void sha256_init(SHA256_CTX * ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);

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

/*
 * returns the message with the correct padding acording with the sha-256 algorithm 
*/
int *paddingMessage(int *msg);

//meaby a function of union of arrays.

#endif


