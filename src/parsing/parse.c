/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:36:19 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:57:46 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
ft_isspace()
space will return 1
not space will return 0
*/
int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_err_msg(char *c)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (c[i])
		i++;
	write(2, c, i);
	write(2, "\n", 1);
	return (-1);
}

int	ft_valid_name(char *c, char *t)
{
	int	i;

	i = 0;
	while (c[i] && c[i] != '\n')
		i++;
	if (c[i - 4] != t[0])
		return (-1);
	else if (c[i - 3] != t[1])
		return (-1);
	else if (c[i - 2] != t[2])
		return (-1);
	else if (c[i - 1] != t[3])
		return (-1);
	return (0);
}

int	ft_parse(int ac, char **av, t_map *data)
{
	int	fd;

	if (ac > 2)
		return (ft_err_msg("Too many arguments"));
	else if (ac == 1)
		return (ft_err_msg("No arguments"));
	else if (ft_valid_name(av[1], ".cub") == 1)
		return (ft_err_msg("Wrong file type"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_err_msg("Opening file"));
	if (read_file(fd, data, 0) == -1)
		return (ft_err_msg("Not complete input"));
	else
		read_map(fd, data);
	if (!data->map)
		return (ft_err_msg("Map is empty"));
	close (fd);
	if (check_map(data->map) == -1)
		return (ft_err_msg("Map is Invalid"));
	if (check_pos(data->map, &data) == -1)
		return (ft_err_msg("Player is Invalid"));
	return (0);
}
