#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void PrintList(const struct sPerson *list)
{
	printf("Printing List:\n");
	const struct sPerson *t;
	t = list;
    if(t == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(t)
        {
            printPerson(t, "t");
            t = t->nextInLine;
        }
    }
}
struct sPerson *getNewPerson(const int age) 
{
    struct sPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
	if(newPerson != NULL)
	{
		newPerson->nextInLine = NULL;
		newPerson->age = age;
		printf("new person at %p\n", newPerson);
	}
	else
	{
		printf("Allocation Failure!! \n");
	}
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
        printf("Cleaning %d\n", list->age);
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
	int place;
	int age;
	
	first = getNewPerson(21);
	pTemp1 = first;
	pTemp1->nextInLine = getNewPerson(22);
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(23);
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(12);
	pTemp1 = pTemp1->nextInLine;	
	pTemp1->nextInLine = getNewPerson(65);
	pTemp1 = pTemp1->nextInLine;	
	

    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 64, stdin);
		if (strcmp("q\n", command) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		else if (strcmp("print\n", command) == 0) 
		{
			printf("Printing..\n");
			PrintList(first);
		}
        else
        {
            if (sscanf(command, "%d %d",  &place, &age) != 0)
			{
				printf("Adding %d at place %d\n", age, place);
				if(first == NULL)
				{
					first = getNewPerson(age);
				}
				else if(place == 1)
				{
					pTemp1 = getNewPerson(age);
					if(pTemp1 != NULL)
					{
						pTemp1->nextInLine = first;
						first = pTemp1;
						pTemp1 = NULL;
					}
				}
				else
				{
					pTemp1 = getPlacePointer(first,place);
					pTemp2 = getNewPerson(age);
					if(pTemp2 != NULL)
					{	
                    	pTemp2->nextInLine = pTemp1->nextInLine;
						pTemp1->nextInLine = pTemp2;
						pTemp2 = NULL;
					}
					pTemp1 = NULL;
				}
			}
        }
        
    }

    CleanUp(first);
    first = NULL;
    pTemp1 = NULL;
    pTemp2 = NULL;

	return 0;
}


























