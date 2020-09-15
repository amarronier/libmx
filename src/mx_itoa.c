#include "libmx.h"

static int number_length(int number) {
    int length = number < 0 ? 1 : 0;

    if (number == 0)
        length = 1;
    while (number) {
        number /= 10;
        ++length;
    }
    return length;
}

char *mx_itoa(int number) {
    int length = number_length(number);
    char *result = mx_strnew(length);
    unsigned int copy_number = number < 0 ? -number : number;

    if (NULL == result)
        return NULL;
    if (number < 0)
      result[0] = '-';
    while (copy_number) {
        result[length - 1] = copy_number % 10 + '0';
        copy_number /= 10;
        --length;
    }
    return result;
}
