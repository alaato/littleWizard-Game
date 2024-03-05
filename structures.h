/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:51:31 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 17:20:06 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
	int			y;
	int			x;
}				t_vector;

typedef struct s_tile
{
	char		t;
	int			v;
}				t_tile;

typedef struct s_map
{
	char		*path;
	int		height;
	int		width;
	char		**grid;
	char		**visited;
	int			exit_accessible;
	int			fd;
	int			accessible_collectibles;
	int			players;
	int			exits;
	int			collectibles;
}				t_map;

typedef struct s_obj
{
	void		*img;
	t_vector	size;
	t_vector	pos;
}				t_obj;

typedef struct win
{
	void		*ptr;
	t_vector	size;
}				t_window;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_obj		player;
	t_map		map;
	t_obj		wall;
	t_obj		collectible;
	t_obj		start;
	t_obj		exit;
	t_obj		floor;
	t_obj		player_front;
	t_obj		player_left;
	t_obj		player_right;
	t_obj		player_back;
	t_obj		yw_sp;
	t_obj		*digits_sp;
	int			moves;
	int			collected;
}				t_game;