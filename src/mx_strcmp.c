#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int i = 0;

    while (s1[i] && s1[i] == s2[i])
        i++;
    return (const unsigned char)s1[i] - (const unsigned char)s2[i];
}
