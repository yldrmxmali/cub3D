/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:20 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:02:21 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"
#include <fcntl.h>
#include <unistd.h>

static void	validate_north_xpm(t_cub3d *cub3d, char *line)
{
	t_config	*config;
	int			fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		config->xpm_files->north = ft_strtrim_start(line + 2, "\t ");
		if (config->xpm_files->north[0] == '\0')
			(ft_putstr_fd(NO_ELEMENT_NULL, 2), free_all(cub3d));
		if (ft_strcmp(config->xpm_files->north
				+ ft_strlen(config->xpm_files->north) - 4, ".xpm") != 0)
			(ft_putstr_fd(NO_ELEMENT_EXTENSION, 2), free_all(cub3d));
		fd = open(config->xpm_files->north, O_RDONLY);
		if (fd == -1)
			(ft_putstr_fd(NO_ELEMENT_OPEN, 2), free_all(cub3d));
		close(fd);
	}
}

static void	validate_south_xpm(t_cub3d *cub3d, char *line)
{
	t_config	*config;
	int			fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		config->xpm_files->south = ft_strtrim_start(line + 2, "\t ");
		if (config->xpm_files->south[0] == '\0')
			(ft_putstr_fd(SO_ELEMENT_EMPTY, 2), free_all(cub3d));
		if (ft_strcmp(config->xpm_files->south
				+ ft_strlen(config->xpm_files->south) - 4, ".xpm") != 0)
			(ft_putstr_fd(SO_ELEMENT_EXTENSION, 2), free_all(cub3d));
		fd = open(config->xpm_files->south, O_RDONLY);
		if (fd == -1)
			(ft_putstr_fd(SO_ELEMENT_OPEN, 2), free_all(cub3d));
		close(fd);
	}
}

static void	validate_west_xpm(t_cub3d *cub3d, char *line)
{
	t_config	*config;
	int			fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		config->xpm_files->west = ft_strtrim_start(line + 2, "\t ");
		if (config->xpm_files->west[0] == '\0')
			(ft_putstr_fd(WE_ELEMENT_NULL, 2), free_all(cub3d));
		if (ft_strcmp(config->xpm_files->west
				+ ft_strlen(config->xpm_files->west) - 4, ".xpm") != 0)
			(ft_putstr_fd(WE_ELEMENT_EXTENSION, 2), free_all(cub3d));
		fd = open(config->xpm_files->west, O_RDONLY);
		if (fd == -1)
			(ft_putstr_fd(WE_ELEMENT_OPEN, 2), free_all(cub3d));
		close(fd);
	}
}

static void	validate_east_xpm(t_cub3d *cub3d, char *line)
{
	t_config	*config;
	int			fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		config->xpm_files->east = ft_strtrim_start(line + 2, "\t ");
		if (config->xpm_files->east[0] == '\0')
			(ft_putstr_fd(EA_ELEMENT_NULL, 2), free_all(cub3d));
		if (ft_strcmp(config->xpm_files->east
				+ ft_strlen(config->xpm_files->east) - 4, ".xpm") != 0)
			(ft_putstr_fd(EA_ELEMENT_EXTENSION, 2), free_all(cub3d));
		fd = open(config->xpm_files->east, O_RDONLY);
		if (fd == -1)
			(ft_putstr_fd(EA_ELEMENT_OPEN, 2), free_all(cub3d));
		close(fd);
	}
}

void	validate_xpm_files(t_cub3d *cub3d, char *line)
{
	validate_north_xpm(cub3d, line);
	validate_south_xpm(cub3d, line);
	validate_west_xpm(cub3d, line);
	validate_east_xpm(cub3d, line);
}
