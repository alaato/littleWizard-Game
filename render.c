/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:29:40 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 19:51:20 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
void display_text(t_game *game){

	char *moves;
	char *text;

	moves = ft_itoa(game->moves);
	text = ft_strjoin("moves made: ", moves);

	ft_printf("%s\n", text);
	mlx_set_font(game->mlx, game->win, "-Misc-Fixed-Bold-R-Normal--18-120-100-100-C-90-ISO10646-1");
	mlx_string_put(game->mlx, game->win, 4, 30, 0xB00058, text);

}
t_obj	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_obj	sprite;

	sprite.img = mlx_xpm_file_to_image(mlx, path, &sprite.size.x,
			&sprite.size.y);
	if (sprite.img == NULL)
		error_message("Couldn't find a sprite. Does it exist?", game);
	return (sprite);
}

void	render_obj(t_game *game, t_obj obj, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, obj.img, x * obj.size.x, y
		* obj.size.y);
}

void	render_sprites(t_game *game, int y, int x)
{
	char	parameter;

	render_obj(game, game->floor, y, x);
	parameter = game->map.grid[y][x];
	if (parameter == WALL)
		render_obj(game, game->wall, y, x);
	else if (parameter == COLLECT)
		render_obj(game, game->collectible, y, x);
	else if (parameter == EXIT)
		render_obj(game, game->exit, y, x);
	else if (parameter == PLAYER)
		render_obj(game, game->player, y, x);

}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			render_sprites(game, y, x);
	}
	display_text(game);

	return (0);
}
