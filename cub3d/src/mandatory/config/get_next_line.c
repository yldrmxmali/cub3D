/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:19:42 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:05:39 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"
#include <fcntl.h>
#include <unistd.h>

static void	clear_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
}

static void	handle_line(t_config *config, char *line, int readed_byte, int *i)
{
	if (line[*i] == '\n' || readed_byte == 0)
	{
		config->total_line_count++;
		line[*i + 1] = '\0';
		if (is_empty_line(line) != ERROR)
		{
			config->full_line_count++;
			if (config->full_line_count == 7)
				config->map->starting_line = config->total_line_count;
		}
		else
			config->empty_line_count++;
		clear_line(line);
		*i = -1;
	}
}

void	set_config_line_count(t_cub3d *cub3d, int i)
{
	char	line[1024];
	char	character;
	int		readed_byte;
	int		fd;

	character = '\0';
	readed_byte = 1;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd(MAP_OPEN, 2), free_all(cub3d));
	while (readed_byte > 0)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
		{
			close (fd);
			(ft_putstr_fd(MAP_READ, 2), free_all(cub3d));
		}
		line[i] = character;
		handle_line(cub3d->config, line, readed_byte, &i);
		i++;
	}
	close(fd);
	if (cub3d->config->full_line_count < 9)
		(ft_putstr_fd(CONFIG_LINE, 2), free_all(cub3d));
}

char	*get_next_line(t_cub3d *cub3d, int fd)
{
	char	*line;
	char	character;
	int		readed_byte;
	int		i;

	line = malloc(1024);
	character = '\0';
	readed_byte = 1;
	i = 0;
	if (fd == -1)
		(ft_putstr_fd(MAP_OPEN, 2), free_all(cub3d));
	while (1)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			(ft_putstr_fd(MAP_READ, 2), free_all(cub3d));
		line[i] = character;
		if (character == '\n' || readed_byte == 0)
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}
