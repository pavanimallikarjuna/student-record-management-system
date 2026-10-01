#include "student.h"

void modify_student(void)
{
    char choice;
    int roll;
    char name[50];
    float percentage;

    struct student *temp;

    if(head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\nEnter which record to search for modification\n\n");

    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    printf("\nEnter your choice : ");
    scanf(" %c", &choice);
    getchar();

    /* Search by roll number */

    if(choice == 'r' || choice == 'R')
    {
        printf("Enter roll number : ");
        roll = read_int();

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                printf("\nCurrent Name : %s\n", temp->name);
                printf("Current Percentage : %.2f\n",
                       temp->percentage);

                printf("\nEnter new name : ");
                read_string(temp->name);

                while(1)
                {
                    printf("Enter new percentage : ");
                    percentage = read_float();

                    if(percentage >= 0 &&
                       percentage <= 100)
                    {
                        temp->percentage = percentage;
                        break;
                    }

                    printf("Percentage must be between 0 and 100.\n");
                }

                printf("Record modified successfully.\n");
                return;
            }

            temp = temp->next;
        }

        printf("Record not found.\n");
    }

    /* Search by name */

    else if(choice == 'n' || choice == 'N')
    {
        printf("Enter name : ");
        read_string(name);

        temp = head;

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

        printf("\nEnter roll number of record to modify : ");
        roll = read_int();

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                printf("Enter new name : ");
                read_string(temp->name);

                while(1)
                {
                    printf("Enter new percentage : ");
                    percentage = read_float();

                    if(percentage >= 0 &&
                       percentage <= 100)
                    {
                        temp->percentage = percentage;
                        break;
                    }

                    printf("Percentage must be between 0 and 100.\n");
                }

                printf("Record modified successfully.\n");
                return;
            }

            temp = temp->next;
        }

        printf("Record not found.\n");
    }

    /* Search by percentage */

    else if(choice == 'p' || choice == 'P')
    {
        printf("Enter percentage : ");
        percentage = read_float();

        temp = head;

        while(temp != NULL)
        {
            if(temp->percentage == percentage)
            {
                printf("Roll No : %d | Name : %s | Percentage : %.2f\n",
                       temp->rollno,
                       temp->name,
                       temp->percentage);
            }

            temp = temp->next;
        }

        printf("\nEnter roll number of record to modify : ");
        roll = read_int();

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                printf("Enter new name : ");
                read_string(temp->name);

                while(1)
                {
                    printf("Enter new percentage : ");
                    percentage = read_float();

                    if(percentage >= 0 &&
                       percentage <= 100)
                    {
                        temp->percentage = percentage;
                        break;
                    }

                    printf("Percentage must be between 0 and 100.\n");
                }

                printf("Record modified successfully.\n");
                return;
            }

            temp = temp->next;
        }

        printf("Record not found.\n");
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
