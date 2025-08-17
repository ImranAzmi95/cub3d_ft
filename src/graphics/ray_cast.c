#include "cub3d.h"

int	calculate_tex_x(t_game *game, t_ray *ray, int tex_num, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)game->textures[tex_num].width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || 
		(ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->textures[tex_num].width - tex_x - 1;
	return (tex_x);
}

void	draw_wall_column(t_game *game, t_ray *ray, int x, int tex_num)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	tex_x = calculate_tex_x(game, ray, tex_num, 
		get_wall_x(ray, &game->player));
	step = 1.0 * game->textures[tex_num].height / ray->line_height;
	tex_pos = (ray->draw_start - game->win_height / 2 + 
		ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (game->textures[tex_num].height - 1);
		tex_pos += step;
		color = get_texture_pixel(&game->textures[tex_num], tex_x, tex_y);
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	int	tex_num;

	tex_num = get_texture_index(ray);
	draw_wall_column(game, ray, x, tex_num);
}

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
	draw_textured_wall(game, &ray, x);
	y = ray.draw_end + 1;
	while (y < game->win_height)
		put_pixel(game, x, y++, floor_color);
}

void	render_frame(t_game *game)
{
	int	x;
	static int frame_count = 0;

	if (frame_count == 0)
		printf("Starting first frame render...\n");
	x = 0;
	while (x < game->win_width)
	{
		cast_ray(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (frame_count == 0)
		printf("First frame rendered.\n");
	frame_count++;
}