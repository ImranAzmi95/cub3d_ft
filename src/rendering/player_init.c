#include "cub3d.h"

void	set_player_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

void	set_player_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

void	set_player_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	set_player_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
		set_player_north(player);
	else if (direction == 'S')
		set_player_south(player);
	else if (direction == 'E')
		set_player_east(player);
	else if (direction == 'W')
		set_player_west(player);
}