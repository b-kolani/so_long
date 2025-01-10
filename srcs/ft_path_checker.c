/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:03:21 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 22:11:45 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_flood_fill_exit(char **map_tab, int y, int x)
{
	if (map_tab[y][x] == WALL || map_tab[y][x] == 'F')
		return ;
	map_tab[y][x] = 'F';
	ft_flood_fill_exit(map_tab, y, x - 1);
	ft_flood_fill_exit(map_tab, y + 1, x);
	ft_flood_fill_exit(map_tab, y, x + 1);
	ft_flood_fill_exit(map_tab, y - 1, x);
}

void	ft_flood_fill_collectable(char **map_tab, int y, int x)
{
	if (map_tab[y][x] == WALL || map_tab[y][x] == 'F' || map_tab[y][x] == EXIT)
		return ;
	map_tab[y][x] = 'F';
	ft_flood_fill_collectable(map_tab, y, x - 1);
	ft_flood_fill_collectable(map_tab, y + 1, x);
	ft_flood_fill_collectable(map_tab, y, x + 1);
	ft_flood_fill_collectable(map_tab, y - 1, x);
}

void	ft_check_for_a_valid_path(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		p_col;
	int		p_row;

	p_col = game->map.player.x;
	p_row = game->map.player.y;
	tmp_map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!tmp_map)
		return ;
	ft_copy_map(tmp_map, game->map.map_tab, game->map.rows);
	ft_flood_fill_exit(tmp_map, p_row, p_col);
	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strchr(tmp_map[i], EXIT))
		{
			ft_free_tmp_map(tmp_map, game->map.rows);
			ft_error_msg("Invalid Map. Make sure "
				"that there's a valid path to exit.",
				game);
		}
		i++;
	}
	ft_free_tmp_map(tmp_map, game->map.rows);
}

void	ft_check_for_a_valid_path_to_collectable(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		p_col;
	int		p_row;

	p_col = game->map.player.x;
	p_row = game->map.player.y;
	tmp_map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!tmp_map)
		return ;
	ft_copy_map(tmp_map, game->map.map_tab, game->map.rows);
	ft_flood_fill_collectable(tmp_map, p_row, p_col);
	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strchr(tmp_map[i], COLL))
		{
			ft_free_tmp_map(tmp_map, game->map.rows);
			ft_error_msg("Invalid Map. Make sure "
				"that there's a valid path to pick a collectable.",
				game);
		}
		i++;
	}
	ft_free_tmp_map(tmp_map, game->map.rows);
}
