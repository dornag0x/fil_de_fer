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
	int		i;
	float	L;

	i = 0;
	L = 50;
	struct s_abs base[8] = {
	    {L/2, L/2, L/2},
		{L/2, L/2, -L/2},
        {L/2, -L/2, L/2},
        {-L/2, L/2, L/2},
        {L/2, -L/2, -L/2},
        {-L/2, L/2, -L/2},
        {-L/2, -L/2, L/2},
        {-L/2, -L/2, -L/2}
	};
	while (i < 8)
	{
		squarelol(mlx, win, base[i]);
		i++;
	}
}

void	squarelol(void *mlx, void *win, struct s_abs src)
{
	t_abs	dst;

	mlx_on_event(mlx, win, MLX_KEYDOWN, hooking, mlx);
	dst.x = (src.x - src.z) / sqrt(2);
	dst.y = (src.x + (2 * src.y) + src.z) / sqrt(6);
	mlx_pixel_put(mlx, win, (int)(dst.x + (WINDOW_WIDTH / 2)), (int)(dst.y + (WINDOW_HEIGHT / 2)), 0xFFFFFFFF);
}

/*int	matrix()
{
	matrix[0] = matrix[0] + matrix[0][1] + matrix
	matrix[1] = 
	matrix[2] = 
}*/
