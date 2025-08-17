#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structs.h"

// ray_cast_init.c
/**********************/

int		is_player_char(char c);
void	set_player_position(t_player *player, int i, int j, char direction);
void	init_player(t_player *player, char **map);
void	init_ray(t_ray *ray, t_player *player, int x, int screen_width);
void	init_game(t_game *game, t_map *map_data);

// ray_cast_dda.c
/**********************/

void	calculate_step_and_side_dist(t_ray *ray, t_player *player);
void	perform_dda(t_ray *ray, char **map);
void	calculate_wall_distance(t_ray *ray, t_player *player);
void	calculate_wall_height(t_ray *ray, int screen_height);

// ray_cast_utils.c
/**********************/

int		get_texture_index(t_ray *ray);
double	get_wall_x(t_ray *ray, t_player *player);
int		is_valid_map_pos(int x, int y, char **map);
void	put_pixel(t_game *game, int x, int y, int color);

#endif