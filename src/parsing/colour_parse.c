/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:36:16 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:04:48 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_floor_colour(char *line, t_map *data, int *i)
{
	if (check_colour(&data->floor_rgb[0], line, i, ',') == -1
		|| check_colour(&data->floor_rgb[1], line, i, ',') == -1
		|| check_colour(&data->floor_rgb[2], line, i, '\0') == -1)
		return (-1);
	return (0);
}

int	parse_ceiling_colour(char *line, t_map *data, int *i)
{
	if (check_colour(&data->ceiling_rgb[0], line, i, ',') == -1
		|| check_colour(&data->ceiling_rgb[1], line, i, ',') == -1
		|| check_colour(&data->ceiling_rgb[2], line, i, '\0') == -1)
		return (-1);
	return (0);
}
