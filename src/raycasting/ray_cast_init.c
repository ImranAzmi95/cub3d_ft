#include "cub3d.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	set_player_position(t_player *player, int i, int j, char direction)
{
	player->pos_x = j + 0.5;
	player->pos_y = i + 0.5;
	set_player_direction(player, direction);
}

void	init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player_char(map[i][j]))
			{
				set_player_position(player, i, j, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_ray(t_ray *ray, t_player *player, int x, int screen_width)
{
	ray->camera_x = 2 * x / (double)screen_width - 1;
	ray->ray_dir_x = player->dir_x + (player->plane_x * player->fov_scale) * ray->camera_x;
	ray->ray_dir_y = player->dir_y + (player->plane_y * player->fov_scale) * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	ray->side = 0;
}

void	init_game(t_game *game, t_map *map_data)
{
	game->mlx = mlx_init();
	game->win_width = 800;
	game->win_height = 600;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "cub3d");
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, 
		&game->line_length, &game->endian);
	game->map_data = *map_data;
	init_player(&game->player, map_data->map);
	if (load_all_textures(game) == -1)
	{
		ft_err_msg("Error loading textures");
		exit(1);
	}
}