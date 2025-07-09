#include "cub3d.h"

/*
ft_isspace()
space will return 1
not space will return 0
*/
int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n'
         || c == '\v' || c == '\f' || c == '\r');
}

int ft_errMsg(char *c)
{
    int i;

    i = 0;
    write(2, "Error\n", 6);
    while (c[i])
        i++;
    write(2, c, i);
    write(2, "\n", 1);
    return (-1);
}

int ft_validName(char *c, char *t)
{
    int i;

    i = 0;
    while (c[i])
        i++;
    if (c[i - 4] !=  t[0])
        return (-1);
    else if (c[i - 3] !=  t[1])
        return (-1);
    else if (c[i - 2] !=  t[2])
        return (-1);
    else if (c[i - 1] !=  t[3])
        return (-1);
    return (0);
}

int ft_parse(int ac, char **av, t_map_data *data)
{
    int fd;
    
    if (ac > 2)
        return (ft_errMsg("Too many arguments"));
    else if (ac == 1)
        return (ft_errMsg("No arguments"));
    else if (ft_validName(av[1],".cub") == 1)
        return (ft_errMsg("Wrong file type"));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (ft_errMsg("Opening file"));
    if (readFile(fd, data) == -1)
        return (-1);
    else
        readMap(fd, data);
    if (!data->map)
        return (ft_errMsg("Map is empty"));
    close (fd);
    if (check_map(data->map) == -1)
        return (ft_errMsg("Map is Invalid"));
    return (0);
}