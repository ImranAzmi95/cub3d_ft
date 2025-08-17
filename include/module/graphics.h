#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "structs.h"

// texture_loader.c
/**********************/

int		load_texture(t_game *game, t_texture *texture, char *path);
int		load_all_textures(t_game *game);
int		get_texture_pixel(t_texture *texture, int x, int y);

// ray_cast.c (rendering functions)
/**********************/

int		calculate_tex_x(t_game *game, t_ray *ray, int tex_num, double wall_x);
void	draw_wall_column(t_game *game, t_ray *ray, int x, int tex_num);
void	draw_textured_wall(t_game *game, t_ray *ray, int x);
void	cast_ray(t_game *game, int x);
void	render_frame(t_game *game);

#endif