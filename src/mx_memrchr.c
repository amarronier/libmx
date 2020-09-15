#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = (const unsigned char *)s;

    while (n >= 1) {
        if (str[n - 1] == (unsigned char)c)
            return (void *)(str + n - 1);
        --n;
    }
    return NULL;
}
