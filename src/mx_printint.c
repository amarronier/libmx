#include "libmx.h"

static void print_num(int *n, int *p, int *k, int sig) {
    while (*k) {
        int x = *n / *p;

        mx_printchar(sig * x + '0');
        *n -= x * (*p);
        *p /= 10;
        --*k;
    }
}

void mx_printint(int n) {
    int sig = 1;
    int m = n;
    int p = 1;
    int k = 0;

    if (n < 0) {
        mx_printchar('-');
        sig = -1;
    } else if (n == 0) {
        mx_printchar('0');
        return;
    }

    while (m) {
        k++;
        m /= 10;
    }
    for (int i = 0; i < k - 1; ++i)
        p *= 10;
    print_num(&n, &p, &k, sig);
}
