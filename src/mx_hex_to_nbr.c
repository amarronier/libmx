#include "libmx.h"

static bool is_hex_str(const char *s) {
    int i = 0;

    while (s[i]) {
        if (!mx_isdigit(s[i]) && !mx_isalpha(s[i]))
            return false;
        if (mx_isalpha(s[i]) && !((s[i] >= 'A' && s[i] <= 'F')
            || (s[i] >= 'a' && s[i] <= 'f')))
            return false;
        ++i;
    }
    return true;
}

static int len_of_hex_str(const char *s) {
    int len_hex = 0;

    while (s[len_hex]) {
        ++len_hex;
    }
    return len_hex;
}

static int char_to_num(char c) {
    int num = 0;

    if (c >= '0' && c <= '9')
        num = c - '0';

    if (c == 'A' || c == 'a')
        num = 10;
    if (c == 'B' || c == 'b')
        num = 11;
    if (c == 'C' || c == 'c')
        num = 12;
    if (c == 'D' || c == 'd')
        num = 13;
    if (c == 'E' || c == 'e')
        num = 14;
    if (c == 'F' || c == 'f')
        num = 15;
    return num;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long num = 0;
    unsigned long base = 1;

    if (NULL == hex || !is_hex_str(hex))
        return 0;

    for (int i = len_of_hex_str(hex) - 1; i >= 0; --i) {
        num += char_to_num(hex[i]) * base;
        base *= 16;
    }
    return num;
}
