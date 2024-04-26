/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:55 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:04:26 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	init_ceiling_rgb(t_cub3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->config->ceiling_color->red;
	green = cub3d->config->ceiling_color->green;
	blue = cub3d->config->ceiling_color->blue;
	cub3d->game->ceiling_rgb = (red << 16 | green << 8 | blue);
}

void	init_floor_rgb(t_cub3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->config->floor_color->red;
	green = cub3d->config->floor_color->green;
	blue = cub3d->config->floor_color->blue;
	cub3d->game->floor_rgb = (red << 16 | green << 8 | blue);
}

static void	init_keys(t_cub3d *cub3d)
{
	cub3d->game->keys.w = 0;
	cub3d->game->keys.s = 0;
	cub3d->game->keys.a = 0;
	cub3d->game->keys.d = 0;
	cub3d->game->keys.left = 0;
	cub3d->game->keys.right = 0;
	cub3d->game->keys.up_speed = 0;
	cub3d->game->keys.down_speed = 0;
}

void	init_game(t_cub3d *cub3d)
{
	cub3d->game = malloc(sizeof(t_game));
	if (cub3d->game == NULL)
		(ft_putstr_fd(GAME_MALLOC, 2), free_all(cub3d));
	cub3d->game->mlx = NULL;
	cub3d->game->window = NULL;
	cub3d->game->screen = NULL;
	cub3d->game->player = NULL;
	cub3d->game->ceiling_rgb = 0;
	cub3d->game->floor_rgb = 0;
	cub3d->game->north_image = NULL;
	cub3d->game->south_image = NULL;
	cub3d->game->west_image = NULL;
	cub3d->game->east_image = NULL;
	init_mlx(cub3d);
	init_screen(cub3d);
	init_north_mlx_image(cub3d);
	init_south_mlx_image(cub3d);
	init_west_mlx_image(cub3d);
	init_east_mlx_image(cub3d);
	init_ceiling_rgb(cub3d);
	init_floor_rgb(cub3d);
	init_player(cub3d);
	init_keys(cub3d);
}

void	free_game(t_cub3d *cub3d)
{
	if (cub3d->game == NULL)
		return ;
	free_player(cub3d);
	free_xpm_images(cub3d);
	free_screen(cub3d);
	free_mlx(cub3d);
	free(cub3d->game);
}
