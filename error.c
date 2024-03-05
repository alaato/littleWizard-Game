/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:51:42 by alaa              #+#    #+#             */
/*   Updated: 2024/03/05 16:23:33 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	error_message(char *from, t_game *game)
{
	printf("Error\n");
	printf("type: %s\n", from);
	if (game->map.grid)
		free_map(game);
	return (1);
}
