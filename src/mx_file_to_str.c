#include "libmx.h"

char *mx_file_to_str(const char *filename) {
    char *str = NULL;
    int length = mx_file_length(filename);
    int fd = open(filename, O_RDONLY);

    if (fd == -1 || length <= 0)
        return NULL;
    str = mx_strnew(length);
    if (str == NULL)
        return NULL;
    if (read(fd, str, length) != length)
        return NULL;
    return str;
}
