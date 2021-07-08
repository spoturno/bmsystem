#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/hash.h"


ArregloChars shaHashing(ArregloChars msg){

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


