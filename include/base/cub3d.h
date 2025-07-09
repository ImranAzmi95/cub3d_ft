#ifndef CUB3D
# define CUB3D

// System headers
/**********************/

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// External library headers
/**********************/

# include "get_next_line.h"
# include "libft.h"

// Graphics library headers
/**********************/

# include "mlx.h"

// Base project headers
/**********************/

# include "macros.h"
# include "structs.h"

// Module headers
/**********************/



typedef struct s_data
{
    char ea_path[1024];
    char we_path[1024];
    char no_path[1024];
    char so_path[1024];
    char pos;
    int stat;
    int cei[3];
    int flo[3];
    char **map;
} t_data;

char    *get_next_line(int fd); // if you're using your own GNL
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *src);
int	    ft_isdigit(int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size);

int     ft_isspace(char c);
int     ft_errMsg(char *c);
int     ft_validName(char *c, char *t);
int     save_texture(char c, char *path, t_data *data);
int     handle_texture(char c, char *line, t_data *data, int stat);
int     save_colour(int count, int result, int *colour);
int     check_colour(int *colour, char *code, int *i, char delimit);
int     handle_colour(char *line, char type, t_data *data, int stat);
int     handle_empty(char *line);
int     readFile(int fd, t_data *data);
int     valid_map_line(char *line);
int     add_map_line(char ***map, char *line);
int     readMap(int fd, t_data *data);
int     check_map(char **map);
int     ft_parse(int ac, char **av, t_data *data);
void    init_data(t_data *data);
int     free_arr(char **arr);


#endif