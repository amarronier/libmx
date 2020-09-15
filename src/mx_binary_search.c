#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int l = -1;
    int r = size;
    *count = 0;

    while (l < r - 1) {
        int mid = l + (r - l) / 2;;

        ++*count;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        else if (mx_strcmp(arr[mid], s) < 0)
            l = mid;
        else
            r = mid;
    }
    *count = 0;
    return -1;
}
