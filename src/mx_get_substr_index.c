#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    char *result;

    if (NULL == str || NULL == sub)
        return -2;

    result = mx_strstr(str, sub);
    return result ? (result - str) : -1;
}
