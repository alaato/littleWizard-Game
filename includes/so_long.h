/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:15:40 by saeby             #+#    #+#             */
/*   Updated: 2024/03/05 18:03:52 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 500
# define WIN_H 500
# define WIN_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT 'C'
# ifndef SIZE
#  define SIZE 50
# endif
# define BOOL short int
# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCSES 0
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../structures.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// parse
int		fill_map(t_game *game);
int		is_not_enclosed_by_wall(t_game *game);
int		is_content_not_valid(t_game *game);
void	path_not_valid(t_map *map, t_vector point);
int		parse_map(t_game *game);
// parse_utils
int		is_rect(t_game *game);
void	print_map(t_game *game);
int		row_is_not_wall(char *toCheck, t_game *game);
int		col_is_not_wall(t_game *game);
void	free_map(t_game *game);
void	free_map(t_game *game);
char	*ft_strappend(char **s1, const char *s2);

// utils
int		ft_line_len(char *line);
// render.c
void	render_sprites(t_game *game, int y, int x);
void	render_obj(t_game *game, t_obj obj, int y, int x);
int		ft_render_map(t_game *game);
t_obj	ft_new_sprite(void *mlx, char *path, t_game *game);
// end.c
void	display_result(t_game *game);
void	close_game(t_game *game);
// movement.c
void	player_dir(t_game *game, int direction);
void	move_player(t_game *game, int direction, int y, int x);
int		ft_input(int key, t_game *game);
// free.c
void	free_images(t_game *game);
int		free_game(t_game *game);
// error.c
int		error_message(char *from, t_game *game);
#endif