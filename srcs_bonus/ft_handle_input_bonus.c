/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:08:10 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 14:00:26 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = player_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.map_tab[new_y][new_x] == EXIT
		&& game->map.collectables == 0)
		ft_win(game);
	else if (game->map.map_tab[new_y][new_x] == ENEMY)
		ft_lose(game);
	else if (game->map.map_tab[new_y][new_x] == FLOOR
		|| game->map.map_tab[new_y][new_x] == COLL)
	{
		game->map.map_tab[last_y][last_x] = FLOOR;
		if (game->map.map_tab[new_y][new_x] == COLL)
			game->map.collectables--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.map_tab[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
}

int	ft_handle_input(int key, t_game *game)
{
	if (key == UP_KEY || key == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (key == LEFT_KEY || key == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (key == RIGHT_KEY || key == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (key == DOWN_KEY || key == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (key == ESC_KEY || key == KEY_Q)
		ft_close_game(game);
	ft_printf("%sMovements : %d%s\n", YELLOW, game->movements, RESET);
	return (0);
}
