#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr = NULL;
    size_t old_size = malloc_size(ptr);

    if (NULL == ptr && size > 0)
        return malloc(size);
    else if (NULL != ptr && size == 0) {
        free(ptr);
        return malloc(1);
    }
    else if (size > 0 && (new_ptr = malloc(size))) {
        mx_memmove(new_ptr, ptr, old_size);
        free(ptr);
    }
    return new_ptr;
}
