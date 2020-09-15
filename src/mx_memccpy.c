#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    bool found = false;

    while (n > 0) {
        *d = *s;
        ++d;
        if (*s == (unsigned char)c) {
            found = true;
            break;
        }
        ++s;
        --n;
    }
    return found ? (void *)d : NULL;
}
