 /*************************************************
 * Filename: hash.cpp
 * Author: Tomas Spoturno
 * Copyright: 
 * Disclaimer: This code is presented "as is" without any guarantees.
 * Details: Implementation of sha-256 algorithm. sha-256 is one of the
 *          three algorithms of sha-2 specification. Algorithm specification
 *          can be found on README.md
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../include/hash.h"




static const WORD K[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};


//==== IMPLEMENT THIS ====
/*   void printFileContents();
*    int calcFileSize();
*    void endianCheckPrint();
*    _Bool endianCheck();
*    int fillMessageBlock();
*    void calculateHash(FILE *file);
*    int nextMessageBlock(FILE *file, union messageBlock *msgBlock, enum status *state, __uint64_t *numBits);
*/

nat charToAsciiValue(char a)
{
    return (int)a;
}

int * natToBinary(int value){
    // fix 
    static int res[10];
    for(nat i=0;value>0;i++){
        res[i] = value%2;
        value=value/2;
    }
    return res;
}

int * unionOfArray(int *ar_1, int *ar_2){
    static int res[sizeof(ar_1) + sizeof(ar_2)];
    int i, j;
    for(i = 0; i<sizeof(ar_1); i++){
        res[i] = ar_1[i];
    }
    for(j = 0;  j< sizeof(ar_2); j++){
        res[i] = ar_2[j];
        i++;
    }
    return res;
}

int *paddingMessage(int *msg){
    int lenght = sizeof(msg);
    int * lenghtInBinary = natToBinary(lenght);
    static int res[512];
    // calling unionOfArray we loose the index
    for (int i=0; i < 512; i++){
        if(i == lenght)
            res[i] = 1;
        if(i > lenght){
            if(i >= 512 - lenght -1){
                res[i] = lenghtInBinary[i];
            }else
                res[i] = 0;    
        }else
            res[i] = msg[i];
    }
    return res;
}



void someShit(){
    // declared K constants of sha-256

}
