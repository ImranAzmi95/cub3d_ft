/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechan <lechan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:36:11 by iazmi             #+#    #+#             */
/*   Updated: 2025/08/19 00:01:13 by lechan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_W)
		move_forward(&game->player, game->map_data.map);
	else if (keycode == KEY_S)
		move_backward(&game->player, game->map_data.map);
	else if (keycode == KEY_A)
		strafe_left(&game->player, game->map_data.map);
	else if (keycode == KEY_D)
		strafe_right(&game->player, game->map_data.map);
	else if (keycode == KEY_LEFT)
		rotate_left(&game->player);
	else if (keycode == KEY_RIGHT)
		rotate_right(&game->player);
	return (0);
}

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	render_frame(game);
	return (0);
}

int	start_game(t_map *data)
{
	t_game	game;

	init_game(&game, data);
	mlx_hook(game.win, 3, 1L << 1, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	data;

	init_data(&data);
	if (ft_parse(ac, av, &data) == -1)
		return (free_arr(data.map));
	if (start_game(&data) == -1)
		return (free_arr(data.map));
	free_arr(data.map);
	return (0);
}
