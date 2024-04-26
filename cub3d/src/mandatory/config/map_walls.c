/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:45 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:06:39 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	error_and_free(t_cub3d *cub3d, char *line)
{
	free(line);
	ft_putstr_fd(MAP_WALL, 2);
	free_all(cub3d);
}

static void	verify_map_border(t_cub3d *cub3d)
{
	char	*line;
	int		last_row_index;
	int		last_col_index;
	int		row;
	int		col;

	last_row_index = cub3d->config->map->row_count - 1;
	row = 0;
	while (cub3d->config->map->text[row] != NULL)
	{
		line = ft_strtrim(cub3d->config->map->text[row], " ");
		last_col_index = ft_strlen(line) - 1;
		col = 0;
		while (line[col] != '\0')
		{
			if ((row == 0 || row == last_row_index) && line[col] == '0')
				error_and_free(cub3d, line);
			else if (line[0] == '0' || line[last_col_index] == '0')
				error_and_free(cub3d, line);
			col++;
		}
		free(line);
		row++;
	}
}

static void	dfs_algorithm(t_cub3d *cub3d, char **map, int row, int col)
{
	if (row < 0 || row >= cub3d->config->map->row_count
		|| col < 0 || col >= cub3d->config->map->col_count)
	{
		ft_no_malloc(map);
		(ft_putstr_fd(MAP_WALL, 2), free_all(cub3d));
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return ;
	map[row][col] = '.';
	dfs_algorithm(cub3d, map, row, col + 1);
	dfs_algorithm(cub3d, map, row, col - 1);
	dfs_algorithm(cub3d, map, row + 1, col);
	dfs_algorithm(cub3d, map, row - 1, col);
}

static void	get_player_position(t_cub3d *cub3d, int *row, int *col)
{
	char	chr;
	int		r;
	int		c;

	chr = '\0';
	r = 0;
	while (cub3d->config->map->text[r] != NULL)
	{
		c = 0;
		while (cub3d->config->map->text[r][c] != '\0')
		{
			chr = cub3d->config->map->text[r][c];
			if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
			{
				*row = r;
				*col = c;
				return ;
			}
			c++;
		}
		r++;
	}
}

void	verify_map_walls(t_cub3d *cub3d)
{
	char	**map;
	int		player_row;
	int		player_col;

	map = create_map_same_row_len(cub3d);
	get_player_position(cub3d, &player_row, &player_col);
	dfs_algorithm(cub3d, map, player_row, player_col);
	ft_no_malloc(map);
	verify_map_border(cub3d);
}
