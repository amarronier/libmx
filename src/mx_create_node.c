#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *temp = (t_list *)malloc(sizeof(t_list));

    if (NULL == temp)
        return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
