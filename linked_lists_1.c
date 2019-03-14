#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
	struct sPerson *nextInLine;
};

struct sPerson *getNewPerson(const int age) 
{
    struct sPerson *newPerson = NULL;
    newPerson = (struct sPerson*)malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
    printf("new person at %X\n", newPerson);
    return newPerson;
}

int main() 
{
	printf("\n\n** START **\n\n");

    struct sPerson *first = NULL;
    printf("first %X\n", first);

    first = getNewPerson(125);

    printf("age:%d address:%X nextInLine:%X ", first->age, 
        first, first->nextInLine);

	return 0;
}


























