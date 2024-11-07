/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:24:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/07 14:10:53 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	mv_up(int key, void *mlx)
{
	printf("oui");
	return (0);
}

int	mv_right(int key, void *mlx)
{
	int	px;

	px = 0;
	if (key == 79)
		px = 2;
	return (px);
}

int	mv_down(int key, void *mlx)
{
	int	px;

	px = 0;
	if (key == 81)
		px = 2;
	return (px);
}

int	mv_left(int key, void *mlx)
{
	int	px;

	px = 0;
	if (key == 80)
		px = 2;
	return (2);
}

int	hooking(int key, void *mlx)
{
	if (key == 82)
		mv_up(key, mlx);
	if (key == 41)
		mlx_loop_end(mlx);
	//if (key == 79)
	//if (key == 81)
	//if (key == 80)
	return (0);
}
