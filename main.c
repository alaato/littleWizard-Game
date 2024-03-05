/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:58:22 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 17:18:19 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ERROR);
	game->player_front = ft_new_sprite(game->mlx, "images/front.xpm", game);
	game->player_back = ft_new_sprite(game->mlx, "images/back.xpm", game);
	game->player_right = ft_new_sprite(game->mlx, "images/right.xpm", game);
	game->player_left = ft_new_sprite(game->mlx, "images/left.xpm", game);
	game->collectible = ft_new_sprite(game->mlx, "images/collect.xpm", game);
	game->exit = ft_new_sprite(game->mlx, "images/door.xpm", game);
	game->floor = ft_new_sprite(game->mlx, "images/floor.xpm", game);
	game->wall = ft_new_sprite(game->mlx, "images/wall.xpm", game);
	game->player.img = game->player_front.img;
	game->player.size = (t_vector){50, 50};
	game->collected = 0;
	game->moves = 0;
	game->win = mlx_new_window(game->mlx, game->map.width * 50, game->map.height
			* 50, "so_long!");
	if (!game->win)
		return (ERROR);
	return (0);
}

int	loop(t_game *game)
{
	mlx_do_sync(game->mlx);
	return (0);
}

int	main(int argc, char **args)
{
	t_game	game;

	if (argc < 2)
		return (error_message("no arguments", &game));
	game.map = (t_map){args[1], 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0};
	if (parse_map(&game) == ERROR)
		return (ERROR);
	init_game(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &ft_input, &game);
	mlx_expose_hook(game.win, &ft_render_map, &game);
	mlx_loop_hook(game.mlx, &loop, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
