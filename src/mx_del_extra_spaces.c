#include "libmx.h"

static char *remove_whitespaces(const char *str, int *n) {
    int i = 0;
    int j = 0;
    char *result = mx_strnew(*n);

    while (NULL != result && i < *n) {
        while (i < *n && mx_isspace(str[i]))
            ++i;
        while (i < *n && !mx_isspace(str[i])) {
            result[j] = str[i];
            ++i;
            ++j;
        }
        if (i < *n) {
            result[j] = ' ';
            ++j;
        }
    }
    *n = j;
    return result;
}

char *mx_del_extra_spaces(const char *str) {
    char *result = mx_strtrim(str);
    char *tmp;
    int n;

    if (NULL == result)
        return NULL;
    n = mx_strlen(result);
    tmp = remove_whitespaces(result, &n);

    mx_strdel(&result);
    result = mx_strnew(n);
    if (NULL == result)
        return NULL;
    result = mx_strncpy(result, tmp, n);
    mx_strdel(&tmp);

    return result;
}
