#include "student.h"


/* Sort records */
void sort_students(void)
{
    char choice;

    struct student *i;
    struct student *j;

    int temp_roll;
    char temp_name[50];
    float temp_percentage;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nN/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    printf("Enter your choice : ");
    scanf(" %c", &choice);
    getchar();

    if(choice == 'n' || choice == 'N')
    {
        /* Sort in alphabetical order */

        for(i = head; i != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(strcmp(i->name, j->name) > 0)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;
                }
            }
        }

        printf("List sorted by name.\n");
    }

    else if(choice == 'p' || choice == 'P')
    {
        /* Sort by percentage in descending order */

        for(i = head; i != NULL; i = i->next)
        {
            for(j = i->next; j != NULL; j = j->next)
            {
                if(i->percentage < j->percentage)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;
                }
            }
        }

        printf("List sorted by percentage.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}


/* Delete all records */
void delete_all(void)
{
    struct student *temp;

    while(head != NULL)
    {
        temp = head;

        head = head->next;

        free(temp);
    }

    head = NULL;

    printf("All records deleted from memory.\n");
}


/* Reverse the linked list */
void reverse_list(void)
{
    struct student *prev;
    struct student *current;
    struct student *next;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    prev = NULL;
    current = head;

    while(current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    head = prev;

    printf("List reversed successfully.\n");
}
