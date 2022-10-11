#include <stdio.h>  /* needed to call prinf() and scanf() */

void printArray(int a[], int size){

    printf("Index\tValue");
    
    for (int i =0; i < size; ++i){
        printf("\n    %d\t    %d", i, a[i]);
    }
    printf("\n");
}

void printStars(int n){
    int empty = 10 - n;
    for(int i = 0; i < empty; ++i){
        printf(" ");
    }

    for(int i = 0; i < n; ++i){
        printf("*");
    }

    printf("\n");
}

void arrayHistogram(int a[], int size){
    int frequency1 = 0, frequency2 = 0, frequency3 = 0;

    for(int i = 0; i < size; ++i){
        if(a[i] == 1){
            ++frequency1;
        }
        else if (a[i] == 2){
            ++frequency2;
        }
        else{
            ++frequency3;
        }
    }

    printf("Value Frequency Histogram\n");
    printf("    1%9d", frequency1);
    printStars(frequency1);
    printf("    2%9d", frequency2);
    printStars(frequency2);
    printf("    3%9d", frequency3);
    printStars(frequency3);


}

void swapValues(int a[], int i1, int i2){
    int temp = a[i1];
    a[i1] = a[i2];
    a[i2] = temp;
}

void bubbleSort(int a[], int size){
    int bo = 1;

    while(bo){
        bo = 0;
        for(int i = 0; i < size - 1; ++i){
            if(a[i] > a[i+1]){
                swapValues(a, i, i+1);
                bo = 1;
            }
        }
    }
}

int median(int a[], int size){

    int b[size];
    for(int i = 0; i < size; ++i){
        b[i] = a[i];
    }
    bubbleSort(b, size);
    return b[size/2];
}

int mode(int a[], int size){

    int frequency1 = 0, frequency2 = 0, frequency3 = 0;

    for(int i = 0; i < size; ++i){
        if(a[i] == 1){
            ++frequency1;
        }
        else if (a[i] == 2){
            ++frequency2;
        }
        else{
            ++frequency3;
        }
    }

    if(frequency1 < frequency2){
        if(frequency2 < frequency3){
            return 3;
        }
        else{
            return 2;
        }
    }
    else{
        if(frequency1 < frequency3){
            return 3;
        }
        else{
            return 1;
        }
    }
}

int isSorted(int a[], int size){
    for(int i = 0; i < size - 1; ++i){
        if(a[i] > a[i+1]){
            return 0;
        }
    }
    return 1;
}


int main(){
    int size = 10;
    int a[] = {1,3,2,3,1,2,2,3,2,1};

    printArray(a, size);

    arrayHistogram(a, size);

    swapValues(a, 1, 8);

    printf("%d\n", median(a, size));

    printf("%d\n", isSorted(a, size));

    printArray(a, size);

    bubbleSort(a, size);

    printf("%d\n", isSorted(a, size));

    printArray(a, size);

    printf("%d\n", mode(a, size));


    return 0;
}



