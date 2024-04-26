/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:44 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:50:51 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define MOVE_SPEED_2 0.1
# define MOVE_SPEED_3 0.175

# define TURN_SPEED 0.05

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# define OUR_W 1
# define OUR_S 2
# define OUR_UP 3
# define OUR_DOWN 4

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define CAR_X 500
# define CAR_Y 830

# define ERROR 1
# define SUCCESS 0

# define MALLOC_ERR "Malloc error.\n"
# define CONFIG_MALLOC_ERR "Malloc Config error.\n"
# define XPM_MALLOC_ERR "Malloc XPM error.\n"
# define COLOR_MALLOC_ERR "Malloc Color error.\n"
# define MAP_MALLOC_ERR "Malloc Map error.\n"
# define MAP_COUNT_1 "Map name not entered. You must enter the map name!\n"
# define MAP_COUNT_GREATER_2 "Only the map name \
	should be entered as an argument.\n"
# define MAP_NULL "Map name cannot be null or empty.\n"
# define MAP_EXTENSION "Map name does not end with the .cub extension.\n"
# define MAP_OPEN "An error occurred while opening the map file.\n"
# define MAP_READ "An error occurred while reading the map file.\n"
# define MAP_EMPTY "Map file must not be empty.\n"
# define NO_ELEMENT "NO element type cannot be more than 1.\n"
# define SO_ELEMENT "SO element type cannot be more than 1.\n"
# define WE_ELEMENT "WE element type cannot be more than 1.\n"
# define EA_ELEMENT "EA element type cannot be more than 1.\n"
# define F_ELEMENT "F element type cannot be more than 1.\n"
# define C_ELEMENT "C element type cannot be more than 1.\n"
# define ELEMENT_TYPES "Only NO, SO, WE, EA, F and \
	C element types can be in the first 6 filled text.\n"
# define CONFIG_LINE "There must be at least 9 text in the \
	configuration file. (4 texture, 2 color, min 3 for map)\n"
# define CONFIG_TEXT "Config->text malloc error.\n" // burayı düzelt
# define CONFIG_MAP "Config->map->text malloc error.\n" // düzelt.
# define MAP_EMPTY_LINE "There can't be empty line on middle \
	of the map or end.\n"
# define NO_ELEMENT_NULL "NO element can't be null.\n"
# define NO_ELEMENT_EXTENSION "NO element must end with the .xpm extension.\n"
# define NO_ELEMENT_OPEN "NO xpm file not found or can't be opened.\n"
# define SO_ELEMENT_EMPTY "SO element cant' be empty.\n"
# define SO_ELEMENT_EXTENSION "SO element must end with the .xpm extension.\n"
# define SO_ELEMENT_OPEN "SO xpm file not found or can't be opened.\n"
# define WE_ELEMENT_NULL "WE element can't be null.\n"
# define WE_ELEMENT_EXTENSION "WE element must end with the .xpm extension.\n"
# define WE_ELEMENT_OPEN "WE xpm file not found or can't be opened.\n"
# define EA_ELEMENT_NULL "EA element can't be null.\n"
# define EA_ELEMENT_EXTENSION "EA element must end with the .xpm extension.\n"
# define EA_ELEMENT_OPEN "EA xpm file not found or can't be opened.\n"

# define F_ELEMENT_EMPTY "F element cant' be empty.\n"
# define F_ELEMENT_VALUE "F take a value in RGB format. The RGB value \
	consists of 3 parts separated by 2 commas.\n"

# define F_ELEM_RED_EMPTY "Red color of F can't be empty.\n"
# define F_ELEM_RED_DIGIT "Red color of F must consist of digit only. (0 - 9)\n"
# define F_ELEM_RED_RANGE "Red color of F must be a value between 0-255.\n"
# define F_ELEM_RED_LEN "Red color of F must be between 1-3 \
	characters. (1 - 10 - 100)\n"

# define F_ELEM_GREEN_EMPTY "Green color of F can't be empty.\n"
# define F_ELEM_GREEN_DIGIT "Green color of F must consist of \
	digit only. (0 - 9)\n"
# define F_ELEM_GREEN_RANGE "Green color of F must be a value between 0-255.\n"
# define F_ELEM_GREEN_LEN "Green color of F must be between \
	1-3 characters. (1 - 10 - 100)\n"

# define F_ELEM_BLUE_EMPTY "Blue color of F can't be empty.\n"
# define F_ELEM_BLUE_DIGIT "Blue color of F must consist of \
	digit only. (0 - 9)\n"
# define F_ELEM_BLUE_RANGE "Blue color of F must be a value between 0-255.\n"
# define F_ELEM_BLUE_LEN "Blue color of F must be between \
	1-3 characters. (1 - 10 - 100)\n"

# define C_ELEMENT_EMPTY "C element cant' be empty.\n"
# define C_ELEMENT_VALUE "C take a value in RGB format. The RGB value \
	consists of 3 parts separated by 2 commas.\n"

