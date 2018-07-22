#include <stdio.h>

enum size_t {
    small,
    medium,
    big
} sizes;

typedef struct {
    enum sizes size;
    float power;
    char supplier[30];
} Bulb;


int main(){
    Bulb bulbs[50];

    Bulb a = {small, 40, "electricity inc. "};
    Bulb *p;

    /*
     *  p = bulbs;
     *  p = *a;
     *  if (bulbs[10]->power == p->power)
     *      printf("OK");
     *  strcpy(a.supplier, bulbs->supplier);
     *  a.size = big;
     *
     *
     * */

    return 0;
}

void printBulb(Bulb b);

void printGoodBulbs(Bulb *bulbs, int size, float power){
    int i;

    for (i=0; i<size; i++){
        if (bulbs[i].power == power){
            printBulb(bulbs[i]);
        }
    }
}
