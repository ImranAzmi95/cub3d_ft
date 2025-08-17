#include "cub3d.h"

int handle_empty(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (ft_is_space(line[i]) == 1)
            i++;
        else
            return (ft_err_msg("Wrong map input"));
    }
    return (0);
}

int read_file(int fd, t_map *data)
{   
    int stat;
    char *line;
    
    stat = 0;
    while ((stat >= 0 && stat < 6) && (line = get_next_line(fd)) != NULL)
    {
        if (ft_strncmp(line, "NO", 2) == 0)
            stat = handle_texture('N', line, data, stat);
        else if (ft_strncmp(line, "SO", 2) == 0)
            stat = handle_texture('S', line, data, stat);
        else if (ft_strncmp(line, "WE", 2) == 0)
            stat = handle_texture('W', line, data, stat);
        else if (ft_strncmp(line, "EA", 2) == 0)
            stat = handle_texture('E', line, data, stat);
        else if (ft_strncmp(line, "F", 1) == 0)
            stat = handle_colour(line, 'F', data, stat);
        else if (ft_strncmp(line, "C", 1) == 0)
            stat = handle_colour(line, 'C', data, stat);
        else if (handle_empty(line) == -1)
            stat = -1;
        free (line);
    }
    return (stat);
}