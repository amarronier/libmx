#include "libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    int n1 = mx_strlen(s1);
    int n2 = mx_strlen(s2);

    for (int i = 0; i <= n1 - n2; ++i)
        if (mx_strncmp(s1 + i, s2, n2) == 0)
            return (char *)(s1 + i);
    return NULL;
}
