/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:24:38 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 16:23:39 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->player_front.img);
	mlx_destroy_image(game->mlx, game->player_left.img);
	mlx_destroy_image(game->mlx, game->player_right.img);
	mlx_destroy_image(game->mlx, game->player_back.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
}
int	free_game(t_game *game)
{
	if (game->map.grid)
		free_map(game);
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (SUCCSES);
}