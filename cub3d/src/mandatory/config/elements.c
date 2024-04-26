/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:26 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:49:46 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	check_unknown_element_type(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0
			&& ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0
			&& ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
			(ft_putstr_fd(ELEMENT_TYPES, 2), free_all(cub3d));
		i++;
	}
}

static void	check_multiple_element_type(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (config->xpm_files->north_count > 1)
		(ft_putstr_fd(NO_ELEMENT, 2), free_all(cub3d));
	if (config->xpm_files->south_count > 1)
		(ft_putstr_fd(SO_ELEMENT, 2), free_all(cub3d));
	if (config->xpm_files->west_count > 1)
		(ft_putstr_fd(WE_ELEMENT, 2), free_all(cub3d));
	if (config->xpm_files->east_count > 1)
		(ft_putstr_fd(EA_ELEMENT, 2), free_all(cub3d));
	if (config->floor_color->count > 1)
		(ft_putstr_fd(F_ELEMENT, 2), free_all(cub3d));
	if (config->ceiling_color->count > 1)
		(ft_putstr_fd(C_ELEMENT, 2), free_all(cub3d));
}

static void	validate_different_xpm_files(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (ft_strcmp(config->xpm_files->north, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->east) == 0)
		(ft_putstr_fd(NO_TEXTURE, 2), free_all(cub3d));
	if (ft_strcmp(config->xpm_files->south, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->east) == 0)
		(ft_putstr_fd(SO_TEXTURE, 2), free_all(cub3d));
	if (ft_strcmp(config->xpm_files->west, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->east) == 0)
		(ft_putstr_fd(WE_TEXTURE, 2), free_all(cub3d));
	if (ft_strcmp(config->xpm_files->east, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->west) == 0)
		(ft_putstr_fd(EA_TEXTURE, 2), free_all(cub3d));
}

static void	validate_different_color(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (config->floor_color->red == config->ceiling_color->red
		&& config->floor_color->green == config->ceiling_color->green
		&& config->floor_color->blue == config->ceiling_color->blue)
		(ft_putstr_fd(F_AND_C_SAME, 2), free_all(cub3d));
}

void	verify_elements(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	set_elements_count(cub3d);
	check_unknown_element_type(cub3d);
	check_multiple_element_type(cub3d);
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		validate_xpm_files(cub3d, line);
		validate_floor_color(cub3d, line);
		validate_ceiling_color(cub3d, line);
		i++;
	}
	validate_different_xpm_files(cub3d);
	validate_different_color(cub3d);
}
