#include "libmx.h"

static bool skip_n_bytes(int fd, t_save_data *data) {
    int x = 0;
    int n = data->last_delim + 1;
    char *tmp;

    if (n > 0) {
        tmp = mx_strnew(n - 1);
        if (NULL == tmp)
            return false;
        x = read(fd, tmp, n);
        mx_strdel(&tmp);
    }
    return x >= 0;
}

static t_save_data *check_create(t_list **saves, int fd, int buf_size) {
    t_save_data *data = (t_save_data *)malloc(sizeof(t_save_data));

    if (NULL == data)
        return NULL;
    data->fd = fd;
    data->last_delim = -1;
    data->buf_size = buf_size;
    data->buf = mx_strnew(buf_size);
    if (NULL == data->buf) {
        free(data);
        return NULL;
    }
    mx_push_back(saves, data);
    return data;
}

static t_save_data *find_update(t_list **saves, int fd, int buf_size) {
    t_list *p;
    t_save_data *data = NULL;

    for (p = *saves; p != NULL; p = p->next) {
        data = (t_save_data *)(p->data);
        if (data && data->fd == fd) {
            if (!skip_n_bytes(fd, data))
                return NULL;
            data->buf_size = buf_size;
            mx_strdel(&(data->buf));
            data->buf = mx_strnew(buf_size);
            if (NULL == data->buf)
                return NULL;
            break;
        }
    }
    if (NULL == p)
        data = check_create(saves, fd, buf_size);
    return data;
}

static bool read_next_line(t_save_data *data, char **lineptr,
                           char delim, int bytes_read, int *len) {
    char delim_str[2] = {delim, '\0'};
    char *delim_pos = mx_strstr(data->buf, delim_str);
    int delim_index;
    char *buf_cut;

    if (bytes_read <= 0) {
        *len = -1;
        return true;
    }
    delim_index = delim_pos ? delim_pos - data->buf : bytes_read;
    *len += delim_index;
    buf_cut = mx_strndup(data->buf, delim_index);
    *lineptr = mx_strjoin(*lineptr, buf_cut);
    mx_strdel(&buf_cut);
    if (delim_pos)
        data->last_delim += *len + 1;
    return (NULL != delim_pos);
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static t_list *saves = NULL;
    t_save_data *data;
    int len = 0;

    if (buf_size == 0 || fd < 0 || NULL == lineptr)
        return -2;
    data = find_update(&saves, fd, buf_size);
    if (NULL == data)
        return -2;
    while(len >= 0) {
        int bytes_read = read(fd, data->buf, data->buf_size);

        if (bytes_read <= 0) {
            len = -1;
            break;
        }
        if (read_next_line(data, lineptr, delim, bytes_read, &len))
            break;
    }
    return len;
}
