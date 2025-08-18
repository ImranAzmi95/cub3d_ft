/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:35:53 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:58:52 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_tex_x(t_game *game, t_ray *ray, int tex_num, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)game->textures[tex_num].width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->textures[tex_num].width - tex_x - 1;
	return (tex_x);
}

void	draw_wall_column(t_game *game, t_ray *ray, int x, int tex_num)
{
	int			y;
	t_text_cord	tex_cord;
	double		step;
	double		tex_pos;
	int			color;

	tex_cord.tex_x = calculate_tex_x(game, ray, tex_num,
			get_wall_x(ray, &game->player));
	step = 1.0 * game->textures[tex_num].height / ray->line_height;
	tex_pos = (ray->draw_start - game->win_height / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_cord.tex_y = (int)tex_pos & (game->textures[tex_num].height - 1);
		tex_pos += step;
		color = get_texture_pixel(&game->textures[tex_num], tex_cord.tex_x,
				tex_cord.tex_y);
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
