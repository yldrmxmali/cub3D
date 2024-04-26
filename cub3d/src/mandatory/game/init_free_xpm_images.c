/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_xpm_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:11 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:48:38 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx/mlx.h"
#include "../../utilities/utilities.h"
#include "../cub3d.h"

void	init_north_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->north_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->north_image == NULL)
		(ft_putstr_fd(NO_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->north_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->north, &size, &size);
	if (cub3d->game->north_image->img == NULL)
		(ft_putstr_fd(NO_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->north_image->addr = mlx_get_data_addr
		(cub3d->game->north_image->img,
			&cub3d->game->north_image->bits_per_pixel,
			&cub3d->game->north_image->size_line,
			&cub3d->game->north_image->endian);
	if (cub3d->game->north_image->addr == NULL)
		(ft_putstr_fd(NO_IMG_ADDR, 2), free_all(cub3d));
}

void	init_south_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->south_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->south_image == NULL)
		(ft_putstr_fd(SO_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->south_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->south, &size, &size);
	if (cub3d->game->south_image->img == NULL)
		(ft_putstr_fd(SO_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->south_image->addr = mlx_get_data_addr
		(cub3d->game->south_image->img,
			&cub3d->game->south_image->bits_per_pixel,
			&cub3d->game->south_image->size_line,
			&cub3d->game->south_image->endian);
	if (cub3d->game->south_image->addr == NULL)
		(ft_putstr_fd(SO_IMG_ADDR, 2), free_all(cub3d));
}

void	init_west_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->west_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->west_image == NULL)
		(ft_putstr_fd(WE_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->west_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->west, &size, &size);
	if (cub3d->game->west_image->img == NULL)
		(ft_putstr_fd(WE_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->west_image->addr = mlx_get_data_addr
		(cub3d->game->west_image->img,
			&cub3d->game->west_image->bits_per_pixel,
			&cub3d->game->west_image->size_line,
			&cub3d->game->west_image->endian);
	if (cub3d->game->west_image->addr == NULL)
		(ft_putstr_fd(WE_IMG_ADDR, 2), free_all(cub3d));
}

void	init_east_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->east_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->east_image == NULL)
		(ft_putstr_fd(EA_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->east_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->east, &size, &size);
	if (cub3d->game->east_image->img == NULL)
		(ft_putstr_fd(EA_IMG_MALLOC, 2), free_all(cub3d));
	cub3d->game->east_image->addr = mlx_get_data_addr
		(cub3d->game->east_image->img,
			&cub3d->game->east_image->bits_per_pixel,
			&cub3d->game->east_image->size_line,
			&cub3d->game->east_image->endian);
	if (cub3d->game->east_image->addr == NULL)
		(ft_putstr_fd(EA_IMG_ADDR, 2), free_all(cub3d));
}

void	free_xpm_images(t_cub3d *cub3d)
{
	if (cub3d->game->north_image != NULL)
	{
		if (cub3d->game->north_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->north_image->img);
		free(cub3d->game->north_image);
	}
	if (cub3d->game->south_image != NULL)
	{
		if (cub3d->game->south_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->south_image->img);
		free(cub3d->game->south_image);
	}
	if (cub3d->game->west_image != NULL)
	{
		if (cub3d->game->west_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->west_image->img);
		free(cub3d->game->west_image);
	}
	if (cub3d->game->east_image != NULL)
	{
		if (cub3d->game->east_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->east_image->img);
		free(cub3d->game->east_image);
	}
}
