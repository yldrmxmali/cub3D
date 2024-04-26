/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 06:52:45 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:46:28 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx/mlx.h"
#include "../cub3d.h"

void	keydown_handler_up(int key, t_cub3d *cub3d)
{
	if (key == KEY_UP)
	{
		cub3d->gear_count++;
		if (cub3d->gear_count == 0)
			transmission_xpm(cub3d, 0);
		if (cub3d->gear_count == 1)
			transmission_xpm(cub3d, 1);
		if (cub3d->gear_count == 2)
			transmission_xpm(cub3d, 2);
		if (cub3d->gear_count >= 3 && cub3d->gear_count <= 10)
		{
			cub3d->gear_count = 3;
			transmission_xpm(cub3d, 3);
		}
		cub3d->game->keys.up_speed = 1;
	}
}

void	key_down_handler_down(int key, t_cub3d *cub3d)
{
	if (key == KEY_DOWN)
	{
		cub3d->gear_count--;
		if (cub3d->gear_count == 0)
			transmission_xpm(cub3d, 0);
		if (cub3d->gear_count == 1)
			transmission_xpm(cub3d, 1);
		if (cub3d->gear_count == 2)
			transmission_xpm(cub3d, 2);
		if (cub3d->gear_count <= -1)
		{
			cub3d->gear_count = -1;
			transmission_xpm(cub3d, 0);
		}
	}
}

void	keydown_handler_w(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
	{
		if (cub3d->gear_count == 0)
			transmission_xpm(cub3d, 0);
		if (cub3d->gear_count == 1)
			transmission_xpm(cub3d, 1);
		if (cub3d->gear_count == 2)
			transmission_xpm(cub3d, 2);
		if (cub3d->gear_count == 3)
			transmission_xpm(cub3d, 3);
		cub3d->game->keys.w = 1;
	}
}

void	transmission_xpm(t_cub3d *cub3d, int gear_flag)
{
	if (gear_flag == 0)
		cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx,
				"textures/car_0.xpm", &cub3d->tmp_x, &cub3d->tmp_y);
	if (gear_flag == 1)
		cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx,
				"textures/car_1.xpm", &cub3d->tmp_x, &cub3d->tmp_y);
	if (gear_flag == 2)
		cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx,
				"textures/car_2.xpm", &cub3d->tmp_x, &cub3d->tmp_y);
	if (gear_flag == 3)
		cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx,
				"textures/car_3.xpm", &cub3d->tmp_x, &cub3d->tmp_y);
}
