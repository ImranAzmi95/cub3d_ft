#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map_data data;
	init_data(&data);
	if (ft_parse(argc, argc, &data) == -1)
		return (free_arr(data.map));
	free_arr(data.map);
	return (0);
}