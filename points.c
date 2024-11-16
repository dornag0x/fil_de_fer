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
	t_abs	**map;
	int		x;
	int		y;
	int		i;
	int		j;

	while (y < point.rows)
	{
		j = 0;
		while (x < point.cols)
		{
			map[i][j].x = x;
			map[i][j].y = y;
			map[i][j].z = 0;
			j++;
		}
		i++;
	}
}

void	squarelol(void *mlx, void *win)
{
	t_vec	dst;
	double alpha = M_PI / 6;
	int zoom = 20;
	int offset_x = WINDOW_WIDTH / 2;
	int offset_y = WINDOW_HEIGHT / 2;

	dst.x = (0 * cos(alpha) + 
				0 * cos(alpha + 2.0943951) +
				0 * cos(alpha - 2.0943951)) * zoom + offset_x;

	dst.y = (0 * sin(alpha) + 
				0 * sin(alpha + 2.0943951) + 
				0 * sin(alpha - 2.0943951)) * zoom + offset_y;
	
	mlx_pixel_put(mlx, win, (int)(dst.x), (int)(dst.y), 0xFF008000); // vert
}

/*t_abs get_coord(t_points point, int index, int x, int y)
{
	t_abs	map;

	map.x	= x;
	map.y	= y;
	map.z = 0;
	return (map)
}*/




















/*	dst.x = (0 - 0) / sqrt(2);
	dst.y = (0 + (2 * 0) + 0) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFF008000); // vert

	dst.x = (50 - 50) / sqrt(2);
	dst.y = (50 + (2 * 50) + -50) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFF91D2FF); // bleu
	
	dst.x = (50 - -50) / sqrt(2);
	dst.y = (50 + (2 * -50) + 50) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFFFF0000); // rouge
	
	dst.x = (50 - 50) / sqrt(2);
	dst.y = (50 + (2 * 50) + 50) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFFFFFFFF); // blanc
}

int	matrix()
{
	matrix[0] = matrix[0] + matrix[0][1] + matrix
	matrix[1] = 
	matrix[2] = 
}*/
