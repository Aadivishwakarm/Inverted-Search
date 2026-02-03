#include "head.h"

int insert_at_last(file_list **head, char *word, char *filename)
{
    file_list *temp = *head;

    /* search word */
    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
            break;
        temp = temp->next;
    }

    /* create new word node if not found */
    if (temp == NULL)
    {
        file_list *new_word = malloc(sizeof(file_list));
        strcpy(new_word->word, word);
        new_word->fhead = NULL;
        new_word->next = *head;
        *head = new_word;
        temp = new_word;
    }

    /* handle file list */
    file_node *f = temp->fhead;
    while (f)
    {
        if (strcmp(f->fname, filename) == 0)
        {
            f->count++;
            return SUCCESS;
        }
        f = f->fnext;
    }

    /* add new file node */
    file_node *new_file = malloc(sizeof(file_node));
    strcpy(new_file->fname, filename);
    new_file->count = 1;
    new_file->fnext = temp->fhead;
    temp->fhead = new_file;

    return SUCCESS;
}
