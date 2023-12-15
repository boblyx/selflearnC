/**
 * dict.c
 * Creating a string dictionary in C.
 * - Hash function hashes an input string into a unsigned long
 * - Use another fuction `getBuckets` that:
 *      - Determine the n-th factor of 2^16 the hash belongs to.
 *      - Determine the p-th index on the n-th factor it belongs to.
 * - Using above information place the user supplied value into 
 *   the n-th bucket at the p-th index.
 * - Do the same thing to retrieve the value.
 * - TODO: Handle collisions.
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/**
 * Custom made hash function.
 * Probably performs badly but who cares.
 */
unsigned long hash(char* str){
    int c = 0;
    unsigned long hash = 13;

    while( c = *str++){
        hash = ((hash * 41) + hash)/37 + c;
    }
    return hash;
}

/**
 * Gets the super bucket as explained above.
 */
int* getSuperBuckets(unsigned long num){
    int count = 0;
    while( num > 65536){
        num = num/65536;
        ++count;
    }
    static int out[2];
    out[0] = count;
    out[1] = (int)num;
    return out;
}

/**
 * SuperBucket definition.
 * As a hard limit, only 2^16 values allowed per bucket.
 * TODO: Each value in values is to contain a list
 * which will store collisions.
 */
typedef struct SuperBucket{
    char* values[65536]; // List of items.
    char* collisions[];
} SuperBucket;

/**
 * Dict definition.
 * Stores multiple buckets.
 * Based on tests, there will only be 4 buckets max.
 */
typedef struct Dict{
    SuperBucket buckets[4];
} Dict;

void dictAdd(Dict* d, char* key, char* value){
    unsigned long h = hash(key);
    int* bdata = getSuperBuckets(h);
    int bnum = bdata[0];
    int bid = bdata[1];
    //char* testo[2] = {"derp", "dreep"};
    //d->buckets[bnum].collisions[bid] = *testo;
    d->buckets[bnum].values[bid] = malloc(sizeof(char*));
    d->buckets[bnum].values[bid] = value;
}

char* dictFind(Dict d, char* key){
    unsigned long h = hash(key);
    int* bdata = getSuperBuckets(h);
    int bnum = bdata[0];
    int bid = bdata[1];
    char* out = d.buckets[bnum].values[bid];
    return out;
}

int main(void){
    Dict testi;
    dictAdd(&testi, "derp", "dorp");
    dictAdd(&testi, "darp", "durp");
    char* result = dictFind(testi, "derp");
    char* result2 = dictFind(testi, "darp");
    printf("%s\n", result);
    printf("%s\n", result2);
}
