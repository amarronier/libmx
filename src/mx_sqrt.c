#include "libmx.h"

int mx_sqrt(int x) {
    long long int i = 1;

    while (i * i <= x) {
        if (i * i == x)
            return i;
        i++;
    }
    return 0;
}
