/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:24:09 by lechan            #+#    #+#             */
/*   Updated: 2025/08/18 23:24:10 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "structs.h"

// texture_loader.c
/**********************/

int		load_texture(t_game *game, t_texture *texture, char *path);
int		load_all_textures(t_game *game);
int		get_texture_pixel(t_texture *texture, int x, int y);

// ray_cast.c (rendering functions)
/**********************/

int		calculate_tex_x(t_game *game, t_ray *ray, int tex_num, double wall_x);
void	draw_wall_column(t_game *game, t_ray *ray, int x, int tex_num);
void	draw_textured_wall(t_game *game, t_ray *ray, int x);
int		calculate_ceiling_color(t_game *game);
int		calculate_floor_color(t_game *game);
void	draw_ceiling_floor(t_game *game, t_ray *ray, int x);
void	cast_ray(t_game *game, int x);
void	render_frame(t_game *game);

#endif