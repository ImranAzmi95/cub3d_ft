#include "cub3d.h"

void init_data(t_data *data)
{
    data->cei[0] = -1;
    data->cei[1] = -1;
    data->cei[2] = -1;
    data->flo[0] = -1;
    data->flo[1] = -1;
    data->flo[2] = -1;
    data->ea_path[0] = '\0';
    data->we_path[0] = '\0';
    data->no_path[0] = '\0';
    data->so_path[0] = '\0';
    data->pos = 0;
    data->map = NULL;
}

int free_arr(char **arr)
{
    int i = 0;

    if (!arr)
        return (-1);
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    return (-1);
}

int main(int ac, char **av)
{
    t_data data;
    init_data(&data);
    if (ft_parse(ac, av, &data) == -1)
        return(free_arr(data.map));

    printf("f_red : %d\n", data.flo[0]);
    printf("f_gre : %d\n", data.flo[1]);
    printf("f_blue : %d\n", data.flo[2]);
    printf("c_red : %d\n", data.cei[0]);
    printf("c_gre : %d\n", data.cei[1]);
    printf("c_blue : %d\n", data.cei[2]);
    free_arr(data.map);
    return (0);
}