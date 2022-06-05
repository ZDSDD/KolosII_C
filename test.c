#include <stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
int i = 0;
printf("Podano parametry: ");
    for(i=1; i<argc; i++){
        printf(" %.2f",atof(argv[i]));
    }

    return 0;
}