
#ifndef _HASH_H
#define _HASH_H

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
void sha256_transform(SHA256_CTX *ctx, const BYTE data[]);


#endif


