//C program to sort string based on string length.
#include<stdio.h>
#include<string.h>

void sortuj(void **lineptr, int n, int (*key)(void *)){
    int i,j,v;
    void *temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(key(lineptr[j])>key(lineptr[j+1])){
                temp=lineptr[j];
                lineptr[j]=lineptr[j+1];
                lineptr[j+1]=temp;
            }
        }
    }
}

int main()
{
    char *a[]={"aa","bbb","c","asdasdsd","adssdasdasd","a"};
//Sorting string based on length
/*    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strlen(a[j])>strlen(a[j+1]))
            {
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }*/
int n = 6, i;
    for(i=0;i<n;i++) {
        printf("%s\n",a[i]);
    }
    printf("\n");
    sortuj((void **) a, n, (int (*)(void *)) strlen);
    for(i=0;i<n;i++) {
        printf("%s\n",a[i]);
    }
    return 0;
}


