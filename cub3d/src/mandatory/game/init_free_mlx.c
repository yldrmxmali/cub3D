/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:00 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:43:51 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"
#include "../../../mlx/mlx.h"

void	init_screen(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	game->screen = malloc(sizeof(t_mlx_image));
	if (game->screen == NULL)
		(ft_putstr_fd(GAME_SCREEN_MALLOC, 2), free_all(cub3d));
	game->screen->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->screen->img == NULL)
		(ft_putstr_fd(GAME_SC_IMG, 2), free_all(cub3d));
	game->screen->addr = mlx_get_data_addr(game->screen->img,
			&game->screen->bits_per_pixel,
			&game->screen->size_line,
			&game->screen->endian);
	if (game->screen->addr == NULL)
		(ft_putstr_fd(GAME_SC_ADDR, 2), free_all(cub3d));
}

void	free_screen(t_cub3d *cub3d)
{
	if (cub3d->game->screen == NULL)
		return ;
	if (cub3d->game->screen->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->screen->img);
	free(cub3d->game->screen);
}

void	init_mlx(t_cub3d *cub3d)
{
	int	w;
	int	h;

	w = SCREEN_WIDTH;
	h = SCREEN_HEIGHT;
	cub3d->game->mlx = mlx_init();
	if (cub3d->game->mlx == NULL)
		(ft_putstr_fd(MLX_MALLOC, 2), free_all(cub3d));
	cub3d->game->window = mlx_new_window(cub3d->game->mlx,
			w, h, "Finish if you can!");
	if (cub3d->game->window == NULL)
		(ft_putstr_fd(MLX_WIN_MALLOC, 2), free_all(cub3d));
}

void	free_mlx(t_cub3d *cub3d)
{
	if (cub3d->game->mlx == NULL)
		return ;
	if (cub3d->game->window != NULL)
		mlx_destroy_window(cub3d->game->mlx, cub3d->game->window);
}
