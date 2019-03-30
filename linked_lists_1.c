#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
};

struct sPerson *getNewPerson(const int age) 
{
    struct sPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
	newPerson->age = age;
    printf("created new person at %p\n", newPerson);
    return newPerson;
}

void printPerson(const struct sPerson *person)
{
    if (person == NULL)
    {
        printf("Printing NULL sPerson\n");
    }
    else
    {
        printf("age:%d address:%p\n", 
            person->age, 
            person);
    }
}

int main() 
{
	printf("\n\n** START **\n\n");

    struct sPerson *first = NULL;
    struct sPerson *second = NULL;

    printPerson(first);
    printPerson(second);

    first = getNewPerson(125);
    second = getNewPerson(100);

    printPerson(first);
    printPerson(second);

	return 0;
}


























