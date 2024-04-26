/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:44:57 by beeren            #+#    #+#             */
/*   Updated: 2024/03/27 02:07:27 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	player_move_speed_up2(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y + player->direction.y * MOVE_SPEED_2;
	new_position.x = player->position.x + player->direction.x * MOVE_SPEED_2;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '0')
		return ;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x += player->direction.x * MOVE_SPEED_2;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y += player->direction.y * MOVE_SPEED_2;
}

void	player_move_speed_up3(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y + player->direction.y * MOVE_SPEED_3;
	new_position.x = player->position.x + player->direction.x * MOVE_SPEED_3;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '0')
		return ;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x += player->direction.x * MOVE_SPEED_3;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y += player->direction.y * MOVE_SPEED_3;
}
