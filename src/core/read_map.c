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
 
    i = 0;
    start = 0;
    while (line[i])
    {
        if (ft_strchr("10NSEW", line[i]))
            start = 1;
        else if (ft_is_space(line[i]) == 0)
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

    len = 0;
    i = -1;
    if (*map)
    {
        while ((*map)[len] != NULL)
            len++;
    }
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
            return (free(line), ft_err_msg("Invalid map element"));
        else if (stat == 1)
            map_started = add_map_line(&data->map, line);
        else if (stat == 0 && map_started)
            return (free(line), ft_err_msg("Invalid map format"));
        free(line);
    }
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
            if (ft_strchr("0NESW", map[i][j]))
            {
                if (j == 0 || !ft_strchr("01NESW", map[i][j - 1]))
                    return (-1);
                if (!ft_strchr("01NESW", map[i][j + 1]))
                    return (-1);
                if (!ft_strchr("01NESW", map[i - 1][j]))
                    return (-1);
                if (!map[i + 1] || !ft_strchr("01NESW", map[i + 1][j]))
                    return (-1);
            }
            j++;            
        }
        i++;
    }
    return (0);
}

int check_pos(char **map, t_map **data)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_strchr("NESW", map[i][j]))
            {
                if ((*data)->pos_x >= 0 && (*data)->pos_y >= 0)
                    return (-1);
                (*data)->pos_y = i;
                (*data)->pos_x = j;
            }
            j++;            
        }
        i++;
    }
    if ((*data)->pos_x < 0 && (*data)->pos_y < 0)
        return (-1);
    return (0);
}