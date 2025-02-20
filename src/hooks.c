/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:24:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/20 18:13:45 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int mouser(int key, void *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	(void)key;
	(void)mlx;
	mlx_mouse_hide();
	mlx_mouse_get_pos(mlx, &x, &y);
	return (0);
}

int get_and_show(int key, void *mlx)
{
	(void)key;
	(void)mlx;
	mlx_mouse_show();
	return (0);
}

int	hooking(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}
