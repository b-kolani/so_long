/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:44:51 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 12:00:33 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "unistd.h"
# include "fcntl.h"
# include "../../../minilibx-linux/mlx.h"
# include "../../utils/utils.h"
# include "X11/X.h"

/*---- IMAGE_SIZE_MACROS ----*/
# define IMG_HEIGHT 32
# define IMG_WIDTH 32

/*---- MAP_MACROS ----*/
# define WALL '1'
# define FLOOR '0'
# define COLL 'C'
# define PLAYER 'P'
# define ENEMY 'X'
# define EXIT 'E'

/*---- WASD_KEYS_MACROS ----*/
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/*---- ARROW_KEYS_MACROS ----*/
# define UP_KEY 65362
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define DOWN_KEY 65364

/*---- CLOSE_WIND_KEYS_MACROS ----*/
# define KEY_Q 113
# define ESC_KEY 65307

/*---- PLAYER_MOVEMENTS_MACROS ----*/
# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

/*---- FRAME_MACRO ----*/
# define FRAME_PER_RENDER 7

/*---- SPRITES_MACROS ----*/
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define WALL_XPM "assets/sprites/wall.xpm"
# define COLL_XPM "assets/sprites/collectable.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back.xpm"
# define EXIT_OPENED_XPM "assets/sprites/exit_opened.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit_closed.xpm"
# define ENEMY_RIGHT_XPM "assets/sprites/enemy_right.xpm"
# define ENEMY_LEFT_XPM "assets/sprites/enemy_left.xpm"

/*---- COLORS_MACROS ----*/
# define RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define GREY "\033[0;90m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

/*---- BOOL_MACROS ----*/
# define TRUE 1
# define FALSE 0

/*---- STRUCT_TYPES_DEF ----*/
typedef struct s_bool
{
	int	bool_val;
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_img
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	char		**map_tab;
	int			rows;
	int			columns;
	int			collectables;
	int			exit;
	int			count_player;
	t_position	player;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		movements;
	int		player_sprite;
	int		enemy_sprite;
	t_map	map;
	t_bool	is_map_alloc;
	t_img	wall;
	t_img	floor;
	t_img	collectable;
	t_img	exit_opened;
	t_img	exit_closed;
	t_img	player_front;
	t_img	player_left;
	t_img	player_right;
	t_img	player_back;
	t_img	enemy_right;
	t_img	enemy_left;
}	t_game;

# define TRUE 1
# define FALSE 0

/*---- PARSING_FUNCTIONS ----*/
void	ft_check_map(t_game *game);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_verify_map_parameters(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_check_for_a_valid_path(t_game *game);
int		ft_check_rectangular(t_game *game);
void	ft_check_for_a_valid_path_to_collectable(t_game *game);
void	ft_flood_fill_exit(char **map_tab, int y, int x);
void	ft_flood_fill_collectable(char **map_tab, int y, int x);

/*---- SO_LONG_FUNCTIONS ----*/
void	ft_check_command_line_arguments(int ac, char **av, t_game *game);
void	ft_init_map(t_game *game, char *av);
void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_img	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_enemy(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_img sprite, int col, int line);
int		ft_handle_input(int key, t_game *game);
void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite);
int		ft_win(t_game *game);
int		ft_lose(t_game *game);
int		ft_error_msg(char *msg, t_game *game);	
int		ft_close_game(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *agme);
void	ft_free_map(t_game *game);
void	ft_print_movements(t_game *game);

/*---- UTILS_FUNCTIONS ----*/
char	*ft_append_str(char	**s1, const char *s2);
void	ft_copy_map(char **dest, char **src, int rows);
void	ft_free_tmp_map(char **map, int rows);
size_t	ft_strlen_exclude_new_line(const char *str);
char	*ft_strjoin_sl(char *s1, char *s2);

#endif