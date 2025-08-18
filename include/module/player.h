/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:24:13 by lechan            #+#    #+#             */
/*   Updated: 2025/08/18 23:24:14 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "structs.h"

// player_init.c
/**********************/

void	set_player_north(t_player *player);
void	set_player_south(t_player *player);
void	set_player_east(t_player *player);
void	set_player_west(t_player *player);
void	set_player_direction(t_player *player, char direction);

// player_movement.c
/**********************/

void	move_forward(t_player *player, char **map);
void	move_backward(t_player *player, char **map);
void	strafe_left(t_player *player, char **map);
void	strafe_right(t_player *player, char **map);

// player_movement_utils.c
/**********************/

int		is_valid_position_circle(double x, double y, double radius, char **map);
int		is_valid_position(double x, double y, char **map);

// player_rotation.c
/**********************/

void	rotate_left(t_player *player);
void	rotate_right(t_player *player);

#endif
