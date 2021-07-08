#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/hash.h"


ArregloChars shaHashing(ArregloChars msg){
/*
 * 1 - Covert each char of msg into decimal ascii code
 * 2 - Convert each decimal code into binary code
 * 3 - Store all the binaries together in array
 * 4 - convert to 512 bits array (sha-256)
 * 5 - 
 * */
    return msg;
}

nat charToAsciiValue(char a)
{
    return (int)a;
}

int * natToBinary(int value){
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


