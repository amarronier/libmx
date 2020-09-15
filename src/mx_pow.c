#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    long double res = 1;
    long double ln = (long double)n;

    while (pow > 0) {
        if (pow % 2 == 1)
            res *= ln;
        pow /= 2;
        ln *= ln;
    }
    return (double)res;
}
