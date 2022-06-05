#include <stdio.h>

struct element{
    int v;
    struct element *nastepny;
};

int liczba_elementow(struct element *eptr){
    int suma=0;
    while(eptr->nastepny !=NULL){
        suma++;
        eptr=eptr->nastepny;
    }
    return suma;
}

int main(){
    struct element e1 = {1, NULL};
    struct element e2 = {2, NULL};
    struct element e3 = {3, NULL};
    struct element e4 = {4, NULL};
    struct element e5 = {5, NULL};

    struct element *eptr = &e4;
    e1.nastepny = &e2;
    e2.nastepny = &e3;
    e3.nastepny = &e4;
    e4.nastepny = &e5;

    printf("\nLiczba elementow: %d\n\n", liczba_elementow(eptr));
}