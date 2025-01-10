/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:40:25 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 22:08:27 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin_sl("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, game->map.columns * 12,
		game->map.rows * 30, 0xaaf0ff, phrase);
	free(movements);
	free(phrase);
}

int	ft_check_rectangular(t_game *game)
{
	int		row;
	size_t	line_len;
	size_t	len;

	row = 0;
	line_len = ft_strlen_exclude_new_line(game->map.map_tab[row]);
	while (game->map.map_tab[row])
	{
		len = ft_strlen_exclude_new_line(game->map.map_tab[row]);
		if (len != line_len)
			ft_error_msg("Invalid Map. The Map is not rectangular.", game);
		row++;
	}
	return (0);
}

void	ft_check_command_line_arguments(int ac, char **av, t_game *game)
{
	size_t	map_parameter_len;

	game->is_map_alloc.bool_val = FALSE;
	if (ac > 2)
		ft_error_msg("Too many arguments (It should be only two).", game);
	if (ac < 2)
		ft_error_msg("The Map file is missing.", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extension is wrong (It should be .ber).", game);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
	{
		free(map);
		ft_error_msg("Inavlid Map. "
			"The Map has an empty line right at the beginning.", game);
	}
	else if (map[game->map.rows - 1] == '\n')
	{
		free(map);
		ft_error_msg("Invalid Map. "
			"The Map has an empty line at the end.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid Map. "
				"The Map has an empty line at the middle.", game);
		}
		i++;
	}
}

void	ft_init_map(t_game *game, char *av)
{
	char	*tmp_map;
	char	*tmp_line;
	int		map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("Map file couldn't be opened. Does the Map exist ?", game);
	tmp_map = ft_strdup("");
	if (!tmp_map)
		return ;
	game->map.rows = 0;
	while (TRUE)
	{
		tmp_line = get_next_line(map_fd);
		if (tmp_line == NULL)
			break ;
		tmp_map = ft_append_str(&tmp_map, tmp_line);
		free(tmp_line);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(tmp_map, game);
	game->map.map_tab = ft_split(tmp_map, '\n');
	game->is_map_alloc.bool_val = TRUE;
	free(tmp_map);
}
