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
struct Person *Person_Create(char *name, int age, int height, int weight){
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
    // so the offset for height for example would be - sizeof(name)+sizeof(age) - (for example: 3 bytes for 3 chars + 4 bytes for int)
    // so 0xb73eb000+7 = height
    // 0xb73eb000+12 = weight

    // use strdup to copy name into the newly allocated Person memory block
    // instead of name = *name - which (could) point outside the memory block?
    // compiler may add padding
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    person->weight = weight;
}

void Person_destroy(struct Person *person){
    assert(person != NULL);

    // delete assigned name memory block (memory address = *name) 
    free(person->name);
    // same with person
    free(person);
}

void Person_print(struct Person *who){
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_Create("Joe NormanAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 32, 64, 140);
    struct Person *frank = Person_Create("Frank Blank", 20, 72, 180);

    // print them out and where they begin in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);
    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

     printf("\n");
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);


    // cleanup garbage (windows will do this automatically but this is good convention)
    Person_destroy(joe);
    Person_destroy(frank);
    return 0;
}