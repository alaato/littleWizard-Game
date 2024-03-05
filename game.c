/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:59:02 by alaa              #+#    #+#             */
/*   Updated: 2024/03/03 18:10:28 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_obj ft_new_sprite(void *mlx, char *path)
{
	t_obj obj;
	
	obj.img = mlx_xpm_file_to_image(mlx, path, &obj.x, &obj.y);
	return (obj);
}

int	ft_input(int key, t_game *game)
{
	if (key == XK_d)
		game->player.pos.x += game->player.sprite.x;
	else if (key == XK_a)
		game->player.pos.x -= game->player.sprite.x;
	else if (key == XK_w)
		game->player.pos.y += game->player.sprite.y;
	else if (key == XK_s)
		game->player.pos.y -= game->player.sprite.y;
	if(key == XK_Escape)
		mlx_loop_end(mlx->mlx);
	mlx_do_sync(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->player.sprite.img, mlx->player.pos.x, mlx->player.pos.y);
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	loop(t_game *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->player.sprite.img, mlx->player.pos.x, mlx->player.pos.y);
	mlx_do_sync(mlx->mlx);
	return (0);
}
void init_sprites(t_game *game){
	game->player.sprite = ft_new_sprite(game->mlx, "./images/monster.xpm");
	game->player.pos.x = 0;
	game->player.pos.y = 0;
}
int	main()
{
	t_game mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (ERROR);
	mlx.win = mlx_new_window(mlx.mlx, 1280, 720, "so_long!");
	if (!mlx.win)
		return (ERROR);


	mlx_hook(mlx.win, KeyPress, KeyPressMask, &ft_input, &mlx);
	mlx_loop_hook(mlx.mlx, &loop, &mlx);
	mlx_loop(mlx.mlx);

	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}