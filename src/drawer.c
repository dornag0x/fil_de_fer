/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:33:29 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/24 19:36:20 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	is_in_window(int x, int y)
{
	return (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT);
}

static void	swap_points(t_vec *vec1, t_vec *vec2)
{
	t_vec	temp;

	temp = *vec1;
	*vec1 = *vec2;
	*vec2 = temp;
}

void	draw_line(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	int	dx;
	int	dy;

	dx = vec2.x - vec1.x;
	dy = vec2.y - vec1.y;
	if (abs(dx) >= abs(dy))
		draw_line_h(mlx, win, vec1, vec2);
	else
		draw_line_v(mlx, win, vec1, vec2);
}

void	draw_line_h(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	int	dx;
	int	dy;
	int	p;
	int	y_step;

	if (vec1.x > vec2.x)
		swap_points(&vec1, &vec2);
	dx = vec2.x - vec1.x;
	dy = vec2.y - vec1.y;
	y_step = valid_step(dy);
	dy = abs(dy);
	p = 2 * dy - dx;
	while (vec1.x <= vec2.x)
	{
		if (is_in_window(vec1.x, vec1.y))
			mlx_pixel_put(mlx, win, vec1.x, vec1.y, 0xFFFFFFFF);
		if (p >= 0)
		{
			vec1.y += y_step;
			p -= 2 * dx;
		}
		p += 2 * dy;
		vec1.x++;
	}
}

void	draw_line_v(void *mlx, void *win, t_vec vec1, t_vec vec2)
{
	int	dx;
	int	dy;
	int	p;
	int	x_step;

	if (vec1.y > vec2.y)
		swap_points(&vec1, &vec2);
	dx = vec2.x - vec1.x;
	dy = vec2.y - vec1.y;
	x_step = valid_step(dx);
	dx = abs(dx);
	p = 2 * dx - dy;
	while (vec1.y <= vec2.y)
	{
		if (is_in_window(vec1.x, vec1.y))
			mlx_pixel_put(mlx, win, vec1.x, vec1.y, 0xFFFFFFFF);
		if (p >= 0)
		{
			vec1.x += x_step;
			p -= 2 * dy;
		}
		p += 2 * dx;
		vec1.y++;
	}
}
