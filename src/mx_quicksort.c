#include "libmx.h"

static int split_arr(char **arr, int *left, int *right, int middle) {
    int swap = 0;
    char *tmp;

    while(1) {
        while(*left < middle
              && mx_strlen(arr[++*left]) <= mx_strlen(arr[middle]));
        while(*right > middle
              && mx_strlen(arr[--*right]) >= mx_strlen(arr[middle]));
        if (*left >= *right)
            break;
        tmp = arr[*right];
        arr[*right] = arr[*left];
        arr[*left] = tmp;
        ++swap;
    }
    return swap;
}

int mx_quicksort(char **arr, int left, int right) {
    int swap = 0;
    int left_a = left - 1;
    int right_a = right + 1;
    int middle = left + (right - left) / 2;

    if (NULL == arr)
        return -1;
    if (left >= right)
        return 0;

    swap += split_arr(arr, &left_a, &right_a, middle);
    swap += mx_quicksort(arr, left, right_a);
    swap += mx_quicksort(arr, right_a + 1, right);
    return swap;
}
