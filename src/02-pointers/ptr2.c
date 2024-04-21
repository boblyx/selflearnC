/**
 * ptr.c
 * Various pointer exercises
 * 2024/04/21 - Fixed!
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

Soldier* expandParty(Soldier* soldiers, int current, int new){
    int total = current + new;
    printf("total members: %d\n", total);
    Soldier* soldier2 = realloc(soldiers, (total + 1) * sizeof(Soldier));
    return soldier2;
}

Soldier* joinParty(Soldier* soldiers, int cap, Soldier fng){
    Soldier* new_soldiers = expandParty(soldiers, cap, 1);
    printf("index: %d\n", cap);
    new_soldiers[cap] = fng;
    return new_soldiers;
}

int main(void){
    Soldier* soldiers = malloc(sizeof(Soldier));
    Soldier Boromir = newSoldier("Boromir", 193);
    Soldier Aragorn = newSoldier("Aragorn", 198);
    soldiers = joinParty(soldiers, 0, Boromir);
    soldiers = joinParty(soldiers, 1, Aragorn);
    printf("%s\n", soldiers[0]);
    free(soldiers);
    return 0;
}
