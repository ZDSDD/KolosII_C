#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Function to print an array */
void printArray(char *arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}
void sortuj(void **lineptr, int n, int (*key)(void *)){
    int i,j;
    char temp[20];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(key(lineptr[j])>key(lineptr[j+1]))
            {
                strcpy(temp,lineptr[j]);
                strcpy(lineptr[j],lineptr[j+1]);
                strcpy(lineptr[j+1],temp);
            }
        }
    }
}
// Driver program to test above functions
int main()
{
    char *tekst[] = {"aa", "bbb", "c"};
    int n = 3;
    sortuj((void **) tekst, n, (int (*)(void *)) strlen);
    printf("Sorted array: \n");
    printArray(tekst, n);
    return 0;
}
