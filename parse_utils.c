/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:50:41 by alaa              #+#    #+#             */
/*   Updated: 2024/03/04 23:53:18 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	is_rect(t_game *game)
{
	char	*line;
	int		fd;

	fd = open(game->map.path, O_RDONLY);
	if (fd == -1)
		return (error_message("couldnt open", game));
	line = get_next_line(fd);
	if (!line)
		return (error_message("Empty file", game));
	game->map.width = ft_line_len(line);
	game->map.height = 0;
	while (line != NULL)
	{
		game->map.height++;
		if (ft_line_len(line) != game->map.width)
		{
			free(line);
			return (error_message("map is not rect", game));
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

void	print_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.height)
		printf("%s", game->map.grid[i]);
}

int	row_is_not_wall(char *toCheck, t_game *game)
{
	int	i;
	char c;

	i = -1;
	if (!toCheck)
		return (1);
	while (toCheck[++i])
	{
		c = toCheck[i];
		if (c != WALL)
			return (error_message("it aint enclosed by walls, sunny", game));
	}
	return (0);
}

int	col_is_not_wall(t_game *game)
{
	int	i;
	char c;
	
	i = -1;
	while (++i < game->map.height)
	{
		c = game->map.grid[i][game->map.width - 1];
		if (c != WALL)
			return (error_message("it aint enclosed by walls, sunny", game));
	}
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.height)
	{
		free(game->map.grid[i]);
		free(game->map.visited[i]);
	}
	free(game->map.grid);
	free(game->map.visited);
}
