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

void	pusher(void *mlx, void *win)
{
	int	i;

	i = 0;
//	(WINDOW_WIDTH / 2) + PIXEL
	struct s_abs base[4] = {
		{200, 150, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	squarelol(mlx, win, base[0]);
}

void	squarelol(void *mlx, void *win, struct s_abs src)
{
	t_abs	dst;

	dst.x = (src.x - src.z) / sqrt(2);
	dst.y = (src.x + (2 * src.y) + src.z) / sqrt(6);
	mlx_pixel_put(mlx, win, dst.x, dst.y, 0xFFFFFFFF);
}

/*int	matrix()
{
	matrix[0] = matrix[0] + matrix[0][1] + matrix
	matrix[1] = 
	matrix[2] = 
}*/
