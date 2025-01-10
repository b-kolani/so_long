/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:15:35 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 21:29:34 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_render_sprite(t_game *game, t_img sprite, int col, int line)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		sprite.img_ptr, col * sprite.x, line * sprite.y);
}

void	ft_render_player(t_game *game, int x, int y)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite(game, game->player_front, x, y);
	if (game->player_sprite == BACK)
		ft_render_sprite(game, game->player_back, x, y);
	if (game->player_sprite == LEFT)
		ft_render_sprite(game, game->player_left, x, y);
	if (game->player_sprite == RIGHT)
		ft_render_sprite(game, game->player_right, x, y);
}

void	ft_render_enemy(t_game *game, int x, int y)
{
	static int	i;

	if (++i <= FRAME_PER_RENDER)
	{
		game->enemy_sprite = RIGHT;
		ft_render_sprite(game, game->enemy_right, x, y);
	}
	else if (i > FRAME_PER_RENDER && i <= FRAME_PER_RENDER * 2)
	{
		game->enemy_sprite = LEFT;
		ft_render_sprite(game, game->enemy_left, x, y);
	}
	else
	{
		game->enemy_sprite = RIGHT;
		ft_render_sprite(game, game->enemy_right, x, y);
		i = 0;
	}
}

void	ft_identify_sprite(t_game *game, int x, int y)
{
	char	parameter;

	parameter = game->map.map_tab[y][x];
	if (parameter == WALL)
		ft_render_sprite(game, game->wall, x, y);
	else if (parameter == COLL)
		ft_render_sprite(game, game->collectable, x, y);
	else if (parameter == FLOOR)
		ft_render_sprite(game, game->floor, x, y);
	else if (parameter == EXIT)
	{
		if (game->map.collectables == 0)
			ft_render_sprite(game, game->exit_opened, x, y);
		else
			ft_render_sprite(game, game->exit_closed, x, y);
	}
	else if (parameter == PLAYER)
		ft_render_player(game, x, y);
	else if (parameter == ENEMY)
		ft_render_enemy(game, x, y);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}
