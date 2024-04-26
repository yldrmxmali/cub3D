/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:07 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:43:51 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	set_player_direction(t_player *player, char player_direction)
{
	if (player_direction == 'N')
	{
		player->direction.y = -1;
		player->camera_plane.x = 0.66;
	}
	else if (player_direction == 'S')
	{
		player->direction.y = 1;
		player->camera_plane.x = -0.66;
	}
	else if (player_direction == 'W')
	{
		player->direction.x = -1;
		player->camera_plane.y = -0.66;
	}
	else if (player_direction == 'E')
	{
		player->direction.x = 1;
		player->camera_plane.y = 0.66;
	}
}

static void	set_player_properties(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (character_is_player(map->text[row][col]))
			{
				cub3d->game->player->position.x = (double)col + 0.5;
				cub3d->game->player->position.y = (double)row + 0.5;
				set_player_direction(cub3d->game->player, map->text[row][col]);
			}
			col++;
		}
		row++;
	}
}

void	init_player(t_cub3d *cub3d)
{
	cub3d->game->player = malloc(sizeof(t_player));
	if (cub3d->game->player == NULL)
		(ft_putstr_fd(PLAYER_MALLOC, 2), free_all(cub3d));
	cub3d->game->player->position.x = 0;
	cub3d->game->player->position.y = 0;
	cub3d->game->player->direction.x = 0;
	cub3d->game->player->direction.y = 0;
	cub3d->game->player->camera_plane.x = 0;
	cub3d->game->player->camera_plane.y = 0;
	set_player_properties(cub3d);
}

void	free_player(t_cub3d *cub3d)
{
	if (cub3d->game == NULL)
		return ;
	if (cub3d->game->player != NULL)
		free(cub3d->game->player);
}
