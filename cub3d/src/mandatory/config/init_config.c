/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:15:56 by beeren            #+#    #+#             */
/*   Updated: 2024/03/19 23:20:34 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

int	init_config(t_cub3d *cub3d, int arg_count, char *filename)
{
	cub3d->game = NULL;
	cub3d->config = malloc(sizeof(t_config));
	if (cub3d->config == NULL)
		return (free(cub3d), ERROR);
	cub3d->config->arg_count = arg_count;
	cub3d->config->filename = filename;
	cub3d->config->text = NULL;
	cub3d->config->xpm_files = NULL;
	cub3d->config->floor_color = NULL;
	cub3d->config->ceiling_color = NULL;
	cub3d->config->map = NULL;
	cub3d->config->total_line_count = 0;
	cub3d->config->full_line_count = 0;
	cub3d->config->empty_line_count = 0;
	return (SUCCESS);
}

int	init_xpm_files(t_cub3d *cub3d)
{
	cub3d->config->xpm_files = malloc(sizeof(t_xpm_files));
	if (cub3d->config->xpm_files == NULL)
		return (ERROR);
	cub3d->config->xpm_files->north = NULL;
	cub3d->config->xpm_files->south = NULL;
	cub3d->config->xpm_files->west = NULL;
	cub3d->config->xpm_files->east = NULL;
	cub3d->config->xpm_files->north_count = 0;
	cub3d->config->xpm_files->south_count = 0;
	cub3d->config->xpm_files->west_count = 0;
	cub3d->config->xpm_files->east_count = 0;
	cub3d->gear_count = 0;
	cub3d->gear_flag = 0;
	return (SUCCESS);
}

int	init_colors(t_cub3d *cub3d)
{
	cub3d->config->floor_color = malloc(sizeof(t_color));
	if (cub3d->config->floor_color == NULL)
		return (ERROR);
	cub3d->config->floor_color->red = -1;
	cub3d->config->floor_color->green = -1;
	cub3d->config->floor_color->blue = -1;
	cub3d->config->floor_color->count = 0;
	cub3d->config->floor_color->string = NULL;
	cub3d->config->floor_color->red_string = NULL;
	cub3d->config->floor_color->green_string = NULL;
	cub3d->config->floor_color->blue_string = NULL;
	cub3d->config->ceiling_color = malloc(sizeof(t_color));
	if (cub3d->config->ceiling_color == NULL)
		return (ERROR);
	cub3d->config->ceiling_color->red = -1;
	cub3d->config->ceiling_color->green = -1;
	cub3d->config->ceiling_color->blue = -1;
	cub3d->config->ceiling_color->count = 0;
	cub3d->config->ceiling_color->string = NULL;
	cub3d->config->ceiling_color->red_string = NULL;
	cub3d->config->ceiling_color->green_string = NULL;
	cub3d->config->ceiling_color->blue_string = NULL;
	return (SUCCESS);
}

int	init_map(t_cub3d *cub3d)
{
	cub3d->config->map = malloc(sizeof(t_map));
	if (cub3d->config->map == NULL)
		return (ERROR);
	cub3d->config->map->text = NULL;
	cub3d->config->map->starting_line = 0;
	cub3d->config->map->row_count = 0;
	cub3d->config->map->col_count = 0;
	cub3d->config->map->player_count = 0;
	cub3d->config->map->player_row = 0;
	cub3d->config->map->player_col = 0;
	return (SUCCESS);
}

t_cub3d	*init_cub3d(int arg_count, char *filename)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		(ft_putstr_fd(MALLOC_ERR, 2), exit(ERROR));
	if (init_config(cub3d, arg_count, filename) != SUCCESS)
		(ft_putstr_fd(CONFIG_MALLOC_ERR, 2), free_all(cub3d));
	if (init_xpm_files(cub3d) != SUCCESS)
		(ft_putstr_fd(XPM_MALLOC_ERR, 2), free_all(cub3d));
	if (init_colors(cub3d) != SUCCESS)
		(ft_putstr_fd(COLOR_MALLOC_ERR, 2), free_all(cub3d));
	if (init_map(cub3d) != SUCCESS)
		(ft_putstr_fd(MAP_MALLOC_ERR, 2), free_all(cub3d));
	return (cub3d);
}
