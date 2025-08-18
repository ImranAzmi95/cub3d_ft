/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:37:36 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:31:32 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_position_circle(double x, double y, double radius, char **map)
{
	int		i;
	int		j;
	double	dx;
	double	dy;
	double	dist;

	i = (int)(y - radius);
	while (i <= (int)(y + radius) + 1)
	{
		j = (int)(x - radius);
		while (j <= (int)(x + radius) + 1)
		{
			if (!is_valid_map_pos(j, i, map) || map[i][j] == '1')
			{
				dx = x - (j + 0.5);
				dy = y - (i + 0.5);
				dist = sqrt(dx * dx + dy * dy);
				if (dist < radius + 0.5)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_position(double x, double y, char **map)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (!is_valid_map_pos(map_x, map_y, map))
		return (0);
	if (map[map_y][map_x] == '1')
		return (0);
	return (1);
}
