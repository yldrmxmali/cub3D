/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:32 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 01:55:04 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"
#include <fcntl.h>
#include <unistd.h>

void	set_config_text(t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd(MAP_OPEN, 2), free_all(cub3d));
	cub3d->config->text = malloc(
			sizeof(char *) * (cub3d->config->full_line_count + 1));
	if (cub3d->config->text == NULL)
		(ft_putstr_fd(CONFIG_TEXT, 2), free_all(cub3d));
	cub3d->config->text[cub3d->config->full_line_count] = NULL;
	i = 0;
	while (i < cub3d->config->full_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (!is_empty_line(line))
		{
			cub3d->config->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}

void	verify_config(t_cub3d *cub3d)
{
	char	character;
	int		readed_byte;
	int		fd;

	character = '\0';
	readed_byte = 0;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd(MAP_OPEN, 2), free_all(cub3d));
	readed_byte = read(fd, &character, 1);
	close(fd);
	if (readed_byte == -1)
		(ft_putstr_fd(MAP_READ, 2), free_all(cub3d));
	if (readed_byte == 0)
		(ft_putstr_fd(MAP_EMPTY, 2), free_all(cub3d));
}

void	map_control(t_cub3d *cub3d)
{
	char	*filename;

	filename = cub3d->config->filename;
	if (cub3d->config->arg_count == 1)
		(ft_putstr_fd(MAP_COUNT_1, 2), free_all(cub3d));
	if (cub3d->config->arg_count > 2)
		(ft_putstr_fd(MAP_COUNT_GREATER_2, 2), free_all(cub3d));
	if (filename == NULL || *filename == '\0')
		(ft_putstr_fd(MAP_NULL, 2), free_all(cub3d));
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		(ft_putstr_fd(MAP_EXTENSION, 2), free_all(cub3d));
}

void	set_elements_count(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		if (ft_strncmp("NO", line, 2) == 0)
			cub3d->config->xpm_files->north_count++;
		if (ft_strncmp("SO", line, 2) == 0)
			cub3d->config->xpm_files->south_count++;
		if (ft_strncmp("WE", line, 2) == 0)
			cub3d->config->xpm_files->west_count++;
		if (ft_strncmp("EA", line, 2) == 0)
			cub3d->config->xpm_files->east_count++;
		if (ft_strncmp("F", line, 1) == 0)
			cub3d->config->floor_color->count++;
		if (ft_strncmp("C", line, 1) == 0)
			cub3d->config->ceiling_color->count++;
		i++;
	}
}
