#include "cub3d.h"

void	move_forward(t_player *player, char **map)
{
	(void)map;
	player->pos_x += player->dir_x * MOVE_SPEED;
	player->pos_y += player->dir_y * MOVE_SPEED;
}

void	move_backward(t_player *player, char **map)
{
	(void)map;
	player->pos_x -= player->dir_x * MOVE_SPEED;
	player->pos_y -= player->dir_y * MOVE_SPEED;
}

void	strafe_left(t_player *player, char **map)
{
	(void)map;
	player->pos_x -= player->plane_x * MOVE_SPEED;
	player->pos_y -= player->plane_y * MOVE_SPEED;
}

void	strafe_right(t_player *player, char **map)
{
	(void)map;
	player->pos_x += player->plane_x * MOVE_SPEED;
	player->pos_y += player->plane_y * MOVE_SPEED;
}