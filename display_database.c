#include "head.h"

void display_database(file_list **hash)
{
    printf("\n--------------------------------------------------\n");
    printf("| INDEX | WORD       | FILES                     |\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < SIZE; i++)
    {
        file_list *w = hash[i];

        if (w == NULL)
            continue;

        while (w)
        {
            printf("  %-4d    %-10s  ", i, w->word);

            file_node *f = w->fhead;
            while (f)
            {
                printf("%s(%d) ", f->fname, f->count/2);
                f = f->fnext;
            }

            printf("\n");
            w = w->next;
        }

        // printf("--------------------------------------------------\n");
    }
    // printf("\n");
    printf("---------------------------------------------------\n");
}
