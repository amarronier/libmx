#include "libmx.h"

int mx_list_size(t_list *list) {
    int k = 1;
    t_list *p = list;

    if (NULL == list)
        return 0;
    while (NULL != p->next) {
        ++k;
        p = p->next;
    }
    return k;
}
