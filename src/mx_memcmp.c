#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *first = (const unsigned char *)s1;
    const unsigned char *second = (const unsigned char *)s2;
    size_t i = 0;

    for (i = 0; i < n; ++i) {
        if (first[i] != second[i])
            break;
    }
    if (i == n)
        return 0;
    return (const unsigned char)first[i] - (const unsigned char)second[i];
}
