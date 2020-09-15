#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *tmp;

    if (NULL == list)
        return;
    tmp = mx_create_node(data);
    if (NULL == tmp)
        return;
    if (NULL == *list)
        *list = tmp;
    else {
        t_list *p = *list;

        while (NULL != p->next)
            p = p->next;
        p->next = tmp;
    }
}
