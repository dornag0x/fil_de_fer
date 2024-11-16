/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:13:25 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/13 14:38:22 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	pusher(t_points point, void *mlx, void *win)
{
	t_abs	*map;
	int		x;
	int		y;
	int		i;

	map = malloc(sizeof(t_abs) * point.size);
	y = 0;
	i = 0;
	while (y < point.rows)
	{
		x = 0;
		while (x < point.cols)
		{
			map[i] = get_coord(point, x, y);
			i++;
			x++;
		}
		y++;
	}
	i = 0;
	while (i < point.size)
	{
		squarelol(map[i], mlx, win);
		i++;
	}
}

void	squarelol(t_abs coord, void *mlx, void *win)
{
	t_vec	dst;
	double alpha = M_PI / 6;
	int zoom = 20;
	int offset_x = WINDOW_WIDTH / 2;
	int offset_y = WINDOW_HEIGHT / 2;

	dst.x = (coord.x * cos(alpha) +
				coord.y * cos(alpha + 2.0943951) +
				coord.z * cos(alpha - 2.0943951)) * zoom + offset_x;
	dst.y = (coord.x * sin(alpha) +
				coord.y * sin(alpha + 2.0943951) +
				coord.z * sin(alpha - 2.0943951)) * zoom + offset_y;
	printf("%d, ", dst.x);
	printf("%d\n", dst.y);
	mlx_pixel_put(mlx, win, (int)(dst.x), (int)(dst.y), 0xFFFFFFFF); // vert
}

t_abs get_coord(t_points point, int x, int y)
{
	t_abs	map;

	map.x = x;
	map.y = y;
	map.z = 0;
	return (map);
}


















/*int	matrix()
{
	matrix[0] = matrix[0] + matrix[0][1] + matrix
	matrix[1] = 
	matrix[2] = 
}*/
