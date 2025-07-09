#include "cub3d.h"

void init_map_data(t_map_data *data)
{
    data->ceiling_rgb[0] = -1;
    data->ceiling_rgb[1] = -1;
    data->ceiling_rgb[2] = -1;
    data->floor_rgb[0] = -1;
    data->floor_rgb[1] = -1;
    data->floor_rgb[2] = -1;
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
    return (0);
}
