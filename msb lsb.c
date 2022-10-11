#include <stdio.h>  /* needed to call prinf() and scanf() */

int msb(int n){
    int x = 1 << 31;
    int index = -1;

    for(int i = 0; i < 32; ++i){

        if (x & n){
            index = 31 - i;
            return index;
        }

        x = x >> 1;

    }
    return index;
}

int lsb(int n){
    int x = 1;
    int index = -1;

    for(int i = 0; i < 32; ++i){

        if (x & n){
            index = i;
            return index;
        }

        x = x << 1;

    }
    return index;
}

int main(){
    int n;

    printf("Enter a positive non-zero integer: \n");
    scanf("%d", &n);

    printf("\n%d", msb(n));
    printf("\n%d", lsb(n));

    printf("\n");

    return 0;
}