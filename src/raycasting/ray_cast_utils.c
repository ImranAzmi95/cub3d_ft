#include "cub3d.h"

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->step_y > 0)
			return (2);
		else
			return (3);
	}
}

double	get_wall_x(t_ray *ray, t_player *player)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	is_valid_map_pos(int x, int y, char **map)
{
	int	i;

	if (y < 0 || x < 0)
		return (0);
	i = 0;
	while (map[i])
		i++;
	if (y >= i)
		return (0);
	if (x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
	{
		dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}