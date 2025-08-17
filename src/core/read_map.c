#include "cub3d.h"

/*
valid_map_line
return 1 for any presence of 1, 0 , N, E, S, W
return 0 for line with all space
return -1 for others
*/
int valid_map_line(char *line)
{
    int i;
    int start;
    char c;

    i = 0;
    start = 0;
    while (line[i])
    {
        c = line[i];
        if (c == '1' || c == '0' || c == 'N')
            start = 1 ;
        else if (c == 'E' || c == 'S' || c == 'W')
            start = 1 ;
        else if (ft_is_space(c) == 0)
            return (ft_err_msg("Invalid map"));
        i++;
    }
    return (start);
}


int add_map_line(char ***map, char *line)
{
    int len;
    int i;
    char **new_map;

    len = get_map_len(*map);
    i = -1;
    new_map = malloc(sizeof(char *) * (len + 2));
    if (new_map == NULL)
        return (0);
    while (++i < len)
        new_map[i] = (*map)[i];
    if (line[ft_strlen(line) - 1] == '\n')
        line[ft_strlen(line) - 1] = '\0';
    new_map[len] = ft_strdup(line);
    new_map[len + 1] = NULL;
    if (*map)
        free (*map);
    *map = new_map;
    return (1);
}

int read_map(int fd, t_map *data)
{   
    char *line;
    int stat;
    int map_started;

    map_started = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        stat = valid_map_line(line);
        if (stat == -1)
        {
            free(line);
            return (ft_err_msg("Invalid map element"));
        }
        else if (stat == 1)
            map_started = add_map_line(&data->map, line);
        else if (stat == 0 && map_started)
        {
            free(line);
            return (ft_err_msg("Invalid map format"));
        }
        free(line);
    }
    return (0);
}

int check_empty_cell(char **map, int i, int j)
{
    if (j == 0 || (map[i][j - 1] != '1' && map[i][j - 1] != '0'))
        return (-1);
    if (map[i][j + 1] != '1' && map[i][j + 1] != '0')
        return (-1);
    if (i == 0 || (map[i - 1][j] != '1' && map[i - 1][j] != '0'))
        return (-1);
    if (!map[i + 1] || (map[i + 1][j] != '1' && map[i + 1][j] != '0'))
        return (-1);
    return (0);
}

int check_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0' && check_empty_cell(map, i, j) == -1)
                return (-1);
            j++;            
        }
        i++;
    }
    return (0);
}