#include "cub3d.h"

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