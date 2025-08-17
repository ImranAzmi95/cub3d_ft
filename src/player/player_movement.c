#include "cub3d.h"

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

void	move_forward(t_player *player, char **map)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x + player->dir_x * MOVE_SPEED;
	new_y = player->pos_y + player->dir_y * MOVE_SPEED;
	if (is_valid_position(new_x, new_y, map))
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
	if (is_valid_position(new_x, new_y, map))
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
	if (is_valid_position(new_x, new_y, map))
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
	if (is_valid_position(new_x, new_y, map))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
	player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROT_SPEED) - player->plane_y * sin(-ROT_SPEED);
	player->plane_y = old_plane_x * sin(-ROT_SPEED) + player->plane_y * cos(-ROT_SPEED);
}

void	rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
	player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROT_SPEED) - player->plane_y * sin(ROT_SPEED);
	player->plane_y = old_plane_x * sin(ROT_SPEED) + player->plane_y * cos(ROT_SPEED);
}