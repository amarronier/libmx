#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int res = 0;

    if (NULL == str)
        return -1;

    if (str[0] && str[0] != delimiter)
        res++;

    for (int i = 0; str[i + 1]; ++i)
        if (str[i] == delimiter && str[i + 1] != delimiter)
            ++res;
    return res;
}
