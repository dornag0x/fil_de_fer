/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/25 16:00:30 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# include "../mlx/includes/mlx.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

# define PIXEL 3
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MOVE_STEP 10

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_abs
{
	double	x;
	double	y;
	double	z;
}	t_abs;

typedef struct u_vec
{
	int	x;
	int	y;
	int	tx;
	int	ty;
}	t_vec;

typedef struct s_points
{
	int	*data;
	int	cols;
	int	rows;
	int	size;
}	t_points;

int			valid_step(int d);
void		imposter(void *mlx, void *win, t_vec *vec, t_points point);
void		draw_line(void *mlx, void *win, t_vec vec1, t_vec vec2);
void		draw_line_h(void *mlx, void *win, t_vec vec1, t_vec vec2);
void		draw_line_v(void *mlx, void *win, t_vec vec1, t_vec vec2);
t_abs		get_coord(int x, int y, int z);
char		*ft_substrc(char const *s, unsigned int start, size_t len);
int			*data_push(char *file, int elem);
char		*read_file_fast(int fd, size_t *total_size);
t_points	point_parser(char *file);
t_vec		squarelol(t_abs coord, int off_x, int off_y);
int			parse(char *file_name, void *mlx, void *win);
void		pusher(t_points point, void *mlx, void *win);
int			hooking(int key, void *mlx);
void		get_dimensions(char *str, size_t size, t_points *points);
#endif
