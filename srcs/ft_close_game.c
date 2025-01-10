/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:49:54 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 11:24:28 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_win(t_game *game)
{
	ft_printf("%s\n                 \
	Movements: %d%s\n", YELLOW, ++game->movements, RESET);
	ft_free_all_allocated_memory(game);
	ft_printf("%s\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
	%s\n", GREEN, RESET);
	exit(EXIT_SUCCESS);
}

int	ft_close_game(t_game *game)
{
	ft_printf("%s\n                 \
	Movements: %d%s\n", YELLOW, game->movements, RESET);
	ft_free_all_allocated_memory(game);
	ft_printf("%sWINDOW CLOSED!%s\n", GREY, RESET);
	exit(EXIT_SUCCESS);
}

int	ft_error_msg(char *msg, t_game *game)
{
	if (game->is_map_alloc.bool_val == TRUE)
		ft_free_map(game);
	free(game);
	ft_printf("%sError\n%s%s%s\n", RED, GREY, msg, RESET);
	exit(EXIT_FAILURE);
}