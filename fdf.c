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

t_abs pusher()
{
	t_abs oui;

	oui.x = 
	oui.y = 
	oui.z = 
}

void squarelol(void *mlx, void *win)
{
	t_abs	src;
	t_abs	dst;

	dst.x = src.x * cos(a)
		+ src.y * cos(a + 2)
		+ src.z * cos(a - 2);
	dst.y = src.x * sin(a)
		+ src.y * sin(a + 2)
		+ src.z * sin(a - 2);
	mls_pixel_put(mlx, win, )
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
