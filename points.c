/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:25 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/08 16:56:11 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_abs	*pusher()
{
	struct s_abs baguette[4] = {
		{200, 150, 0},
		{0, 0, 1},
		{1, 0, 1},
		{1, 1, 0}};
	return (baguette);
	starting_point = ((WINDOW_WIDTH / 2) + )
	/*pos = malloc(sizeof(t_abs) * 4);
	if (!pos)
		return (NULL);
	pos[4] = {
		{200, 150, 0},
		{0, 0, 1},
		{1, 0, 1},
		{1, 1, 0}};*/
}

void	squarelol(void *mlx, void *win)
{
	struct s_abs	*src;
	t_abs	dst;

	src = malloc(sizeof(t_abs) * 4);
	if (!src)
		return ;
	/*dst.x = src.x * cos(a)
		+ src.y * cos(a + 2)
		+ src.z * cos(a - 2);
	dst.y = src.x * sin(a)
		+ src.y * sin(a + 2)
		+ src.z * sin(a - 2);*/
	dst.x = (src->x - src->z) / sqrt(2);
	dst.y = (src->x + (2 * src->y) + src->z) / sqrt(6);
	mlx_pixel_put(mlx, win, dst.x, dst.y, 0xFF404040);
}
