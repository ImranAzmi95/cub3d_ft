/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:37:27 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:54:49 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
valid_map_line
return 1 for any presence of 1, 0 , N, E, S, W
return 0 for line with all space
return -1 for others
*/
int	valid_map_line(char *line)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (line[i])
	{
		if (ft_strchr("10NSEW", line[i]))
			start = 1;
		else if (ft_is_space(line[i]) == 0)
			return (ft_err_msg("Invalid map"));
		i++;
	}
	return (start);
}

int	add_map_line(char ***map, char *line)
{
	int		len;
	int		i;
	char	**new_map;

	len = get_map_len(*map);
	i = -1;
	new_map = malloc(sizeof(char *) * (len + 2));
	if (new_map == NULL)
		return (0);
	while (++i < len)
		new_map[i] = (*map)[i];
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	new_map[len] = ft_strdup(line);
	new_map[len + 1] = NULL;
	if (*map)
		free (*map);
	*map = new_map;
	return (1);
}

int	read_map(int fd, t_map *data)
{
	char	*line;
	int		stat;
	int		map_started;

	map_started = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		stat = valid_map_line(line);
		if (stat == -1)
			return (free(line), ft_err_msg("Invalid map element"));
		else if (stat == 1)
			map_started = add_map_line(&data->map, line);
		else if (stat == 0 && map_started)
			return (free(line), ft_err_msg("Invalid map format"));
		free(line);
	}
	return (0);
}
