/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:14:33 by wabathur          #+#    #+#             */
/*   Updated: 2022/02/19 16:47:32 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	count_distance(t_window *window)
{
	float	distance;
	float	dx;
	float	dy;

	dx = window->player->dir_x - window->player->x;
	dy = window->player->dir_y - window->player->y;
	distance = sqrtf(dx * dx + dy * dy);
	return (distance);
}

void	calc_pixel(t_window *window, int wall_height, int height, int x)
{
	int	draw_start;
	int	draw_end;

	draw_start = -wall_height / 2 + height / 2 + window->offset;
	draw_end = wall_height / 2 + height / 2 + window->offset;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= height)
		draw_end = height - 1;
	window->current_x = x;
	calc_texture_y(window, wall_height, draw_start, draw_end);
}

void	draw_wall(t_window *window, int x)
{
	float	wall_height;
	int		height;

	height = 720;
	wall_height = height / window->distance;
	if (wall_height < 0)
		wall_height = -wall_height;
	calc_texture(window);
	calc_pixel(window, wall_height, height, x);
}
