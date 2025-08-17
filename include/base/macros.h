#ifndef MACROS_H
# define MACROS_H

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define TEXTURE_SIZE 64
# define MAP_SIZE 24
# define FOV 60
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.2

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

#endif