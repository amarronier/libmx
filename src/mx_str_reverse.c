#include "libmx.h"

void mx_str_reverse(char *s) {
    int n = mx_strlen(s);

    for (int i = 0; i < n / 2; i++) {
        mx_swap_char(&s[i], &s[n - 1 - i]);
    }
}
