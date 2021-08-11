#include <stdio.h>
#define INT_BITS 32

int leftRotate(int n, unsigned int d){
    return (n << d) | (n >> (INT_BITS - d));
}

int rightRotate(int n, unsigned int d){
    return (n >> d) | (n << (INT_BITS - d));
}

int main(){
    int n = 16;
    int d = 2;
    printf("Left Rotation of %d by %d is: ", n, d);
    printf("%d\n", leftRotate(n, d));
    printf("Right Rotation of %d by %d is: ", n, d);
    printf("%d\n", rightRotate(n, d));
    getchar();
    return 0;
}
