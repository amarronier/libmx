#include "libmx.h"

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = str ? mx_strlen(str) : 0;
    char *new_str = NULL;
    int new_len = 0;

    end = end == 0 ? 0 : end - 1;

    if (str) {
        for (; mx_isspace(str[start]); ++start);
        for (; mx_isspace(str[end]) && end > start; --end);

        new_len = end > start ? end - start + 1 : 0;
        new_str = mx_strnew(new_len);
        if (NULL == new_str)
            return NULL;
        mx_strncpy(new_str, str + start, new_len);
    }
    return new_str;
}
