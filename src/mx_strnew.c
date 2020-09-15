#include "libmx.h"

char *mx_strnew(const int size) {
    char *str;

    if (size < 0)
        return NULL;

    str = (char *)malloc((size + 1) * sizeof(char));
    if (NULL == str)
        return NULL;

    for (int i = 0; i <= size; ++i)
        str[i] = '\0';
    return str;
}
