#include <bits/stdint-intn.h>
#include <stdio.h>
#include <stdint.h>

void endian();

// int main(void) recommended practice in c
int main(){
    int16_t i = 1;
    int8_t *p = (int8_t *) &i;
    if(p[0] == 1) printf("Little Endian\n");
    else printf("Big Endian\n");
    endian();
    return 0;
}

void endian(){
    union{
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;
    if(sizeof(short) == 2){
        if(un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");
        else if(un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else printf("unknwon\n");
    } else{
        printf("sizeof(short) = %lu\n", sizeof(short));
    }
}




