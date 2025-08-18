/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:36:16 by lechan            #+#    #+#             */
/*   Updated: 2025/08/18 23:36:17 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_ceiling_color(t_game *game)
{
	return ((game->map_data.ceiling_rgb[0] << 16)
		| (game->map_data.ceiling_rgb[1] << 8) | game->map_data.ceiling_rgb[2]);
}

int	calculate_floor_color(t_game *game)
{
	return ((game->map_data.floor_rgb[0] << 16)
		| (game->map_data.floor_rgb[1] << 8) | game->map_data.floor_rgb[2]);
}

void	draw_ceiling_floor(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = calculate_ceiling_color(game);
	floor_color = calculate_floor_color(game);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(game, x, y++, ceiling_color);
	y = ray->draw_end + 1;
	while (y < game->win_height)
		put_pixel(game, x, y++, floor_color);
}

void	cast_ray(t_game *game, int x)
{
	t_ray	ray;

	init_ray(&ray, &game->player, x, game->win_width);
	calculate_step_and_side_dist(&ray, &game->player);
	perform_dda(&ray, game->map_data.map);
	calculate_wall_distance(&ray, &game->player);
	calculate_wall_height(&ray, game->win_height);
	draw_ceiling_floor(game, &ray, x);
	draw_textured_wall(game, &ray, x);
}

void	render_frame(t_game *game)
{
	int			x;
	static int	frame_count = 0;

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
