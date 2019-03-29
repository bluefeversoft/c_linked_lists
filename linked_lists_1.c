#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
	struct sPerson *nextInLine;
};

struct sPerson *getNewPerson(const int age) 
{
    struct sPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
    printf("new person at %p\n", newPerson);
    return newPerson;
}

int main() 
{
	printf("\n\n** START **\n\n");

    struct sPerson *first = NULL;
    printf("first %p\n", first);

    first = getNewPerson(125);

    printf("age:%d address:%p nextInLine:%p\n", 
        first->age, 
        first, 
        first->nextInLine);

	return 0;
}


























