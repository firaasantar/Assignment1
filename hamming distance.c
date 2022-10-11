#include <stdio.h>  /* needed to call prinf() and scanf() */

int distance(int n1, int n2){
    int x = n1 ^ n2;
    int d = 0;

    while(x > 0){
        d += x & 1;
        x >>= 1;
    }

    return d;
}

int main(){
    int b = 1;
    int n1, n2, d;

    while(b){
        printf("\n Please enter 2 positive numbers seperated by a space or a negative number to stop: \n");
        scanf("%d", &n1);

        if(n1 < 0){
            b = 0;
            break;
        }

        scanf("%d", &n2);

        d = distance(n1, n2);
        printf("\n %d", d);
    }

    return 0;
}

