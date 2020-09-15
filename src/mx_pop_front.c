#include "libmx.h"

void mx_pop_front(t_list **list) {
    t_list *p;

    if (NULL == list || NULL == *list)
        return;
    p = *list;
    if (NULL == p->next) {
        free(p);
        *list = NULL;
    }
    else {
        p = p->next;
        free(*list);
        *list = p;
    }
}
