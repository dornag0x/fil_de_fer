/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:33:29 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/23 19:54:45 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int is_in_window(int x, int y)
{
	if (x > 0 && x <= (WINDOW_WIDTH - 1)
		&& y > 0 && y <= (WINDOW_HEIGHT - 1))
		return (1);
	return (0);
}

void	draw_line(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	if (abs(vec1.x - vec2.x) > abs(vec1.y - vec2.y))
		draw_lineH(mlx, win, vec1, vec2);
	else
		draw_lineV(mlx, win, vec1, vec2);
}

void	draw_lineH(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	int	i;
	int	tx;
	int	ty;
	int	dir;
	int	p;

	i = 0;
	dir = 1;
	if (vec1.x > vec2.x)
	{
		tx = vec1.x;
		ty = vec1.y;
		vec1.x = vec2.x;
		vec1.y = vec2.y;
		vec2.x = tx;
		vec2.y = ty;
	}
	tx = vec2.x - vec1.x;
	ty = vec2.y - vec1.y;
	if (ty < 0)
		dir = -1;
	ty *= dir;
	if (tx != 0)
	{
		p = 2 * ty - tx;
		while (i < tx)
		{
			if (is_in_window((vec1.x + i), vec1.y))
				mlx_pixel_put(mlx, win, (int)(vec1.x + i), (int)(vec1.y), 0xFFFFFFFF); // blanc
			if (p >= 0)
			{
				vec1.y += dir;
				p -= 2 * tx;
			}
			p += 2 * ty;
			i++;
		}
	}
}

void	draw_lineV(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	int	i;
	int	tx;
	int	ty;
	int	dir;
	int	p;

	i = 0;
	dir = 1;
	if (vec1.y > vec2.y)
	{
		tx = vec1.x;
		ty = vec1.y;
		vec1.x = vec2.x;
		vec1.y = vec2.y;
		vec2.x = tx;
		vec2.y = ty;
	}
	tx = vec2.x - vec1.x;
	ty = vec2.y - vec1.y;
	if (tx < 0)
		dir = -1;
	tx *= dir;
	if (ty != 0)
	{
		p = 2 * tx - ty;
		while (i < ty)
		{
			if (is_in_window(vec1.x, (vec1.y + i)))
				mlx_pixel_put(mlx, win, (int)(vec1.x), (int)(vec1.y + i), 0xFFFFFFFF); // blanc
			if (p >= 0)
			{
				vec1.x += dir;
				p -= 2 * ty;
			}
			p += 2 * tx;
			i++;
		}
	}
}
