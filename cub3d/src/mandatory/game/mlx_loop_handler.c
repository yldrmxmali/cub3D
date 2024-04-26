/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:24 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:47:39 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx/mlx.h"
#include "../cub3d.h"
#include "math.h"

void	player_turn_left(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(-TURN_SPEED)
		- player->direction.y * sin(-TURN_SPEED);
	player->direction.y = old_player_direction_x * sin(-TURN_SPEED)
		+ player->direction.y * cos(-TURN_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(-TURN_SPEED)
		- player->camera_plane.y * sin(-TURN_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(-TURN_SPEED)
		+ player->camera_plane.y * cos(-TURN_SPEED);
}

void	player_turn_right(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(TURN_SPEED)
		- player->direction.y * sin(TURN_SPEED);
	player->direction.y = old_player_direction_x * sin(TURN_SPEED)
		+ player->direction.y * cos(TURN_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(TURN_SPEED)
		- player->camera_plane.y * sin(TURN_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(TURN_SPEED)
		+ player->camera_plane.y * cos(TURN_SPEED);
}

static int	is_keys_pressed(t_keys keys)
{
	if (keys.w == 1 || keys.s == 1 || keys.a == 1 || keys.d == 1
		|| keys.left == 1 || keys.right == 1 || keys.up_speed == 1
		|| keys.down_speed == 1)
	{
		return (1);
	}
	return (0);
}

static void	player_move(t_cub3d *cub3d)
{
	if (cub3d->game->keys.w == 1 && cub3d->gear_count == 1)
		player_move_up(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.s == 1)
		player_move_down(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.a == 1)
		player_move_left(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.d == 1)
		player_move_right(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.left == 1)
		player_turn_left(cub3d->game->player);
	if (cub3d->game->keys.right == 1)
		player_turn_right(cub3d->game->player);
	if (cub3d->game->keys.w == 1 && cub3d->gear_count == 2)
		player_move_speed_up2(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.w == 1 && cub3d->gear_count == 3)
		player_move_speed_up3(cub3d->config->map, cub3d->game->player);
}

int	loop_handler(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	mlx_put_image_to_window(game->mlx, game->window, cub3d->car_0, CAR_X,
		CAR_Y);
	cub3d->config->map->text[(int)game->player->position.y]
	[(int)game->player->position.x] = '0';
	if (is_keys_pressed(game->keys))
	{
		player_move(cub3d);
		raycasting(cub3d);
		mlx_put_image_to_window(game->mlx, game->window, game->screen->img, 0,
			0);
		mlx_put_image_to_window(game->mlx, game->window, cub3d->car_0, CAR_X,
			CAR_Y);
	}
	return (0);
}
