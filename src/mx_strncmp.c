#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;

    if (n == 0)
        return 0;
    while (i < n - 1 && s1[i] && s1[i] == s2[i])
        i++;
    return (const unsigned char)s1[i] - (const unsigned char)s2[i];
}
