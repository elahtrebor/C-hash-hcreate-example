#include <stdio.h>
#include <search.h>
#include <string.h>
#include<stdlib.h>

struct value {       
    int number;   
};

#define ENTRIES 10  

// create some strings to put into the hash
char *haystack[] = { "thread", "spindle", "spool", "needle", "thimble", "" };

int main(int argc, char *argv[])
{
                                      
    ENTRY hashentry;
    ENTRY *result; 
    (void) hcreate(ENTRIES);  // create the hash
   int n  = 0;  // loop over the strings and stop at the empty string
  while(strcmp(haystack[n] ,"")){
        hashentry.key = haystack[n];    // assign the string name as key 
        hashentry.data = &n;            // assign the number as value
        (void) hsearch(hashentry, ENTER); // add it to the hash
    n++;
   }
   // Search for the desired key
        hashentry.key = "needle";
        result = hsearch(hashentry, FIND);
         (void)printf("found %s -> haystack element: %d\n",result->key, ((struct value *)result->data)->number);
    hdestroy();
    return 0;
}

