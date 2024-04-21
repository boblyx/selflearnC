/**
 * ptr3.c
 * Yet another attempt to realloc
 */

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int numbers[4] = {0,1,2,3};
    // Need to cast int*[4] to int* !
    int* numptr = (int*)&numbers;
    numptr = malloc(sizeof(int)*5);
    numptr[4] = 4;
    int* otherptr = realloc(numptr, sizeof(int)*6);
    printf("Done. %d\n", otherptr[4]);
    free(otherptr); // Only need to free the realloc pointer. No need to free numptr.
}
