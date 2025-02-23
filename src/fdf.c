/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:42:10 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/23 15:56:19 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int close_window(int key, void *mlx)
{
	if (key == 0)
		mlx_loop_end(mlx);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	mlx_t mlx;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fil_de_fer");
	parse(argv[1], mlx.mlx, mlx.win);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEDOWN, mouser, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEUP, get_and_show, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, hooking, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, close_window, mlx.mlx);
	mlx_loop(mlx.mlx);

	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