# define C_ELEM_RED_EMPTY "Red color of C can't be empty.\n"
# define C_ELEM_RED_LEN "Red color of C must be between 1-3 \
	characters. (1 - 10 - 100)\n"
# define C_ELEM_RED_DIGIT "Red color of C must consist of digit only. (0 - 9)\n"
# define C_ELEM_RED_RANGE "Red color of C must be a value between 0-255.\n"

# define C_ELEM_GREEN_EMPTY "Green color of C can't be empty.\n"
# define C_ELEM_GREEN_LEN "Green color of C must be between 1-3 \
	characters. (1 - 10 - 100)\n"
# define C_ELEM_GREEN_DIGIT "Green color of C must consist of \
	digit only. (0 - 9)\n"
# define C_ELEM_GREEN_RANGE "Green color of C must be a value between 0-255.\n"

# define C_ELEM_BLUE_EMPTY "Blue color of C can't be empty.\n"
# define C_ELEM_BLUE_LEN "Blue color of C must be between 1-3 \
	characters. (1 - 10 - 100)\n"
# define C_ELEM_BLUE_DIGIT "Blue color of C must consist of \
	digit only. (0 - 9)\n"
# define C_ELEM_BLUE_RANGE "Blue color of C must be a value between 0-255.\n"

# define NO_TEXTURE "NO texture can't be used for other textures.\n"
# define SO_TEXTURE "SO texture can't be used for other textures.\n"
# define WE_TEXTURE "WE texture can't be used for other textures.\n"
# define EA_TEXTURE "EA texture can't be used for other textures.\n"

# define F_AND_C_SAME "Floor and ceiling color should not be the same.\n"

# define MAP_CHAR "There can only be 0, 1, N, S, W, E or Space on the map.\n"
# define MAP_PLYR_LESS_1 "There is no Player on the map. (N,S,W,E)\n"
# define MAP_PLYR_MORE_1 "There can only be 1 Player on the map. (N,S,W,E)\n"
# define MAP_PLYR_FIRST "Player can't be on the first row. (N,S,W,E)\n"
# define MAP_PLYR_LAST "Player can't be on the last row. (N,S,W,E)\n"
# define MAP_PLYR_FIRST_COL "Player can't be on the first column. (N,S,W,E)\n"
# define MAP_PLYR_LAST_COL "Player can't be on the last column. (N,S,W,E)\n"

# define MAP_ROW_MALLOC "Create_map_same_row_len malloc error.\n"
# define MAP_ROW_MALLOC_I "Create_map_same_row_len[i] malloc error.\n"

# define MAP_WALL "The map must be closed/surrounded by walls. (1)\n"

# define GAME_MALLOC "Malloc Game error.\n"
# define GAME_SCREEN_MALLOC "Malloc Game screen error.\n"
# define GAME_SC_IMG "Game screen img malloc error.\n"
# define GAME_SC_ADDR "Game screen addr malloc error.\n"

# define MLX_MALLOC "Malloc Mlx error.\n"
# define MLX_WIN_MALLOC "Malloc Mlx window error.\n"

# define NO_IMG_MALLOC "Malloc North img error.\n"
# define NO_IMG_ADDR "North img addr malloc error.\n"

# define SO_IMG_MALLOC "Malloc South img error.\n"
# define SO_IMG_ADDR "South img addr malloc error.\n"

# define WE_IMG_MALLOC "Malloc West img error.\n"
# define WE_IMG_ADDR "West img addr malloc error.\n"

# define EA_IMG_MALLOC "Malloc East img error.\n"
# define EA_IMG_ADDR "East img addr malloc error.\n"

# define PLAYER_MALLOC "Malloc Player error.\n"
# define CAR_TEXTURE_ERR "Car texture not found or can't be opened.\n"

typedef struct s_xpm_files
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_count;
	int		south_count;
	int		west_count;
	int		east_count;
}			t_xpm_files;

typedef struct s_color
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		count;
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_map
{
	char	**text;
	int		starting_line;
	int		row_count;
	int		col_count;

	int		player_count;
	int		player_row;
	int		player_col;
}			t_map;

typedef struct s_config
{
	int			arg_count;
	char		*filename;

	char		**text;
	int			total_line_count;
	int			full_line_count;
	int			empty_line_count;

	t_xpm_files	*xpm_files;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_map		*map;
}				t_config;

typedef struct s_vector_double
{
	double	x;
	double	y;
}			t_vector_double;

typedef struct s_vector_int
{
	int	x;
	int	y;

}		t_vector_int;

typedef struct s_player
{
	t_vector_double	position;
	t_vector_double	direction;
	t_vector_double	camera_plane;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	up_speed;
	int	down_speed;
}		t_keys;

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_mlx_image	*screen;
	t_mlx_image	*north_image;
	t_mlx_image	*south_image;
	t_mlx_image	*west_image;
	t_mlx_image	*east_image;
	int			floor_rgb;
	int			ceiling_rgb;
	t_keys		keys;
	t_player	*player;
}				t_game;

