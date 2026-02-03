#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "head.h"

void search_database(file_list **hash)
{
    char word[50];
    printf("Enter word to search: ");
    scanf("%49s", word);
    to_lowercase(word);

    int index = tolower(word[0]) - 'a';

    if (index < 0 || index >= SIZE)
    {
        printf("Invalid word\n");
        return;
    }

    file_list *temp = hash[index];

    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
        {
            printf("Word FOUND: %s\n", word);
            printf("Present in files:\n");

            file_node *f = temp->fhead;
            while (f)
            {
                printf("  %s -> %d\n", f->fname, f->count);
                f = f->fnext;
            }
            return;
        }
        temp = temp->next;
    }

    printf("Word NOT found in database\n");
}
