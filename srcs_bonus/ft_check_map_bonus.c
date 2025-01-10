/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:47:43 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 12:00:56 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.rows > 63)
		ft_error_msg("Invalid Map. "
			"The number of rows is to high. "
			"The Map must have fewer than 64 rows.", game);
	while (i < game->map.rows)
	{
		if (game->map.map_tab[i][0] != WALL)
			ft_error_msg("Invalid Map. "
				"There's a wall missing at the beginning of the row. "
				"The Map must be surrounded by walls!.", game);
		else if (game->map.map_tab[i][game->map.columns - 1] != WALL)
			ft_error_msg("Invalid Map. "
				"There's a wall missing at the end of the row. "
				"The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.columns > 121)
		ft_error_msg("Invalid Map. "
			"The number of columns is too high. "
			"The Map must have fewer than 122 columns.", game);
	while (i < game->map.columns)
	{
		if (game->map.map_tab[0][i] != WALL)
			ft_error_msg("Invalid Map. "
				"There's a wall missing in a column of the first row. "
				"The Map must be surrounded by walls!.", game);
		else if (game->map.map_tab[game->map.rows - 1][i] != WALL)
			ft_error_msg("Invalid Map. "
				"There's a wall missing in a column of the last row. "
				"The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("ECP01X", game->map.map_tab[y][x]))
				ft_error_msg("Invalid Map. Not expected map parameter.", game);
			if (game->map.map_tab[y][x] == PLAYER)
			{
				game->map.count_player++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.map_tab[y][x] == COLL)
				game->map.collectables++;
			else if (game->map.map_tab[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.collectables == 0)
		ft_error_msg("Invalid Map. There's no collectable.", game);
	else if (game->map.exit != 1)
		ft_error_msg("Invalid Map. There should be only one exit.", game);
	else if (game->map.count_player != 1)
		ft_error_msg("Invalid Map. Invalid player number. "
			"It's a single player game.", game);
}

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_check_rectangular(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
	ft_check_for_a_valid_path_to_collectable(game);
	ft_check_for_a_valid_path(game);
}
