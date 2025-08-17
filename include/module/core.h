# include "structs.h"

// parse
/**********************/

int     ft_is_space(char c);
int     ft_err_msg(char *c);
int     ft_valid_name(char *c, char *t);
int     ft_parse(int ac, char **av, t_map *data);

// read file
/**********************/

int     read_file(int fd, t_map *data);
int     handle_empty(char *line);

// read file utils
/**********************/

int     save_texture(char c, char *path, t_map *data);
int     handle_texture(char c, char *line, t_map *data, int stat);
int     save_colour(int count, int result, int *colour);
int     check_colour(int *colour, char *code, int *i, char delimit);
int     handle_colour(char *line, char type, t_map *data, int stat);

// read map
/**********************/

int     valid_map_line(char *line);
int     add_map_line(char ***map, char *line);
int     read_map(int fd, t_map *data);
int     check_map(char **map);

// utils
/**********************/

void    init_data(t_map *data);
int     get_map_len(char **map);
int     free_arr(char **arr);

// colour parse
/**********************/

int     parse_floor_colour(char *line, t_map *data, int *i);
int     parse_ceiling_colour(char *line, t_map *data, int *i);

// read map helpers
/**********************/

int     check_empty_cell(char **map, int i, int j);