#include "libmx.h"

static int len_of_hex(unsigned long number) {
    int len_hex = 0;

    while (number) {
        len_hex++;
        number /= 16;
    }
    return len_hex;
}

static char num_to_char(int d) {
    char c = '0';

    if (d >= 0 && d <= 9)
        c = '0' + d;
    else if (d == 10)
        c = 'a';
    else if (d == 11)
        c = 'b';
    else if (d == 12)
        c = 'c';
    else if (d == 13)
        c = 'd';
    else if (d == 14)
        c = 'e';
    else if (d == 15)
        c = 'f';
    return c;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int length = len_of_hex(nbr);
    char *str_hex = mx_strnew(length);

    if (NULL == str_hex)
        return 0;

    for (int i = length - 1; i >= 0; i--) {
        int rem = nbr % 16;

        str_hex[i] = num_to_char(rem);
        nbr /= 16;
    }
    return str_hex;
}
