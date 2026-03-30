#include "head.h"

void display_database(file_list **hash)
{
    printf("\n--------------------------------------------------\n");
    printf("| %-5s | %-12s | %-22s |\n", "INDEX", "WORD", "FILES");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < SIZE; i++)
    {
        file_list *w = hash[i];

        while (w)
        {
            file_node *f = w->fhead;
            int first = 1;

            while (f)
            {
                if (first)
                {
                    printf("| %-5d | %-12s | ", i, w->word);
                    first = 0;
                }
                else
                {
                    printf("| %-5s | %-12s | ", "", "");
                }

                if (f->fnext == NULL)
                    printf("└── %-10s : %-3d   |\n", f->fname, f->count);
                else
                    printf("├── %-10s : %-3d   |\n", f->fname, f->count);

                f = f->fnext;
            }

            printf("--------------------------------------------------\n");

            w = w->next;
        }
    }
}
