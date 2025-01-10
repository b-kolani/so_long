/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:49:02 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 21:41:37 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->collectable.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_opened.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy_left.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy_right.img_ptr);
}

void	ft_free_map(t_game *game)
{
	int	str_line;

	str_line = 0;
	while (str_line < game->map.rows)
		free(game->map.map_tab[str_line++]);
	free(game->map.map_tab);
}

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_destroy_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
