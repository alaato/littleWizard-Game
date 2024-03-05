/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:33 by alaa              #+#    #+#             */
/*   Updated: 2024/03/04 23:56:31 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	fill_map(t_game *game)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;
	int		i;

	i = -1;
	map_fd = open(game->map.path, O_RDONLY);
	if (map_fd == -1)
		error_message("couldn't be opened. check it exists", game);
	map_temp = ft_strdup("");
	game->map.visited = malloc(game->map.height * sizeof(char *));
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.visited[++i] = calloc(game->map.width, 1);
	}
	close(map_fd);
	game->map.grid = ft_split(map_temp, '\n');
	free(map_temp);
	return (0);
}

int	is_not_enclosed_by_wall(t_game *game)
{
	int	len;

	len = game->map.height;
	if (row_is_not_wall(game->map.grid[0], game) || row_is_not_wall(game->map.grid[len - 1], game)
		|| col_is_not_wall(game) || col_is_not_wall(game))
		return (1);
	return (0);
}

int	is_content_not_valid(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (game->map.grid[i][++j])
		{
			if (game->map.grid[i][j] == PLAYER)
			{
				game->map.players++;
				game->player.pos = (t_vector){i, j};
			}
			else if (game->map.grid[i][j] == COLLECT)
				game->map.collectibles++;
			else if (game->map.grid[i][j] == EXIT)
				game->map.exits++;
			else if (game->map.grid[i][j] != WALL
				&& game->map.grid[i][j] != FLOOR
				&& game->map.grid[i][j] != '\n')
				return (error_message("Unkown content", game));
		}
	}
	return (0);
}

void	path_not_valid(t_map *map, t_vector point)
{
	if (point.y >= map->height || point.x >= map->width)
		return ;
	if (map->grid[point.y][point.x] == WALL
		|| map->visited[point.y][point.x] == 'y')
		return ;
	if (map->grid[point.y][point.x] == EXIT)
	{
		map->exit_accessible = 1;
		return ;
	}
	if (map->grid[point.y][point.x] == COLLECT)
		map->accessible_collectibles++;
	map->visited[point.y][point.x] = 'y';
	path_not_valid(map, (t_vector){point.y - 1, point.x});
	path_not_valid(map, (t_vector){point.y + 1, point.x});
	path_not_valid(map, (t_vector){point.y, point.x - 1});
	path_not_valid(map, (t_vector){point.y, point.x + 1});
	return ;
}

int	parse_map(t_game *game)
{
	if (is_rect(game) == ERROR)
		return (ERROR);
	if (fill_map(game) == ERROR)
		return (ERROR);
	if (is_not_enclosed_by_wall(game))
		return (ERROR);
	if (is_content_not_valid(game))
		return (ERROR);
	if (game->map.collectibles < 1 || game->map.exits != 1
		|| game->map.players != 1)
		return (error_message("only 1 player 1 exit and collectibles allowed", game));
	path_not_valid(&(game->map), game->player.pos);
	if (game->map.exit_accessible != 1
		|| game->map.accessible_collectibles != game->map.collectibles)
		return (error_message("Invalid path to the exit or collectibles", game));
	return (SUCCSES);
}
