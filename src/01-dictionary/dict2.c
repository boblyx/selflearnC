/**
 * dict.c
 * Creating a string dictionary in C.
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

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

typedef struct {
    char* values[9999];
    char* collisions[];
} HashTable;

typedef struct {
    const char* key;
    void* value;
} DictItem;

typedef struct {
    DictItem* items; // Contains all collisions
    size_t size;
    size_t count;
} Dict;

Dict* cDict(void){
    Dict* dict = malloc(sizeof(Dict));
    dict->count = 0;
    dict->size = 16;
    dict->items = calloc(dict->count, sizeof(DictItem));
    if(dict->items == NULL){
        free(dict);
        return NULL;
    }
    return dict;
}

void fDict(Dict* dict){

    for(size_t i = 0; i < dict->count; i++){
        free((void*)dict->items[i].key);
    }
    free(dict->items);
    free(dict);
}

unsigned long qBucket(unsigned long num){
    unsigned long count = 0;
    while (num != 0)
    {
        num = num/16;
        count++;
    }
    return count;
}

void aDict(Dict* dict, char* key, void* value){
    unsigned long h = hash(key);
    unsigned long id = qBucket(h);
    dict->count += 1;
    dict->items[id].key = malloc(sizeof(char*));
    dict->items[id].key = key;
    dict->items[id].value = malloc(sizeof(void*));
    dict->items[id].value = value;
}

void* qDict(Dict* dict, char* key){
    unsigned long h = hash(key);
    unsigned long id = qBucket(h);
    printf("%lu\n",id);
    printf("%s\n",dict->items[id].key);
    if(dict->items[id].key != key){
        return "";
    }
    void* out = dict->items[id].value;
    return out;
}


int main(void){

    Dict* dict = cDict();
    aDict(dict, "test", "test");
    aDict(dict, "otherrrr", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed et libero mollis, aliquet tortor vel, fermentum justo. Donec quis placerat urna. Sed convallis odio sit amet ipsum pretium faucibus. Etiam quis dolor est. Sed pretium nunc quis augue lacinia, sed tristique lacus dictum. Morbi facilisis lorem id mauris iaculis sodales. In ut ante interdum, ornare est ut, commodo nisl. Etiam lacinia eget odio at placerat. Mauris aliquet elementum urna ut lacinia. Vivamus posuere nibh arcu, sit amet congue libero sodales id. Nunc elementum est sed tincidunt blandit.");
    char* out = qDict(dict, "test");
    printf("%s\n",out);
    fDict(dict);
}