typedef struct s_cub3d
{
	t_config	*config;
	t_game		*game;
	void		*car_0;
	void		*car_1;
	void		*car_2;
	void		*car_3;
	int			tmp_x;
	int			tmp_y;
	int			gear_flag;
	int			gear_count;
}				t_cub3d;

typedef struct s_screen
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen;

typedef struct s_ray
{
	t_vector_int	map_position;
	t_vector_double	real_position;
	t_vector_double	direction;
	t_vector_double	side_dist;
	t_vector_double	next_hit_dist;
	t_vector_int	map_step;
	int				hit_wall;
	char			hit_wall_side;
	double			view_of_wall;
	double			hit_point_wall;
	t_screen		screen;
}					t_ray;

int		init_config(t_cub3d *cub3d, int arg_count, char *filename);
void	free_config(t_cub3d *cub3d);
int		init_xpm_files(t_cub3d *cub3d);
void	free_xpm_files(t_cub3d *cub3d);
int		init_colors(t_cub3d *cub3d);
void	free_colors(t_cub3d *cub3d);
int		init_map(t_cub3d *cub3d);
void	free_map(t_cub3d *cub3d);
void	map_control(t_cub3d *cub3d);
void	verify_config(t_cub3d *cub3d);
void	set_config_line_count(t_cub3d *cub3d, int i);
void	set_config_text(t_cub3d *cub3d);
void	set_elements_count(t_cub3d *cub3d);
void	verify_elements(t_cub3d *cub3d);
void	validate_xpm_files(t_cub3d *cub3d, char *line);
void	validate_floor_color(t_cub3d *cub3d, char *line);
void	validate_ceiling_color(t_cub3d *cub3d, char *line);
void	set_map_text(t_cub3d *cub3d);
char	**create_map_same_row_len(t_cub3d *cub3d);
void	check_map_empty_line(t_cub3d *cub3d);
void	verify_map_characters(t_cub3d *cub3d);
void	verify_map_walls(t_cub3d *cub3d);
void	verify_map_spaces(t_cub3d *cub3d);
void	verify_map(t_cub3d *cub3d);
char	*get_next_line(t_cub3d *cub3d, int fd);
int		is_empty_line(char *line);

void	init_game(t_cub3d *cub3d);
void	free_game(t_cub3d *cub3d);
void	init_mlx(t_cub3d *cub3d);
void	free_mlx(t_cub3d *cub3d);
void	init_screen(t_cub3d *cub3d);
void	free_screen(t_cub3d *cub3d);
void	init_north_mlx_image(t_cub3d *cub3d);
void	init_south_mlx_image(t_cub3d *cub3d);
void	init_west_mlx_image(t_cub3d *cub3d);
void	init_east_mlx_image(t_cub3d *cub3d);
void	init_ceiling_rgb(t_cub3d *cub3d);
void	init_floor_rgb(t_cub3d *cub3d);
void	free_xpm_images(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	free_player(t_cub3d *cub3d);

void	ray_properties(t_ray *ray, t_player *player, int x);
void	ray_draw_until_hit_wall(t_ray *ray, t_map *map);
void	ray_wall_properties(t_ray *ray, t_player *player);
void	ray_texture_properties(t_ray *ray);
void	ray_fill_screen(t_ray *ray, t_game *game, int x);
void	raycasting(t_cub3d *cub3d);

void	player_move_up(t_map *map, t_player *player);
void	player_move_down(t_map *map, t_player *player);
void	player_move_left(t_map *map, t_player *player);
void	player_move_right(t_map *map, t_player *player);
void	player_turn_left(t_player *player);
void	player_turn_right(t_player *player);

size_t	get_image_color(t_mlx_image *image, int x, int y);
void	put_pixel_to_mlx_image(t_mlx_image *image, int x, int y, int color);
int		destroy_handler(t_cub3d *cub3d);
int		keydown_handler(int key, t_cub3d *cub3d);
int		keyup_handler(int key, t_cub3d *cub3d);
int		loop_handler(t_cub3d *cub3d);

t_cub3d	*init_cub3d(int arg_count, char *filename);
void	free_cub3d(t_cub3d *cub3d);
void	free_all(t_cub3d *cub3d);

void	player_move_speed_up2(t_map *map, t_player *player);
void	player_move_speed_up3(t_map *map, t_player *player);
void	transmission_xpm(t_cub3d *cub3d, int gear_flag);
void	key_down_handler_down(int key, t_cub3d *cub3d);
void	keydown_handler_up(int key, t_cub3d *cub3d);
void	keydown_handler_w(int key, t_cub3d *cub3d);
void	validate_comma(t_cub3d *cub3d);

#endif