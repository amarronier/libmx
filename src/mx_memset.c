#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *dst = (unsigned char *)b;

    while (len > 0) {
        *dst = (unsigned char)c;
        ++dst;
        --len;
    }
    return b;
}
