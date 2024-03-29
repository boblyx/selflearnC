/**
 * Creating a list of strings in C
 * by Bob Lee YX
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct List{
  size_t size; /* Memory size of the List instance */
  int num; /* Number of items in the instance */
  char* items[]; /* Actual pointers to the strings Flexible Array member must be declared last*/
} List;

List* newList(void){
  List* list;
  list = malloc(sizeof(list) + sizeof(int));
  list->size = sizeof(list);
  return list;
}

//void dList(List* list){}

List* add(List* list, char* item){
  printf("Start add\n");
  List* w = newList(); /* malloc(sizeof(list) + sizeof(List) + sizeof(char*) + sizeof(int)); */
  w = malloc(sizeof(char*));
  printf("\t@func input list->size: %zu\n", list->size);
  int num = list->size / sizeof(char*);
  printf("\tNo. items in input list: %d\n", num);
  for(int i = 0; i < list->num; ++i){
    w->items[i] = list->items[i]; 
    printf("\t\tAdd item %d to new list\n", i);
  }
  w->items[num] = item;
  printf("\t\tAdd item %d to new list\n", num);
  w->num = num+1;
  printf("\tNo. items in new list: %d\n", w->num);
  printf("End add\n\n");
  return w;
}

int main(void){
  char* yup[] = {"item1", "item2", "item3"};
  printf("@main input list->size: %zu\n", sizeof(yup));
  List* test = newList();
  test = malloc(sizeof(yup) + sizeof(List));
  int count = sizeof(yup)/sizeof(char*);
  for(int i = 0; i < count; i++){
    test->items[i] = yup[i];
  }
  test->size = sizeof(yup);
  test->num = count;
  List* thing = add(test, "item4");
  printf("New list:\n");
  for(int i = 0; i < thing->num; ++i){
    printf("\t-%s\n", thing->items[i]);
  }
  dList(thing);
  free(thing);
  free(test);
  return 0;
}
