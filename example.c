#include"structures.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int onDestroy(t_program *mlx){
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
}

int handleInputs(int keysym, t_program *data){

	if(keysym == XK_Escape){
		mlx_destroy_window(data->ptr, data->win);
		data->win = NULL;
	}
}

int	loop(t_program *mlx)
{
	t_player *player;

	player = &mlx->player;
	player->sprite.img = mlx_xpm_file_to_image(mlx->ptr, "/home/alaa/42/so_long/monster.xpm",player->sprite.size.x, player->sprite.size.y);

	mlx_put_image_to_window(mlx->ptr, mlx->win, player->sprite.img, 0, 0);
    return (0);
}
int	main(void)
{
	t_program mlx;

	mlx.ptr = mlx_init();
	if(!mlx.ptr) return 1;
	mlx.win = mlx_new_window(mlx.ptr, 1280, 720, "so_long!");
	if(!mlx.win) return 1;



    mlx_loop_hook(mlx.ptr, &loop, &mlx);
	mlx_hook(mlx.win, KeyPress ,KeyPressMask, &handleInputs, &mlx);
	mlx_hook(mlx.win, DestroyNotify ,DestroyNotify, &onDestroy, &mlx);
	mlx_loop(mlx.ptr);


	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
}