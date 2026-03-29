#include <stdio.h>
#include <stdlib.h>
#include "head.h"

/* database state flags */
int db_created = 0;   
int db_loaded  = 0;   

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file1.txt file2.txt ...\n", argv[0]);
        return 0;
    }

    if (validation_file(argv) == FAILURE)
    {
        printf("File validation failed\n");
        return 0;
    }

    /* initialize hash table */
    file_list *hash[SIZE];
    create_hash(hash, SIZE);

    int choice;

    while (1)
    {
        printf("INVERTED SEARCH PROJECT (C)\n");
        printf("Author: Aditya Shirawal\n");
        printf("====================================\n");
        printf("        INVERTED SEARCH MENU\n");
        printf("====================================\n");
        printf("1. Create Database\n");
        printf("2. Search Database\n");
        printf("3. Display Database\n");
        printf("4. Update Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("====================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Invalid input\n");
            continue;
        }

        switch (choice)
        {
            /* CREATE DATABASE */
            case 1:
                if (db_created)
                {
                    printf("Database already created. Cannot create again.\n");
                }
                else if (db_loaded)
                {
                    /* allowed only for new files */
                    for (int i = 1; i < argc; i++)
                        create_database(hash, argv[i]);

                    db_created = 1;
                    printf("New files added to existing database.\n");
                }
                else
                {
                    for (int i = 1; i < argc; i++)
                        create_database(hash, argv[i]);

                    db_created = 1;
                    printf("Database created successfully.\n");
                }
                break;

            /* SEARCH */
            case 2:
                if (!db_created && !db_loaded)
                    printf("Database is empty. Create or update database first.\n");
                else
                    search_database(hash);
                break;

            /* DISPLAY */
            case 3:
                if (!db_created && !db_loaded)
                    printf("Database is empty. Create or update database first.\n");
                else
                    display_database(hash);
                break;

            /* UPDATE DATABASE (BACKUP ONLY) */
            case 4:
                update_database(hash);
                break;
            
            /* SAVE DATABASE */
            case 5:
                if (!db_created && !db_loaded)
                    printf("Database is empty. Nothing to save.\n");
                else
                    save_database(hash);
                break;

            case 6:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
