#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    while (n > 0) {
        *d = *s;
        ++d;
        ++s;
        --n;
    }
    return dst;
}
