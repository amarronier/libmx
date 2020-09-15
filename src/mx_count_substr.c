#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int res = 0;

    if (NULL == str || NULL == sub)
        return -1;

    if (!sub[0])
        return 0;
        
    while (str && str[0]) {
        str = mx_strstr(str, sub);
        if (str && str[0]) {
            res++;
            str++;
        }
    }
    return res;
}
