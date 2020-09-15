#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (NULL == arr || NULL == delim)
        return;

    for (int i = 0; arr[i] != NULL; ++i) {
        mx_printstr(arr[i]);
        if (arr[i + 1] != NULL)
            mx_printchar(*delim);
    }
    mx_printchar('\n');
}
