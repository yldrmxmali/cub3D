/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:49 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 03:14:33 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include "../../utilities/utilities.h"
#include <unistd.h>

void	check_map_empty_line(t_cub3d *cub3d)
{
	t_config	*config;
	char		*line;
	int			i;
	int			fd;

	config = cub3d->config;
	fd = open(config->filename, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd(MAP_OPEN, 2), free_all(cub3d));
	line = NULL;
	i = 1;
	while (i <= config->total_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (is_empty_line(line) && i > config->map->starting_line)
		{
			free(line);
			(ft_putstr_fd(MAP_EMPTY_LINE, 2), free_all(cub3d));
		}
		free(line);
		i++;
	}
	close(fd);
}

void	set_map_text(t_cub3d *cub3d)
{
	t_config	*config;
	int			map_index;
	int			col_count;
	int			i;

	config = cub3d->config;
	map_index = 6;
	config->map->row_count = config->full_line_count - map_index;
	config->map->text = malloc(sizeof(char *) * (config->map->row_count + 1));
	if (config->map->text == NULL)
		(ft_putstr_fd(CONFIG_MAP, 2), free_all(cub3d));
	col_count = 0;
	i = 0;
	while (config->text[map_index] != NULL)
	{
		config->map->text[i] = ft_strdup(config->text[map_index]);
		col_count = ft_strlen(config->text[map_index]);
		if (col_count > config->map->col_count)
			config->map->col_count = col_count;
		i++;
		map_index++;
	}
	config->map->text[i] = NULL;
}

void	verify_map(t_cub3d *cub3d)
{
	set_map_text(cub3d);
	check_map_empty_line(cub3d);
	verify_map_characters(cub3d);
	verify_map_walls(cub3d);
	verify_map_spaces(cub3d);
}
