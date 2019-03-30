#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
	struct sPerson *nextInLine;
};

void printPerson(const struct sPerson *person, const char *comment)
{
    if (person == NULL)
    {
        printf("%s is NULL\n", comment);
    }
    else
    {
        printf("%s: age:%d address:%p nextInLine:%p\n", 
            comment,
            person->age, 
            person,
            person->nextInLine);
    }
}

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
	printf("** START **\n");

    struct sPerson *first = NULL;
    struct sPerson *second = NULL;

    printf("first %p\n", first);
    printf("second %p\n", first);

    first = getNewPerson(125);
    second = getNewPerson(50);

    printPerson(first, "First");
    printPerson(second, "Second");

    first->nextInLine = second;
    printPerson(first, "First");
    printPerson(first->nextInLine, "first->nextInLine");
    printPerson(second, "Second");

    free(second);
    free(first);
    second = NULL;
    first = NULL;

	return 0;
}


























