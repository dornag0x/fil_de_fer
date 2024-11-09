/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:42:10 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/09 00:56:36 by hfeufeu          ###   ########.fr       */
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

int main(int argc, char **argv)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FilDeFer");
	squarelol(mlx, win);
	mlx_on_event(mlx, win, MLX_KEYDOWN, hooking, mlx);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, closewin, mlx);
	mlx_loop(mlx);

	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}
