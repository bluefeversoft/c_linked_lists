#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
	struct sPerson *nextInLine;
};

void printPerson(struct sPerson *person, const char *comment)
{
    printf("%s age:%d address:%X nextInLine:%X\n", comment,
    person->age, person, person->nextInLine);
}

struct sPerson *getNewPerson(const int age) 
{
    struct sPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
    printf("new person at %X\n", newPerson);
    return newPerson;
}

int main() 
{
	printf("** START **\n");

    struct sPerson *first = NULL;
    struct sPerson *second = NULL;

    printf("first %X\n", first);
    printf("second %X\n", first);

    first = getNewPerson(125);
    second = getNewPerson(50);

    printPerson(first, "First");
    printPerson(second, "Second");

    first->nextInLine = second;
    printPerson(first, "First After Assign");
    printPerson(first->nextInLine, "first->nextInLine");
    printPerson(second, "Second");

    free(second);
    second = NULL;
    free(first);
    first = NULL;

	return 0;
}


























