/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:17 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:43:51 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../../mlx/mlx.h"

int	destroy_handler(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keydown_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
		destroy_handler(cub3d);
	if (key == KEY_W)
		keydown_handler_w(key, cub3d);
	else if (key == KEY_S)
		cub3d->game->keys.s = 1;
	else if (key == KEY_A)
		cub3d->game->keys.a = 1;
	else if (key == KEY_D)
		cub3d->game->keys.d = 1;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 1;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 1;
	else if (key == KEY_UP)
		keydown_handler_up(key, cub3d);
	else if (key == KEY_DOWN)
		key_down_handler_down(key, cub3d);
	return (0);
}

int	keyup_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
	{
		cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx,
				"textures/car_0.xpm", &cub3d->tmp_x, &cub3d->tmp_y);
		cub3d->game->keys.w = 0;
	}
	else if (key == KEY_S)
		cub3d->game->keys.s = 0;
	else if (key == KEY_A)
		cub3d->game->keys.a = 0;
	else if (key == KEY_D)
		cub3d->game->keys.d = 0;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 0;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 0;
	else if (key == KEY_UP)
		cub3d->game->keys.up_speed = 0;
	else if (key == KEY_DOWN)
		cub3d->game->keys.down_speed = 0;
	return (0);
}

size_t	get_image_color(t_mlx_image *image, int x, int y)
{
	return (*(size_t *)((image->addr
			+ (y * image->size_line) + (x * image->bits_per_pixel / 8))));
}

void	put_pixel_to_mlx_image(t_mlx_image *image, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > SCREEN_HEIGHT)
		return ;
	if (x < 0 || x > SCREEN_WIDTH)
		return ;
	if (image->addr == NULL)
		return ;
	dst = image->addr
		+ (y * image->size_line + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
