#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define IN 1
#define HASHSIZE 101
struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval=0; *s != '\0';s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s,np->name)==0)
            return np;
    return NULL;
}
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { //not found
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else //already there
    free ((void *) np->defn); //free previous defn
    return (np->defn = strdup(defn)) == NULL ? NULL : np;
}
int main(){


    return 0;
}