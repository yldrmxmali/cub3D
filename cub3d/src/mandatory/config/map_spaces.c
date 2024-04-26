/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:40 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:06:28 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	error_and_free(t_cub3d *cub3d, char **line)
{
	free(line);
	ft_putstr_fd(MAP_WALL, 2);
	free_all(cub3d);
}

static int	valid_char(char chr)
{
	if (chr == '1' || chr == ' ' || chr == '\0')
	{
		return (1);
	}
	return (0);
}

static void	validate_row_spaces(t_cub3d *cub3d, char **map, int last_row_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (row == 0 && !valid_char(map[row + 1][col]))
					error_and_free(cub3d, map);
				if (row == last_row_index && !valid_char(map[row - 1][col]))
					error_and_free(cub3d, map);
				if (row > 0 && row < last_row_index
					&& (!valid_char(map[row - 1][col])
					|| !valid_char(map[row + 1][col])))
					error_and_free(cub3d, map);
			}
			col++;
		}
		row++;
	}
}

static void	validate_col_spaces(t_cub3d *cub3d, char **map, int last_col_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (col == 0 && !valid_char(map[row][col + 1]))
					error_and_free(cub3d, map);
				if (col == last_col_index && !valid_char(map[row][col - 1]))
					error_and_free(cub3d, map);
				if (col > 0 && col < last_col_index
					&& (!valid_char(map[row][col - 1])
					|| !valid_char(map[row][col + 1])))
					error_and_free(cub3d, map);
			}
			col++;
		}
		row++;
	}
}

void	verify_map_spaces(t_cub3d *cub3d)
{
	char	**map;
	int		last_row_index;
	int		last_col_index;

	map = create_map_same_row_len(cub3d);
	last_row_index = cub3d->config->map->row_count - 1;
	last_col_index = cub3d->config->map->col_count - 1;
	validate_row_spaces(cub3d, map, last_row_index);
	validate_col_spaces(cub3d, map, last_col_index);
	ft_no_malloc(map);
}
