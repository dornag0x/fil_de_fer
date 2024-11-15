/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/13 14:38:22 by hfeufeu          ###   ########.fr       */
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

typedef struct s_buffer
{
	struct s_buffer	*next;
	size_t			size;
	char			buff[BUFFER_SIZE + 1];
} t_buffer;

typedef struct s_abs
{
	double	x;
	double	y;
	double	z;
}	t_abs;

typedef union u_color
{
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
	uint32_t	argb;
}	t_color;

typedef union u_vec
{
	struct
	{
		int	x;
		int	y;
	};
	struct
	{
		float fx;
		float fy;
	};
}	t_vec;

typedef struct s_points
{
	int	*data;
	int	cols;
	int	rows;
}	t_points;

t_buffer	*read_file(int fd);
t_points	point_parser(char *file);
char		*buff_to_str(t_buffer *src);
void		ft_lstclearc(t_buffer **lst, void (*del)(void*));
t_buffer	*ft_lstnewc(char *content, size_t size);
int			ft_lstsizec(t_buffer *lst);
t_buffer	*ft_lstlastc(t_buffer *lst);
void		ft_lstadd_backc(t_buffer **lst, t_buffer *new);
t_vec		squarelol(void *mlx, void *win);
int			parse(char *file_name);
void		pusher(void *mlx, void *win);
int			hooking(int key, void *mlx);
#endif
