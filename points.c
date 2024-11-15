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

/*void	pusher(void *mlx, void *win)
{
	int		i;
	int		*row1 = NULL;
	int		*row2 = NULL;
	t_abs	*abs;

	i = 0;
	while (y < points.row - 1)
	{
		row1 = row2;
		if (!row1)
			row1 = &points.data[y * points.cols];
		row2 = &points.data[(y + 1) * points.cols];
		x = 0;
		while (x < points.cols)
		{
			t_abs[i] = getcoord(points.rows, points.cols, x, y);
		}
	}
}*/

void	squarelol(void *mlx, void *win)
{
	t_vec	dst;

	dst.x = (50 - 50) / sqrt(2);
	dst.y = (50 + (2 * 50) + 50) / sqrt(6);
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

/*int	matrix()
{
	matrix[0] = matrix[0] + matrix[0][1] + matrix
	matrix[1] = 
	matrix[2] = 
}

	
while (points.data[i])
{
	y * points.cols + x;
	x = index % cols;
	y = (index / cols) % rows;
	z = index / (cols * rows);
}*/

//t_abs	getcoord()
/*	dst.x = (src.x - src.y) / sqrt(2);
	dst.y = (src.x + (2 * src.y) + src.z) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFFFFFFFF);
}*/
