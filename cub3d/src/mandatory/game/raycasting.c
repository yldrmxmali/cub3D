/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:39 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:46:01 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "math.h"

void	ray_wall_properties(t_ray *ray, t_player *player)
{
	t_screen	*screen;

	screen = &ray->screen;
	if (ray->hit_wall_side == 'x')
		ray->view_of_wall = ray->side_dist.x - ray->next_hit_dist.x;
	else
		ray->view_of_wall = ray->side_dist.y - ray->next_hit_dist.y;
	screen->wall_height = (long)(SCREEN_HEIGHT / ray->view_of_wall);
	screen->wall_start_point = SCREEN_HEIGHT / 2 - screen->wall_height / 2;
	screen->wall_end_point = SCREEN_HEIGHT / 2 + screen->wall_height / 2;
	if (ray->hit_wall_side == 'x')
		ray->hit_point_wall = player->position.y + ray->view_of_wall
			* ray->direction.y;
	else
		ray->hit_point_wall = player->position.x + ray->view_of_wall
			* ray->direction.x;
	ray->hit_point_wall -= floor(ray->hit_point_wall);
	screen->hit_point_wall_texture = (int)(ray->hit_point_wall * (double)64);
	if ((ray->hit_wall_side == 'x' && ray->direction.x > 0)
		|| (ray->hit_wall_side == 'y' && ray->direction.y < 0))
		screen->hit_point_wall_texture = 64 - screen->hit_point_wall_texture
			- 1;
}

void	ray_draw_until_hit_wall(t_ray *ray, t_map *map)
{
	while (ray->hit_wall == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->next_hit_dist.x;
			ray->map_position.x += ray->map_step.x;
			ray->hit_wall_side = 'x';
		}
		else
		{
			ray->side_dist.y += ray->next_hit_dist.y;
			ray->map_position.y += ray->map_step.y;
			ray->hit_wall_side = 'y';
		}
		if (map->text[ray->map_position.y] == NULL)
			break ;
		if (map->text[ray->map_position.y][ray->map_position.x] == '1')
			ray->hit_wall = 1;
	}
}

static void	side_dist_and_step(t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->map_step.x = -1;
		ray->side_dist.x = (ray->real_position.x - ray->map_position.x)
			* ray->next_hit_dist.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->side_dist.x = (ray->map_position.x + 1.0 - ray->real_position.x)
			* ray->next_hit_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->map_step.y = -1;
		ray->side_dist.y = (ray->real_position.y - ray->map_position.y)
			* ray->next_hit_dist.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->side_dist.y = (ray->map_position.y + 1.0 - ray->real_position.y)
			* ray->next_hit_dist.y;
	}
}

void	ray_properties(t_ray *ray, t_player *player, int x)
{
	double	normalized_camera_x;

	normalized_camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->direction.x = player->direction.x + player->camera_plane.x
		* normalized_camera_x;
	ray->direction.y = player->direction.y + player->camera_plane.y
		* normalized_camera_x;
	ray->next_hit_dist.x = fabs(1 / ray->direction.x);
	ray->next_hit_dist.y = fabs(1 / ray->direction.y);
	ray->map_position.x = (int)player->position.x;
	ray->map_position.y = (int)player->position.y;
	ray->hit_wall = 0;
	side_dist_and_step(ray);
}

void	raycasting(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	ray.real_position.x = cub3d->game->player->position.x;
	ray.real_position.y = cub3d->game->player->position.y;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_properties(&ray, cub3d->game->player, x);
		ray_draw_until_hit_wall(&ray, cub3d->config->map);
		ray_wall_properties(&ray, cub3d->game->player);
		ray_texture_properties(&ray);
		ray_fill_screen(&ray, cub3d->game, x);
		x++;
	}
}
