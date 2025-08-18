/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:37:23 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:26:56 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty_cell(char **map, int i, int j)
{
	if (j == 0 || (map[i][j - 1] != '1' && map[i][j - 1] != '0'))
		return (-1);
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0')
		return (-1);
	if (i == 0 || (map[i - 1][j] != '1' && map[i - 1][j] != '0'))
		return (-1);
	if (!map[i + 1] || (map[i + 1][j] != '1' && map[i + 1][j] != '0'))
		return (-1);
	return (0);
}

int	check_map_cell(char **map, int i, int j)
{
	if (j == 0 || !ft_strchr("01NESW", map[i][j - 1]))
		return (-1);
	if (!ft_strchr("01NESW", map[i][j + 1]))
		return (-1);
	if (!ft_strchr("01NESW", map[i - 1][j]))
		return (-1);
	if (!map[i + 1] || !ft_strchr("01NESW", map[i + 1][j]))
		return (-1);
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("0NESW", map[i][j]))
			{
				if (check_map_cell(map, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	handle_player_position(char **map, t_map **data, int i, int j)
{
	(void)map;
	if ((*data)->pos_x >= 0 && (*data)->pos_y >= 0)
		return (-1);
	(*data)->pos_y = i;
	(*data)->pos_x = j;
	return (0);
}

int	check_pos(char **map, t_map **data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NESW", map[i][j]))
			{
				if (handle_player_position(map, data, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	if ((*data)->pos_x < 0 && (*data)->pos_y < 0)
		return (-1);
	return (0);
}
