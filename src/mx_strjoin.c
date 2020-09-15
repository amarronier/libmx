#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    int n1 = s1 ? mx_strlen(s1) : 0;
    int n2 = s2 ? mx_strlen(s2) : 0;
    char *join;

    if (NULL == s1 && NULL == s2)
        return NULL;
    join = mx_strnew(n1 + n2);
    if (NULL == join)
        return NULL;

    if (s1)
        mx_strcpy(join, s1);
    if (s2)
        mx_strcat(join, s2);
    return join;
}
