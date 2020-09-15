#include "libmx.h"

static int count_occur(const char *str, const char *sub) {
    int sub_len = mx_strlen(sub);
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_strstr(&str[i], sub) == &str[i]) {
            count++;
            i += sub_len - 1;
        }
    }
    return count;
}

static char *replace_word(const char *str, const char *sub,
                          const char *replace) {
    int r_len = mx_strlen(replace);
    int sub_len = mx_strlen(sub);
    int res_len = mx_strlen(str) + count_occur(str, sub) * (r_len - sub_len);
    char *result = mx_strnew(res_len);
    int i = 0;

    while ((NULL != result) && *str) {
        if (sub_len == 0) {
            mx_strcpy(&result[i++], replace);
            result[i++] = *str++;
        } else if (mx_strstr(str, sub) == str) {
            mx_strcpy(&result[i], replace);
            i += r_len;
            str += sub_len;
        }
        else
            result[i++] = *str++;
    }
    return result;
}

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    if (NULL == str || NULL == sub || NULL == replace)
        return NULL;
    if (*sub == '\0') {
        int res_len = mx_strlen(str) * 2 + 1;
        char *result = mx_strnew(res_len);
        int i = 0;

        while (*str) {
            mx_strcpy(&result[i++], replace);
            result[i++] = *str++;
        }
        mx_strcpy(&result[i++], replace);
        return result;
    }
    return replace_word(str, sub, replace);
}
