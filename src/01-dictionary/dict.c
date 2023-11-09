/**
 * Creating a Dictionary with specified types in C
 * by Bob Lee YX
 */
#include<stdio.h>
#include<stdlib.h>

/* Represents a Key value pair*/
typedef struct Item{ 
  size_t size;
  void* key;
  char* key_type;
  void* value;
  char* value_type;
} Item;

/* Check if a given key matches and returns the value */
void* getValue(Item* item, char* key){
  printf("%s\n", (char*)item->key);
  printf("%s\n", key);
  printf("%s\n", key == (char*)item->key ? "true" : "false");
  return item->value;
}

int main(void){
  Item* thing;
  size_t base_size = sizeof(Item) + sizeof(char*) * 2 + sizeof(char*) * 2; 
  thing = malloc(base_size);
  char* test_key = "key1";
  char* test_value = "value1";
  thing->key = test_key;
  thing->value =  test_value;
  getValue(thing, "key1");
  //Let's say we want to add a key 
  return 0;
}
