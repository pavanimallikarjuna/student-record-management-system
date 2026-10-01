#include "student.h"

void delete_student(void)
{
    char choice;
    int roll;
    char name[50];

    struct student *temp;
    struct student *prev;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nR/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");

    printf("Enter your choice : ");
    scanf(" %c", &choice);
    getchar();

    /* Delete by roll number */

    if(choice == 'r' || choice == 'R')
    {
        printf("Enter roll number to delete : ");
        roll = read_int();

        temp = head;
        prev = NULL;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                if(prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                free(temp);

                printf("Record deleted successfully.\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("Record not found.\n");
    }

    /* Delete by name */

    else if(choice == 'n' || choice == 'N')
    {
        printf("Enter name to delete : ");
        read_string(name);

        temp = head;

        printf("\nMatching records:\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll No : %d | Name : %s | Percentage : %.2f\n",
                       temp->rollno,
                       temp->name,
                       temp->percentage);
            }

            temp = temp->next;
        }

        printf("\nEnter roll number of record to delete : ");
        roll = read_int();

        temp = head;
        prev = NULL;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                if(prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                free(temp);

                printf("Record deleted successfully.\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("Record not found.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
