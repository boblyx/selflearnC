/**
 * ptr.c
 * Various pointer exercises
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * SOLDIER CLASS
 */
typedef struct{
    char* name;
    int height;
} Soldier;

Soldier newSoldier(char* name, int height){
    Soldier s;
    s.name = name;
    s.height = height;
    return s;
}

void expandParty(Soldier* soldiers, int current, int new){
    int total = current + new;
    printf("total members: %d\n", total);
    Soldier* soldier2 = realloc(soldiers, (total + 1) * sizeof(Soldier));
    soldiers = soldier2;
}

void joinParty(Soldier* soldiers, int cap, Soldier fng){
    expandParty(soldiers, cap, 1);
    printf("index: %d\n", cap);
    soldiers[cap] = fng;
}

int main(void){
    Soldier* soldiers = malloc(sizeof(Soldier));
    Soldier Boromir = newSoldier("Boromir", 193);
    Soldier Aragorn = newSoldier("Aragorn", 198);
    joinParty(soldiers, 0, Boromir);
    joinParty(soldiers, 1, Aragorn);
    printf("%s\n", soldiers[0]); // << Broken...
    return 0;
}
