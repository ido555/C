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
    struct Person *person = malloc(sizeof(struct Person)); // assign memory block the size of name+age+height+weight
    // If TRUE, assert() does nothing
    // If FALSE, assert() displays an error message and aborts the program

    // malloc can return NULL when system memory / virtual memory are full (more of a problem with embedded systems)
    assert(person != NULL);
    // TODO fix current understanding of pointers if needed
    // person->name is equivalent to (*person).name 
    // *person is pointing to 0xb73eb000(example address) in memory  and *(person).name is 0xb73eb000+offset

    // each "cell" in memory is 1 byte
    // and the offset for height for example would be - sizeof(name)+sizeof(age) - (for example: 3 bytes for 3 chars + 4 bytes for int)
    // so 0xb73eb000+7 = height
    // 0xb73eb000+12 = weight
    
    // use strdup to copy name into the newly allocated Person memory block
    // instead of name = *name - which will point outside the memory block?
    person->name = strdup(*name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    
}
