/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:03 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:06:04 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	free_config(t_cub3d *cub3d)
{
	if (cub3d->config == NULL)
		return ;
	free_map(cub3d);
	free_colors(cub3d);
	free_xpm_files(cub3d);
	ft_no_malloc(cub3d->config->text);
	free(cub3d->config);
}

void	free_map(t_cub3d *cub3d)
{
	if (cub3d->config->map == NULL)
		return ;
	ft_no_malloc(cub3d->config->map->text);
	free(cub3d->config->map);
}

void	free_colors(t_cub3d *cub3d)
{
	if (cub3d->config->floor_color != NULL)
	{
		if (cub3d->config->floor_color->string != NULL)
			free(cub3d->config->floor_color->string);
		if (cub3d->config->floor_color->red_string != NULL)
			free(cub3d->config->floor_color->red_string);
		if (cub3d->config->floor_color->green_string != NULL)
			free(cub3d->config->floor_color->green_string);
		if (cub3d->config->floor_color->blue_string != NULL)
			free(cub3d->config->floor_color->blue_string);
		free(cub3d->config->floor_color);
	}
	if (cub3d->config->ceiling_color != NULL)
	{
		if (cub3d->config->ceiling_color->string != NULL)
			free(cub3d->config->ceiling_color->string);
		if (cub3d->config->ceiling_color->red_string != NULL)
			free(cub3d->config->ceiling_color->red_string);
		if (cub3d->config->ceiling_color->green_string != NULL)
			free(cub3d->config->ceiling_color->green_string);
		if (cub3d->config->ceiling_color->blue_string != NULL)
			free(cub3d->config->ceiling_color->blue_string);
		free(cub3d->config->ceiling_color);
	}
}

void	free_xpm_files(t_cub3d *cub3d)
{
	if (cub3d->config->xpm_files == NULL)
		return ;
	if (cub3d->config->xpm_files->north != NULL)
		free(cub3d->config->xpm_files->north);
	if (cub3d->config->xpm_files->south != NULL)
		free(cub3d->config->xpm_files->south);
	if (cub3d->config->xpm_files->west != NULL)
		free(cub3d->config->xpm_files->west);
	if (cub3d->config->xpm_files->east != NULL)
		free(cub3d->config->xpm_files->east);
	free(cub3d->config->xpm_files);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d == NULL)
		return ;
	free_config(cub3d);
	free_game(cub3d);
	free(cub3d);
}
