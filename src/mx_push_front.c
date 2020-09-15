#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);
    t_list *tmp = NULL;

    if (NULL == list || NULL == *list || NULL == front)
        return;

    tmp = *list;
    *list = front;
    front->next = tmp;
}
