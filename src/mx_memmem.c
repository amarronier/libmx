#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len) {
    const char *s1 = (const char *)big;
    const char *s2 = (const char *)little;

    if (little_len == 0 || big_len == 0)
        return NULL;
    if (big_len < little_len)
        return NULL;
    for (size_t i = 0; i <= big_len - little_len; ++i)
        if (mx_memcmp(s1 + i, s2, little_len) == 0)
            return (void *)(s1 + i);
    return NULL;
}
