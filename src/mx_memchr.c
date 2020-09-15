#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = (const unsigned char *)s;
    int i = 0;

    while (n > 0) {
        if (str[i] == (unsigned char)c)
            return (void *)(str + i);
        else
            ++i;
        --n;
    }
    return NULL;
}
