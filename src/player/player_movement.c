/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:37:41 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/18 22:37:43 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player, char **map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x + player->dir_x * MOVE_SPEED;
	new_y = player->pos_y + player->dir_y * MOVE_SPEED;
	if (is_valid_position_circle(new_x, new_y, player->radius, map))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	move_backward(t_player *player, char **map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x - player->dir_x * MOVE_SPEED;
	new_y = player->pos_y - player->dir_y * MOVE_SPEED;
	if (is_valid_position_circle(new_x, new_y, player->radius, map))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	strafe_left(t_player *player, char **map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x - player->plane_x * MOVE_SPEED;
	new_y = player->pos_y - player->plane_y * MOVE_SPEED;
	if (is_valid_position_circle(new_x, new_y, player->radius, map))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	strafe_right(t_player *player, char **map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x + player->plane_x * MOVE_SPEED;
	new_y = player->pos_y + player->plane_y * MOVE_SPEED;
	if (is_valid_position_circle(new_x, new_y, player->radius, map))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}
