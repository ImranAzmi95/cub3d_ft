#include "cub3d.h"

void	cast_ray(t_game *game, int x)
{
	t_ray	ray;
	int		y;
	int		ceiling_color;
	int		floor_color;

	init_ray(&ray, &game->player, x, game->win_width);
	calculate_step_and_side_dist(&ray, &game->player);
	perform_dda(&ray, game->map_data.map);
	calculate_wall_distance(&ray, &game->player);
	calculate_wall_height(&ray, game->win_height);
	ceiling_color = (game->map_data.ceiling_rgb[0] << 16) | 
		(game->map_data.ceiling_rgb[1] << 8) | game->map_data.ceiling_rgb[2];
	floor_color = (game->map_data.floor_rgb[0] << 16) | 
		(game->map_data.floor_rgb[1] << 8) | game->map_data.floor_rgb[2];
	y = 0;
	while (y < ray.draw_start)
		put_pixel(game, x, y++, ceiling_color);
	while (y <= ray.draw_end)
		put_pixel(game, x, y++, 0x808080);
	while (y < game->win_height)
		put_pixel(game, x, y++, floor_color);
}

void	render_frame(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->win_width)
	{
		cast_ray(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
