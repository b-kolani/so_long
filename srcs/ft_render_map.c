/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:24:11 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 11:50:59 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

void	ft_identify_sprite(t_game *game, int x, int y)
{
	char	parameter;

	parameter = game->map.map_tab[y][x];
	if (parameter == WALL)
		ft_render_sprite(game, game->wall, x, y);
	else if (parameter == FLOOR)
		ft_render_sprite(game, game->floor, x, y);
	else if (parameter == COLL)
		ft_render_sprite(game, game->collectable, x, y);
	else if (parameter == EXIT)
	{
		if (game->map.collectables == 0)
			ft_render_sprite(game, game->exit_opened, x, y);
		else
			ft_render_sprite(game, game->exit_closed, x, y);
	}
	else if (parameter == PLAYER)
		ft_render_player(game, x, y);
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
	return (0);
}
