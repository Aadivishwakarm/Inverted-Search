#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "head.h"

int get_word_total_count(file_list *word_node)
{
    int total = 0;
    file_node *f = word_node->fhead;
    while (f)
    {
        total += f->count;
        f = f->fnext;
    }
    return total;
}

int update_database(file_list **hash)
{
    char filename[50];
    printf("Enter file name to update database: ");
    scanf("%49s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error: Cannot open file %s\n", filename);
        return FAILURE;
    }

    if (strcmp(filename, "database.txt") == 0)
    {
        char line[256];
        int index = -1;

        while (fgets(line, sizeof(line), fp))
        {
            line[strcspn(line, "\n")] = '\0';

            if (line[0] == '#')
            {
                index = atoi(line + 1);
                continue;
            }

            if (strlen(line) == 0)
                continue;

            char *token = strtok(line, ";");
            if (!token)
                continue;

            char word[50];
            strcpy(word, token);

            file_list *w = hash[index], *prev = NULL;
            while (w && strcmp(w->word, word) != 0)
            {
                prev = w;
                w = w->next;
            }

            if (!w)
            {
                w = malloc(sizeof(file_list));
                strcpy(w->word, word);
                w->fhead = NULL;
                w->next = NULL;

                if (!prev)
                    hash[index] = w;
                else
                    prev->next = w;
            }

            while (1)
            {
                char *fname = strtok(NULL, ";");
                if (!fname)
                    break;

                char *cnt = strtok(NULL, ";");
                if (!cnt)
                    break;

                int count = atoi(cnt);

                file_node *f = malloc(sizeof(file_node));
                strcpy(f->fname, fname);
                f->count = count;
                f->fnext = w->fhead;
                w->fhead = f;
            }
        }

        fclose(fp);
        printf("Database loaded successfully from backup file\n");
        return SUCCESS;
    }

    char word[50];

    while (fscanf(fp, "%49s", word) != EOF)
    {
        to_lowercase(word);

        int index = word[0] - 'a';
        if (index < 0 || index >= SIZE)
            continue;

        insert_at_last(&hash[index], word, filename);
    }

    fclose(fp);
    printf("Database updated using %s\n", filename);
    return SUCCESS;
}
