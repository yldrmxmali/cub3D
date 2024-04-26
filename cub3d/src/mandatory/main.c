/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:17:48 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:55:45 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../utilities/utilities.h"
#include "cub3d.h"

char	**create_map_same_row_len(t_cub3d *cub3d)
{
	t_config	*config;
	char		**map;
	int			i;

	config = cub3d->config;
	map = malloc(sizeof(char *) * (config->map->row_count + 1));
	if (map == NULL)
		(ft_putstr_fd(MAP_ROW_MALLOC, 2), free_all(cub3d));
	i = 0;
	while (config->map->text[i] != NULL)
	{
		map[i] = malloc(config->map->col_count + 1);
		if (map[i] == NULL)
		{
			ft_no_malloc(map);
			(ft_putstr_fd(MAP_ROW_MALLOC_I, 2), free_all(cub3d));
		}
		ft_strncpy(map[i], config->map->text[i], config->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	free_all(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(ERROR);
}

static void	load_xpm(t_cub3d *cub3d)
{
	int	tmp_x;
	int	tmp_y;

	cub3d->car_0 = mlx_xpm_file_to_image(cub3d->game->mlx, "textures/car_0.xpm",
			&tmp_x, &tmp_y);
	cub3d->car_1 = mlx_xpm_file_to_image(cub3d->game->mlx, "textures/car_1.xpm",
			&tmp_x, &tmp_y);
	cub3d->car_2 = mlx_xpm_file_to_image(cub3d->game->mlx, "textures/car_2.xpm",
			&tmp_x, &tmp_y);
	cub3d->car_3 = mlx_xpm_file_to_image(cub3d->game->mlx, "textures/car_3.xpm",
			&tmp_x, &tmp_y);
	if (!cub3d->car_0 || !cub3d->car_1 || !cub3d->car_2 || !cub3d->car_3)
		free_all(cub3d);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;
	int		i;

	i = 0;
	cub3d = init_cub3d(argc, argv[1]);
	map_control(cub3d);
	verify_config(cub3d);
	set_config_line_count(cub3d, 0);
	set_config_text(cub3d);
	verify_elements(cub3d);
	verify_map(cub3d);
	init_game(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	load_xpm(cub3d);
	mlx_hook(cub3d->game->window, ON_DESTROY, 0, destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYDOWN, 0, keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYUP, 0, keyup_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
