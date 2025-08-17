#include "cub3d.h"

int handle_key(int keycode, void *param)
{
    t_game *game = (t_game *)param;
    
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    else if (keycode == KEY_W)
        move_forward(&game->player, game->map_data.map);
    else if (keycode == KEY_S)
        move_backward(&game->player, game->map_data.map);
    else if (keycode == KEY_A)
        strafe_left(&game->player, game->map_data.map);
    else if (keycode == KEY_D)
        strafe_right(&game->player, game->map_data.map);
    else if (keycode == KEY_LEFT)
        rotate_left(&game->player);
    else if (keycode == KEY_RIGHT)
        rotate_right(&game->player);
    return (0);
}

int game_loop(void *param)
{
    t_game *game = (t_game *)param;
    
    render_frame(game);
    return (0);
}

int start_game(t_map *data)
{
    t_game game;
    
    init_game(&game, data);
    mlx_key_hook(game.win, handle_key, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);
    return (0);
}

int main(int ac, char **av)
{
    t_map data;
    init_data(&data);
    if (ft_parse(ac, av, &data) == -1)
        return(free_arr(data.map));
    if (start_game(&data) == -1)
        return(free_arr(data.map));
    free_arr(data.map);
    return (0);
}