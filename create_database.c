#include "head.h"
#include <ctype.h>

int create_database(file_list **hash, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        return FAILURE;
    }
    char word[50];

    while (fscanf(fp, "%49s", word) != EOF)
    {
        to_lowercase(word);

        int index = word[0] - 'a';
        if (index < 0 || index >= SIZE)
        {
            continue;
        }
        insert_at_last(&hash[index], word, filename);
    }


    fclose(fp);
    return SUCCESS;
}
