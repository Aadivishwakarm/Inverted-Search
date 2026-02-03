#include <stdio.h>
#include <string.h>
#include "head.h"

int validation_file(char *argv[])
{
    FILE *fp;
    char *ext;

    for (int i = 1; argv[i] != NULL; i++)
    {
        /* check .txt extension */
        ext = strrchr(argv[i], '.');
        if (ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("Error: %s is not a .txt file\n", argv[i]);
            return FAILURE;
        }

        /* check file open */
        fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("Error: Cannot open file %s\n", argv[i]);
            return FAILURE;
        }

        /* check empty file */
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            printf("Error: %s is empty\n", argv[i]);
            fclose(fp);
            return FAILURE;
        }

        fclose(fp);
    }

    return SUCCESS;
}
