#include "libmx.h"

static char *split_step(char const *s, char c, int *L) {
    int R;
    char *result;

    while (s[*L] && s[*L] == c)
        ++*L;
    if (!s[*L]) {
        *L = -1;
        return NULL;
    }

    R = *L;
    while (s[R] && s[R] != c)
        ++R;

    result = mx_strnew(R - *L + 1);
    if (NULL == result)
        return NULL;
    result = mx_strncpy(result, s + *L, R - *L);
    *L = R;
    return result;
}

char **mx_strsplit(char const *s, char c) {
    int n;
    char **arr;
    int L = 0;
    int i = 0;

    if (NULL == s)
        return NULL;
    n = mx_count_words(s, c);
    arr = (char **)malloc((n + 1) * sizeof(char *));

    while (s && s[L]) {
        arr[i] = split_step(s, c, &L);
        if (NULL == arr[i] && L != -1)
            return NULL;
        ++i;
    }
    arr[n] = NULL;
    return arr;
}
