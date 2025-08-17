#include "cub3d.h"

int handle_key(int keycode, void *param)
{
    if (keycode == KEY_ESC)
    {
        t_map *data = (t_map *)param;
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

int load_map(t_map *data)
{
    int size;
    int i;
    int j;

    i = 0;
    size = TEXTURE_SIZE;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
    data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wood1.xpm", &size, &size);
    data->eagle = mlx_xpm_file_to_image(data->mlx, "textures/eagle_wood.xpm", &size, &size);
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 64 ,i * 64);
            if (ft_strchr("NSWE",data->map[i][j]))
                mlx_put_image_to_window(data->mlx, data->win, data->eagle, j * 64 ,i * 64);
            j++;
        }
        i++;
    }
    mlx_key_hook(data->win, handle_key, data);
	mlx_loop(data->mlx);
	return (0);
}

int main(int ac, char **av)
{
    t_map data;
    init_map_data(&data);
    if (ft_parse(ac, av, &data) == -1)
        return(free_arr(data.map));
    if (load_map(&data) == -1)
        return(free_arr(data.map));
    free_arr(data.map);
    return (0);
}