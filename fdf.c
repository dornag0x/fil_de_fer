/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:42:10 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/07 14:01:58 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/*int key_hook(int keycode, void *mlx)
{
    printf("Key pressed: %d\n", keycode);
    return (0);
}*/

int closewin(int key, void *mlx)
{
	if (key == 0)
		mlx_loop_end(mlx);
	return (0);
}

int key_escape(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}

t_triangle trianglepusher()
{
	t_triangle abs;

	abs.x = 200;
	abs.y = 400;
	abs.i = 123;
	return (abs);
}

void squarelol(void *mlx, void *win)
{
	int	i;
	int	j;

	i = 200;
	j = 150;
	while (j < 300)
	{
		mlx_pixel_put(mlx, win, i, j, 0xFF404040);
		j++;
	}
	while (i < 350)
	{
		mlx_pixel_put(mlx, win, i, j, 0xFF404040);
		i++;
	}
	while (i > 200)
	{
		mlx_pixel_put(mlx, win, i, j, 0xFF404040);
		i--;
		j--;
	}
}

int main()
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "FilDeFer");
	squarelol(mlx, win);
	mlx_on_event(mlx, win, MLX_KEYDOWN, hooking, mlx);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, closewin, mlx);
	mlx_loop(mlx);

	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}
