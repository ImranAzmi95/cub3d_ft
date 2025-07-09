#include "cub3d.h"

int main(int ac, char **av)
{
    t_map_data data;
    init_data(&data);
    if (ft_parse(ac, av, &data) == -1)
        return(free_arr(data.map));
    free_arr(data.map);
    return (0);
}