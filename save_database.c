#include <stdio.h>
#include "head.h"

int save_database(file_list **hash)
{
    FILE *fp = fopen("database.txt", "w");
    if (fp == NULL)
    {
        printf("Error: Unable to create database file\n");
        return FAILURE;
    }

    for (int i = 0; i < SIZE; i++)
    {
        file_list *w = hash[i];
        if (w)
        {
            fprintf(fp, "#%d\n", i);

            while (w)
            {
                fprintf(fp, "%s;", w->word);

                file_node *f = w->fhead;
                while (f)
                {
                    fprintf(fp, "%s;%d; ", f->fname, f->count);
                    f = f->fnext;
                }

                fprintf(fp, "\n");
                w = w->next;
            }
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    printf("Database saved successfully to database.txt\n");
    return SUCCESS;
}
