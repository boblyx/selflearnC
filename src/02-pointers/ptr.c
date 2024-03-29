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

Soldier* newSoldier(char* name, int height){
    Soldier* s = malloc(sizeof(Soldier));
    s->name = name;
    s->height = height;
    return s;
}

void rS(Soldier* soldier){
    printf("Soldier %s is %d tall.\n", soldier->name, soldier->height);
}

/* END SOLDIER CLASS */

/* UNIT CLASS */
typedef struct{
    char* name;
    Soldier* soldiers; // may contain any number of soldiers
    size_t count;
} Unit;

Unit* newUnit(char* name, Soldier soldiers[], size_t strength){
    Unit* u = malloc(sizeof(Unit));
    if(strength == 0){ u->soldiers = NULL;};
    //u->soldiers = calloc(strength, sizeof(Soldier)); << Malloc not needed!
    u->name = name;
    u->count = strength;
    u->soldiers = soldiers;
    return u;
}

void addSoldiers(Unit* u, Soldier soldiers[], size_t strength){
    if(strength == 0){return;};
    size_t p_count = u->count;
    size_t new_count = strength + p_count;
    char message[50] = "";
    Soldier* prev = calloc( p_count , sizeof(Soldier));
    memcpy(prev, u->soldiers, sizeof(Soldier) * p_count);
    //u->soldiers = realloc(u->soldiers, new_count * sizeof(Soldier)); /// << DOESN'T WORK...
    //u->soldiers = malloc( new_count * sizeof(Soldier));
    u->soldiers = calloc( new_count, sizeof(Soldier));
    for(int i =0; i < p_count; i++){
        u->soldiers[i] = prev[i];
    }
    for(int i =0; i < strength; i++){
        u->soldiers[p_count + i] = soldiers[i];  
        strcat(message, soldiers[i].name);
        strcat(message, ", ");
    }
    u->count = new_count;
    free(prev);
    printf("%sjoined the %s!\n", message, u->name);
}

void rU(Unit* unit){
    if(unit->count == 0){
        printf("The %s has no members...\n", unit->name);
        return;
    }
    printf("The %s has the following members:\n", unit->name);
    for(size_t i = 0; i < unit->count; ++i){
        printf("\t - %s\n" , unit->soldiers[i].name);
    }
    return;
}

void dUnit(Unit* u){
    // Free the soldiers first
    //free(u->name);
    free(u->soldiers);
    //free(u);
}

/* END UNIT CLASS */

/* COMPANY CLASS */

typedef struct{
    Unit* units;
    size_t count;
} Company;

/* END COMPANY */

/* ARMY */
typedef struct{
    Company* companies;
    size_t count;
} Army;

/* END ARMY */

int main(void){
    
    Soldier soldiers[] = {
        {"Boromir", 193}
        ,{"Aragorn", 198}
        ,{"Legolas", 183}
        ,{"Gimli", 137}
    };

    size_t strength = sizeof(soldiers)/sizeof(Soldier);

    rS(soldiers);
    printf("%d\n", strength);

    //Soldier nobodies[0]; // How to handle empty arrays?

    Unit* fellowship = newUnit("Fellowship of the Ring", soldiers, strength);
    rU(fellowship);

    Soldier new_soldiers[] = {
        {"Frodo", 124}
        ,{"Samwise", 125}
    };
    
    addSoldiers(fellowship, new_soldiers, sizeof(new_soldiers)/sizeof(Soldier));
    rU(fellowship);
    dUnit(fellowship);
    //rU(fellowship);
    free(fellowship);
    return 0;
}
