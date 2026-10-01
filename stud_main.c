#include "student.h"

struct student *head = NULL;

void read_string(char *str)
{
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int read_int(void)
{
    int n;

    scanf("%d", &n);
    getchar();

    return n;
}

float read_float(void)
{
    float n;

    scanf("%f", &n);
    getchar();

    return n;
}

int main()
{
    char choice;
    char ch;

    load_students();

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n\n");

        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        getchar();

        switch(choice)
        {
            case 'a':
            case 'A':
                add_student();
                break;

            case 'd':
            case 'D':
                delete_student();
                break;

            case 's':
            case 'S':
                show_students();
                break;

            case 'm':
            case 'M':
                modify_student();
                break;

            case 'v':
            case 'V':
                save_students();
                break;

            case 't':
            case 'T':
                sort_students();
                break;

            case 'l':
            case 'L':
                delete_all();
                break;

            case 'r':
            case 'R':
                reverse_list();
                break;

            case 'e':
            case 'E':

                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");

                printf("Enter your choice: ");
                scanf(" %c", &ch);
                getchar();

                if(ch == 's' || ch == 'S')
                {
                    save_students();
                    delete_all();

                    printf("Saved and exited successfully.\n");
                    return 0;
                }

                else if(ch == 'e' || ch == 'E')
                {
                    delete_all();

                    printf("Exited without saving.\n");
                    return 0;
                }

                else
                {
                    printf("Invalid choice.\n");
                }

                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}
