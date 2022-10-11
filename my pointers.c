#include <stdio.h>  /* needed to call prinf() and scanf() */
#include <string.h>
# define _countof(array) (sizeof(array)/sizeof(array[0]))

int compare(char ** a1, char ** a2){
     char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
     char * a = &alphabet[0];

     int bo = 1;
     int counter = -1;
     int c = 0;

    while(bo && c < 5){
        ++c;

        if(**a1 == '\0'){
            return 1;
        }
        else if (**a2 == '\0'){
            return 0;
        }
        else{
            for(int i = 0; i < 26; ++i){
                ++counter;
                if(**a1 == *a){
                    if(**a2 == *a){
                        ++*a1;
                        ++*a2;
                        break;
                    }
                    else{
                        return 1;
                    }
                }
                else if (**a2 == alphabet[i]){
                    return 0;
                }
                ++a;
            }
        }
        a -= counter;
        counter=-1;
    }
    
    return bo;
}

char** merge(char *a1[], char *a2[], int sizeA, int sizeB){
    int totalSize = sizeA + sizeB;
    char *result = (char *)malloc((totalSize)*sizeof(char *));

    for(int i=0; i<totalSize; i++){
        result[i] = (char *)malloc(10 * sizeof(char));
    }

    int counterA1 = 0, counterA2 = 0;

    for(int i =0; i < totalSize; ++i){

        if(compare(a1, a2) == 1){ // a1 is before a2
            strcpy(result[i], a1[counterA1]);
            ++counterA1;

        }
        else{
            strcpy(result[i], a1[counterA2]);
            ++counterA2;
        }
    }
    return result;
}


int main(){
    char * a1[] ={"ab", "abc"}; 
    char * a2[] = {"mabcd", "zb", "zz"};

    char** r = merge(a1, a2, 2, 3);

    for(int i = 0; i < 5; ++i){
        printf("%d%9s\n", i, r[i]);
    }

}
