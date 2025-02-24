/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:25 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/24 19:26:33 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_map_coords(t_points point, t_abs **map, t_vec **coord, int *i)
{
	int	x;
	int	y;
	int	off_x;
	int	off_y;

	off_x = WINDOW_WIDTH / 2;
	off_y = WINDOW_HEIGHT / 2;
	*map = malloc(sizeof(t_abs) * point.size);
	*coord = malloc(sizeof(t_vec) * point.size);
	y = 0;
	*i = 0;
	while (y < (point.rows - 1))
	{
		x = 0;
		while (x < point.cols)
		{
			(*map)[*i] = get_coord(x, y, point.data[*i]);
			(*coord)[*i] = squarelol((*map)[*i], off_x, off_y);
			(*i)++;
			x++;
		}
		y++;
	}
}

void	pusher(t_points point, void *mlx, void *win)
{
	t_abs	*map;
	t_vec	*coord;
	int		i;

	init_map_coords(point, &map, &coord, &i);
	imposter(mlx, win, coord, point);
}

t_vec	squarelol(t_abs coord, int off_x, int off_y)
{
	t_vec	dst;
	double	alpha;
	double	zoom;

	alpha = M_PI / 6;
	zoom = 20;
	dst.x = (coord.x * cos(alpha)
			+ coord.y * cos(alpha + 2.0943951)
			+ coord.z * cos(alpha - 2.0943951)) * zoom + off_x;
	dst.y = (coord.x * sin(alpha)
			+ coord.y * sin(alpha + 2.0943951)
			+ coord.z * sin(alpha - 2.0943951)) * zoom + off_y;
	return (dst);
}

t_abs	get_coord(int x, int y, int z)
{
	t_abs	map;

	map.x = x;
	map.y = y;
	map.z = z;
	return (map);
}

void	imposter(void *mlx, void *win, t_vec *vec, t_points point)
{
	int		p1;
	int		p2;
	int		y;
	int		x;

	y = 0;
	while (y < (point.rows - 1))
	{
		x = 0;
		while (x < point.cols)
		{
			p1 = y * point.cols + (x + 1);
			p2 = (y + 1) * point.cols + x;
			if (x != (point.cols - 1))
				draw_line(mlx, win, vec[y * point.cols + x], vec[p1]);
			if (y != (point.rows - 2))
				draw_line(mlx, win, vec[y * point.cols + x], vec[p2]);
			x++;
		}
		y++;
	}
}
