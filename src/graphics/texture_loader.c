/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:36:05 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/18 22:36:07 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_game *game, t_texture *texture, char *path)
{
	printf("Loading texture: %s\n", path);
	texture->img = mlx_xpm_file_to_image(game->mlx, path, 
		&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Failed to load texture: %s\n", path);
		return (-1);
	}
	texture->addr = mlx_get_data_addr(texture->img, 
		&texture->bits_per_pixel, &texture->line_length, 
		&texture->endian);
	if (!texture->addr)
	{
		printf("Failed to get texture data: %s\n", path);
		return (-1);
	}
	printf("Successfully loaded texture: %s (%dx%d)\n", path, texture->width, texture->height);
	return (0);
}

int	load_all_textures(t_game *game)
{
	if (load_texture(game, &game->textures[0], 
		game->map_data.no_path) == -1)
		return (-1);
	if (load_texture(game, &game->textures[1], 
		game->map_data.so_path) == -1)
		return (-1);
	if (load_texture(game, &game->textures[2], 
		game->map_data.ea_path) == -1)
		return (-1);
	if (load_texture(game, &game->textures[3], 
		game->map_data.we_path) == -1)
		return (-1);
	return (0);
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + 
		x * (texture->bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}