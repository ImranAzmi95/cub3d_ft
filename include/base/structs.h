typedef struct s_map_data
{
	char	ea_path[1024];
	char	we_path[1024];
	char	no_path[1024];
	char	so_path[1024];
	char	pos;
	int		ceiling_rgb[3];
	int		stat;
	int		floor_rgb[3];
	char	**map;
}			t_map_data;
