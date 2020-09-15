#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *temp;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (mx_strcmp(arr[j], arr[i]) < 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }
    return count;
}
