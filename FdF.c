/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:42:10 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/06 16:55:14 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib/MacroLibX/includes/mlx.h"
#include "FdF.h"

int key_escape(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}

t_square squarepusher()
{
	t_square abs;

	abs.x = 200;
	abs.j = 150;
	abs.i = 450;
	abs.y = 600;
	return (abs);
}

void squarelol(void *mlx, void *win, t_square abs)
{
	int	i;
	int	j;

	i = abs.x;
	j = abs.j;
	while (i < abs.y)
	{
		mlx_pixel_put(mlx, win, i, abs.j, 0xFF404040);
		i++;
	}
	while (j < abs.i)
	{
		mlx_pixel_put(mlx, win, abs.x, j, 0xFF404040);
		j++;
	}
	i = abs.j;
	while (i < abs.i)
	{
		mlx_pixel_put(mlx, win, abs.y, i, 0xFF404040);
		i++;
	}
	j = abs.x;
	while (j < abs.y)
	{
		mlx_pixel_put(mlx, win, j, abs.i, 0xFF404040);
		j++;
	}
}

int main()
{
	void		*mlx;
	void		*win;
	t_square	abs;

	mlx = mlx_init();
	abs = squarepusher();
	win = mlx_new_window(mlx, 800, 600, "FilDeFer");
	squarelol(mlx, win, abs);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_escape, mlx);
	mlx_loop(mlx);

	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}
