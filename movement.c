/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:43:10 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 17:20:34 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	player_dir(t_game *game, int direction)
{
	if (direction == XK_Right)
		game->player.img = game->player_right.img;
	if (direction == XK_Left)
		game->player.img = game->player_left.img;
	if (direction == XK_Up)
		game->player.img = game->player_back.img;
	if (direction == XK_Down)
		game->player.img = game->player_front.img;
}

void	move_player(t_game *game, int direction, int y, int x)
{
	int	old_x;
	int	old_y;

	if (game->map.grid[y][x] != WALL)
	{
		if (game->map.grid[y][x] == COLLECT)
			game->collected++;
		if (game->map.grid[y][x] == EXIT)
			return close_game(game);
		player_dir(game, direction);
		old_y = game->player.pos.y;
		old_x = game->player.pos.x;
		game->player.pos.y = y;
		game->player.pos.x = x;
		game->map.grid[y][x] = PLAYER;
		game->map.grid[old_y][old_x] = FLOOR;
		game->moves++;
		ft_render_map(game);
	}
}

int	ft_input(int key, t_game *game)
{
	int	y;
	int	x;

	y = game->player.pos.y;
	x = game->player.pos.x;
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (key == XK_Right)
		move_player(game, XK_Right, y, x + 1);
	else if (key == XK_Left)
		move_player(game, XK_Left, y, x - 1);
	else if (key == XK_Down)
		move_player(game, XK_Down, y + 1, x);
	else if (key == XK_Up)
		move_player(game, XK_Up, y - 1, x);
	return (0);
}
