#include "cub3d.h"


int save_texture(char c, char *path, t_data *data)
{
    if (c == 'N' && data->no_path[0] != '\0')
        return ft_errMsg("Duplicate NO texture");
    if (c == 'S' && data->so_path[0] != '\0')
        return ft_errMsg("Duplicate SO texture");
    if (c == 'W' && data->we_path[0] != '\0')
        return ft_errMsg("Duplicate WE texture");
    if (c == 'E' && data->ea_path[0] != '\0')
        return ft_errMsg("Duplicate EA texture");
    if (c == 'N' && data->no_path[0] == '\0')
        ft_strlcpy(data->no_path, path, sizeof(data->no_path));
    if (c == 'S' && data->so_path[0] == '\0')
        ft_strlcpy(data->so_path, path, sizeof(data->so_path));
    if (c == 'W' && data->we_path[0] == '\0')
        ft_strlcpy(data->we_path, path, sizeof(data->we_path));
    if (c == 'E' && data->ea_path[0] == '\0')
        ft_strlcpy(data->ea_path, path, sizeof(data->ea_path));
    return (0);    
}

int handle_texture(char c, char *line, t_data *data, int stat)
{
    char *path;
    int i;
    
    i = 2;
    if (ft_isspace(line[i]) == 0)
        return(ft_errMsg("Wrong texture format"));
    while (ft_isspace(line[i]) == 1)
        i++;
    path = line + i;
    if (*path == '\0')
        return (ft_errMsg("missing texture file"));
    if ((ft_validName(path,".xpm") == 1) || (open(path, O_RDONLY) < 0))
        return(ft_errMsg("Wrong input path"));
    if (save_texture(c, path, data) == -1)
        return (-1);
    return (stat + 1);
}

int save_colour(int count, int result, int *colour)
{
    if (count == 0)
        return ft_errMsg("Missing colour value");
    if (result < 0 || result > 255)
        return ft_errMsg("Colour out of range");
    if (*colour > -1)
        return ft_errMsg("Duplicate colour code");
    *colour = result;
    return (1);
}

int check_colour(int *colour, char *code, int *i, char delimit)
{
    int result;
    int count;

    count = 0;
    result = 0;
    while (ft_isspace(code[*i]) == 1)
        (*i)++;
    if (!ft_isdigit(code[*i]))
        return (ft_errMsg("Expected digit only in colour"));
    while (ft_isdigit(code[*i]))
    {
        result = result * 10 + (code[*i] - '0');
        (*i)++;
        count++;
    }
    while (ft_isspace(code[*i]) == 1)
        (*i)++;
    if (code[*i] == delimit)
        (*i)++;
    else
        return (ft_errMsg("Wrong input"));
    return (save_colour(count, result, colour));
}

int handle_colour(char *line, char type, t_data *data, int stat)
{
    int i;

    i = 1;
    if (ft_isspace(line[i]) == 0)
        return(ft_errMsg("Wrong colour format"));
    while (ft_isspace(line[i]) == 1)
        i++;
    if (*(line + i) == '\0')
        return (ft_errMsg("missing colour code"));
    if (type == 'F')
    {
        if (check_colour(&data->flo[0], line, &i, ',') == -1 ||
            check_colour(&data->flo[1], line, &i, ',') == -1 ||
            check_colour(&data->flo[2], line, &i, '\0') == -1)
        return (-1);
    }
    if (type == 'C')
    {
        if (check_colour(&data->cei[0], line, &i, ',') == -1 ||
            check_colour(&data->cei[1], line, &i, ',') == -1 ||
            check_colour(&data->cei[2], line, &i, '\0') == -1)
        return (-1);
    }
    return (stat + 1);
}