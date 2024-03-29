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
int* getBuckets(unsigned long num){
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

typedef struct {
    const char* key;
    char* value;
} DictValue;

/**
 * Bucket definition.
 * As a hard limit, only 2^16 values allowed per bucket.
 * TODO: Each value in values is to contain a list
 * which will store collisions.
 */
typedef struct Bucket{
    DictValue* values; // List of items.
    size_t count;
} Bucket;

/**
 * Dict definition.
 * Stores multiple buckets.
 */
typedef struct Dict{
    Bucket* buckets;
    size_t count;
    size_t cap;
} Dict;

Dict* cDict(void){
    Dict* dict = malloc(sizeof(Dict));
    dict->count = 0;
    dict->cap = 1000;
    dict->buckets = calloc(dict->cap, sizeof(Bucket));
    if(dict->buckets == NULL){
        free(dict);
        return NULL;
    }
    return dict;
}

DictValue* nDictValue(char* key, char* value){
    DictValue* dv = malloc(sizeof(DictValue));
    dv->key = key;
    dv->value = value;
    return dv;
}

void dictAdd(Dict* d, char* key, char* value){
    unsigned long h = hash(key);
    int* bdata = getBuckets(h);
    int bnum = bdata[0];
    int bid = bdata[1];
    printf("%d\n", bid);
    d->buckets[bnum].values = calloc(65535, sizeof(DictValue*));
    d->buckets[bnum].values[bid].value = "test";
}

char* dictFind(Dict* d, char* key){
    unsigned long h = hash(key);
    int* bdata = getBuckets(h);
    int bnum = bdata[0];
    int bid = bdata[1];
    printf("%d\n", bid);
    char* out = d->buckets[bnum].values[bid].value;
    return out;
}

int main(void){
    Dict* testi = cDict();
    dictAdd(testi, "derp", "dorp");
    dictAdd(testi, "darp", "durp");
    char* result = dictFind(testi, "derp");
    //char* result2 = dictFind(testi, "darp");
    printf("%s\n", result);
    //printf("%s\n", result2);
}
