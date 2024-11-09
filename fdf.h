/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/09 00:52:38 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# include "lib/MacroLibX/includes/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6500
# endif

# define PIXEL 3
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_list
{
	char c
}	t_list;

typedef struct s_abs
{
	int	x;
	int	y;
	int	z;
}	t_abs;

struct s_abs	*pusher();
void	squarelol(void *mlx, void *win);
int		hooking(int key, void *mlx);
#endif
