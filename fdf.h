/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/07 13:55:56 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "lib/MacroLibX/includes/mlx.h"

typedef struct s_triangle
{
	int	x;
	int	y;
	int	i;
}	t_triangle;

int	hooking(int key, void *mlx);
#endif
