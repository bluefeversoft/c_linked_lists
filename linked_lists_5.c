#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPerson {
	int age;
	char name[16];
	struct sPerson *nextInLine;
};

void printPerson(struct sPerson *person)
{
    printf("name:%s age:%d address:%X nextInLine:%X\n", person->name,
    person->age, person, person->nextInLine);
}

void PrintList(struct sPerson *list)
{
	printf("Printing List:\n");
	struct sPerson *t;
	t = list;
    if(t == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(t)
        {
            printPerson(t);
            t = t->nextInLine;
        }
    }
}

struct sPerson *getNewPerson(const int age, const char *name) 
{
    struct sPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
    sprintf(newPerson->name, "%s", name);
    printf("new person at %X\n", newPerson);
    return newPerson;
}

struct sPerson *getPlacePointer(struct sPerson *list, const int place)
{
	struct sPerson *t;
	t = list;
	int count = 1;
	do
	{
		count++;
		if (count == place)
		{
			break;
		}
		t = t->nextInLine;
	}
	while (t->nextInLine != NULL);
	
	return t;
}

void CleanUp(struct sPerson *list)
{
	struct sPerson *next;
	while(list)
	{
		next = list->nextInLine;
		printf("Cleaning %s\n", list->name);
		free(list);
		list = next;
	}
}

int main() 
{
	printf("** START **\n");

    struct sPerson *first = NULL;
    struct sPerson *pTemp1 = NULL;
	struct sPerson *pTemp2 = NULL; 
	
	char command[64];
	char name[16];
	
	int place;
	int age;
	
	first = getNewPerson(21, "John");
	pTemp1 = first;
	pTemp1->nextInLine = getNewPerson(22, "Roger");
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(23, "Jane");
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(12, "Tom");
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(65, "Susan");
	pTemp1 = pTemp1->nextInLine;	
	

    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 64, stdin);
		if (strncmp("q", command, 1) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		else if (strncmp("print", command, 5) == 0) 
		{
			printf("Printing..\n");
			PrintList(first);
		}
        else
        {
            if (sscanf(command, "%d %s %d",  &place, name, &age) != 0)
			{
				printf("Adding %s %d at place %d\n", name, age, place);
				if(first == NULL)
				{
					first = getNewPerson(age, name);
				}
				else if(place == 1)
				{
					pTemp1 = getNewPerson(age, name);
					pTemp1->nextInLine = first;
					first = pTemp1;
					pTemp1 = NULL;
				}
				else
				{
					pTemp1 = getPlacePointer(first,place);
					pTemp2 = getNewPerson(age, name);
                    pTemp2->nextInLine = pTemp1->nextInLine;
					pTemp1->nextInLine = pTemp2;
					pTemp1 = NULL;
					pTemp2 = NULL;
				}
			}
        }
        
    }

    CleanUp(first);
    pTemp1 = NULL;
    pTemp2 = NULL;

	return 0;
}


























