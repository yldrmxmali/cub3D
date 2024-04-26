/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:16:09 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 01:50:01 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	validate_red_color(t_cub3d *cub3d)
{
	char	*red_string;
	int		red;
	int		red_len;
	int		i;

	red_string = cub3d->config->ceiling_color->red_string;
	red_len = ft_strlen(red_string);
	if (red_len == 0)
		(ft_putstr_fd(C_ELEM_RED_EMPTY, 2), free_all(cub3d));
	if (red_len > 3)
		(ft_putstr_fd(C_ELEM_RED_LEN, 2), free_all(cub3d));
	i = 0;
	while (i < red_len)
	{
		if (!ft_is_digit(red_string[i]))
			(ft_putstr_fd(C_ELEM_RED_DIGIT, 2), free_all(cub3d));
		i++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		(ft_putstr_fd(C_ELEM_RED_RANGE, 2), free_all(cub3d));
	cub3d->config->ceiling_color->red = red;
}

static void	validate_green_color(t_cub3d *cub3d)
{
	char	*green_string;
	int		green;
	int		green_len;
	int		i;

	green_string = cub3d->config->ceiling_color->green_string;
	green_len = ft_strlen(green_string);
	if (green_len == 0)
		(ft_putstr_fd(C_ELEM_GREEN_EMPTY, 2), free_all(cub3d));
	if (green_len > 3)
		(ft_putstr_fd(C_ELEM_GREEN_LEN, 2), free_all(cub3d));
	i = 0;
	while (i < green_len)
	{
		if (!ft_is_digit(green_string[i]))
			(ft_putstr_fd(C_ELEM_GREEN_DIGIT, 2), free_all(cub3d));
		i++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		(ft_putstr_fd(C_ELEM_GREEN_RANGE, 2), free_all(cub3d));
	cub3d->config->ceiling_color->green = green;
}

static void	validate_blue_color(t_cub3d *cub3d)
{
	char	*blue_string;
	int		blue;
	int		blue_len;
	int		i;

	blue_string = cub3d->config->ceiling_color->blue_string;
	blue_len = ft_strlen(blue_string);
	if (blue_len == 0)
		(ft_putstr_fd(C_ELEM_BLUE_EMPTY, 2), free_all(cub3d));
	if (blue_len > 3)
		(ft_putstr_fd(C_ELEM_BLUE_LEN, 2), free_all(cub3d));
	i = 0;
	while (i < blue_len)
	{
		if (!ft_is_digit(blue_string[i]))
			(ft_putstr_fd(C_ELEM_BLUE_DIGIT, 2), free_all(cub3d));
		i++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		(ft_putstr_fd(C_ELEM_BLUE_RANGE, 2), free_all(cub3d));
	cub3d->config->ceiling_color->blue = blue;
}

void	validate_ceiling_color(t_cub3d *cub3d, char *line)
{
	char	**rgb;

	rgb = NULL;
	if (line[0] == 'C')
	{
		cub3d->config->ceiling_color->string = \
			ft_strtrim_start(line + 1, " \t");
		if (*cub3d->config->ceiling_color->string == '\0')
			(ft_putstr_fd(C_ELEMENT_EMPTY, 2), free_all(cub3d));
		validate_comma(cub3d);
		rgb = ft_split(cub3d->config->ceiling_color->string, ',');
		cub3d->config->ceiling_color->red_string = ft_strdup(rgb[0]);
		cub3d->config->ceiling_color->green_string = ft_strdup(rgb[1]);
		cub3d->config->ceiling_color->blue_string = ft_strdup(rgb[2]);
		ft_no_malloc(rgb);
		validate_red_color(cub3d);
		validate_green_color(cub3d);
		validate_blue_color(cub3d);
	}
}
