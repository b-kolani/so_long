/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:29:07 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 14:25:07 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map.collectables = 0;
	game->map.count_player = 0;
	game->map.exit = 0;
	game->map.columns = ft_strlen_exclude_new_line(game->map.map_tab[0]);
	game->movements = 0;
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_msg("Couldn't initialize MiniLibX.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create a new window.", game);
	}
}

t_img	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_img	sprite;

	sprite.img_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.img_ptr)
		ft_error_msg("Couldn't find a sprite. Does it Exist ?", game);
	return (sprite);
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->collectable = ft_new_sprite(mlx, COLL_XPM, game);
	game->exit_opened = ft_new_sprite(mlx, EXIT_OPENED_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}
