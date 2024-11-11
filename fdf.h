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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include "lib/MacroLibX/includes/mlx.h"
# include "lib/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6500
# endif

# define PIXEL 3
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480
# define MOVE_STEP 10

typedef struct s_abs
{
	double	x;
	double	y;
	double	z;
}	t_abs;

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}	t_char;

void	squarelol(void *mlx, void *win, struct s_abs src);
int		parse(void *mlx, void *win, char *file_name);
void	pusher(void *mlx, void *win);
int		hooking(int key, void *mlx);
#endif
