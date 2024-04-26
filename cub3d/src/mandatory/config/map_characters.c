/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:36 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:49:06 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static int	character_is_valid(char chr)
{
	if (chr != '0' && chr != '1'
		&& chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E'
		&& chr != ' ')
	{
		return (SUCCESS);
	}
	return (ERROR);
}

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (SUCCESS);
	}
	return (ERROR);
}

static void	validate_player_position(t_cub3d *cub3d)
{
	t_map	*map;

	map = cub3d->config->map;
	if (map->player_count < 1)
		(ft_putstr_fd(MAP_PLYR_LESS_1, 2), free_all(cub3d));
	if (map->player_count > 1)
		(ft_putstr_fd(MAP_PLYR_MORE_1, 2), free_all(cub3d));
	if (map->player_row == 0)
		(ft_putstr_fd(MAP_PLYR_FIRST, 2), free_all(cub3d));
	if (map->player_row == map->row_count - 1)
		(ft_putstr_fd(MAP_PLYR_LAST, 2), free_all(cub3d));
	if (map->player_col == 0)
		(ft_putstr_fd(MAP_PLYR_FIRST_COL, 2), free_all(cub3d));
	if (map->player_col == map->col_count - 1)
		(ft_putstr_fd(MAP_PLYR_LAST_COL, 2), free_all(cub3d));
}

void	verify_map_characters(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (!character_is_valid(map->text[row][col]))
				(ft_putstr_fd(MAP_CHAR, 2), free_all(cub3d));
			if (!character_is_player(map->text[row][col]))
			{
				map->player_count++;
				map->player_row = row;
				map->player_col = col;
			}
			col++;
		}
		row++;
	}
	validate_player_position(cub3d);
}
