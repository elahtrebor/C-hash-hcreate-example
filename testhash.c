#include <stdio.h>
#include <search.h>
#include <string.h>
#include<stdlib.h>

struct info {       
    int number;   
};

#define ENTRIES 1000   

char *haystack[] = { "thread", "spindle", "spool", "needle", "thimble", "" };

int main(int argc, char *argv[])
{
                                      
    ENTRY item;
    ENTRY *result; 
    (void) hcreate(ENTRIES);
   int n  = 0;
  while(strcmp(haystack[n] ,"")){
        item.key = haystack[n];
        item.data = &n;
        (void) hsearch(item, ENTER);
    n++;
   }
   // Search for the desired key
        item.key = "needle";
        result = hsearch(item, FIND);
         (void)printf("found %s -> haystack element: %d\n",result->key, ((struct info *)result->data)->number);
    hdestroy();
    return 0;
}

