#include <ctype.h>
#include "head.h"

void to_lowercase(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}
