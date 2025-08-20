/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:37:32 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/20 23:42:21 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 1;
	player->plane_y = 0;
	player->fov_scale = FOV_SCALE;
}

void	set_player_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -1;
	player->plane_y = 0;
	player->fov_scale = FOV_SCALE;
}

void	set_player_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 1;
	player->fov_scale = FOV_SCALE;
}

void	set_player_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -1;
	player->fov_scale = FOV_SCALE;
}

void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
		set_player_north(player);
	else if (direction == 'S')
		set_player_south(player);
	else if (direction == 'E')
		set_player_east(player);
	else if (direction == 'W')
		set_player_west(player);
}
