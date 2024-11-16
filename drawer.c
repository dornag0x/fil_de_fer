/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:33:29 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/16 20:55:40 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	draw_line(t_vec vec1, t_vec vec2)
{
	if (abs(vec1.x - vec2.x) > abs(vec1.y - vec2.y))
		draw_lineH(vec1, vec2);
	else
		draw_lineV(vec1, vec2);
}

void	draw_lineH(t_vec vec1, t_vec vec2)
{
	int	i;
	int	tx;
	int	ty;
	int	dir;
	int	p;

	i = 0;
	dir = 1;
	if (vec1.x > vec2.x)
	{
		tx = vec1.x;
		ty = vec1.y;
		vec1.x = vec2.x;
		vec1.y = vec2.y;
		vec2.x = tx;
		vec2.y = ty;
	}
	tx = vec2.x - vec1.x;
	ty = vec2.y - vec1.y;
	if (ty < 0)
		dir = -1;
	ty *= dir;
	if (tx != 0)
	{
		p = 2 * ty - tx;
	}
}

void	draw_lineV(t_vec vec1, t_vec vec2)
{}
