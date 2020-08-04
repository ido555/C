#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char *name;
    int age;
    int height;
    int weight;
};
// kind of like a ctor
struct Person *Person_Create(char *name, int age ,int height , int weight){
    // malloc - On success, returns the pointer to the beginning of newly allocated memory
    // On failure, returns a null pointer (IMPORTANT remember to catch with assert).
    struct Person *person = malloc(sizeof(struct Person));
    // If expression evaluates to TRUE, assert() does nothing
    // If expression evaluates to FALSE, assert() displays an error message and aborts the program
    assert(person != NULL);
    // TODO fix current understanding of pointers if needed
    // my (ok-ish) explanation here
    // person->name is equivalent to (*person).name 
    // *person is pointing to 0xb73eb000 in memory  and *(person).name is 0xb73eb000+offset
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    
}
