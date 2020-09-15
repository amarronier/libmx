#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **arrp = arr ? *arr : NULL;

    for (int i = 0; arrp && arrp[i]; ++i) {
        mx_strdel(arrp + i);
    }
    if (arr && *arr) {
        free(*arr);
        *arr = NULL;
    }
}
