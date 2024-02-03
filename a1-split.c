
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXLINE     132
#define MAX_NTOKEN  MAXLINE
#define MAXWORD     32

// ------------------------------
int split(char inStr[],  char token[][MAXWORD], char fs[])
{
    int    i, count;
    char   *tokenp, inStrCopy[MAXLINE]; 

    // initialize variables
    count= 0;
    memset (inStrCopy, 0, sizeof(inStrCopy));
    for (i=0; i < MAX_NTOKEN; i++) memset (token[i], 0, sizeof(token[i]));

    // make a backup of inStr in inStrCopy
    strcpy (inStrCopy, inStr);

    if ( (tokenp= strtok(inStr, fs)) == NULL) return(0);
    
    strcpy(token[count],tokenp); count++;

    while ( (tokenp= strtok(NULL, fs)) != NULL)
    {
        strcpy(token[count],tokenp); count++;
    }

     strcpy (inStr, inStrCopy);		// restore inStr
     return(count);	   
}

// ------------------------------
int main (int argc, char *argv[])
{
    // test with
    // char token[MAX_NTOKEN][MAXWORD];
    // char inStr[]= "timeout 10 do_work bash.man 7";
    // ...

    printf ("Test function split()\n");

}
