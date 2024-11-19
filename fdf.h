/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:00 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/16 20:55:41 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
#define FDF_H

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "lib/MacroLibX/includes/mlx.h"
#include "lib/libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 6500
#endif

#define PIXEL 3
#define WINDOW_WIDTH 1920  // 640
#define WINDOW_HEIGHT 1080 // 480
#define MOVE_STEP 10

typedef struct s_buffer {
  struct s_buffer *next;
  size_t size;
  char buff[BUFFER_SIZE + 1];
} t_buffer;

typedef struct
{
    void* mlx;
    void* win;
} mlx_t;

typedef union u_color {
  struct {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
  };
  uint32_t argb;
} t_color;

typedef struct s_abs {
  double x;
  double y;
  double z;
  t_color color;
} t_abs;

typedef union u_vec {
  struct {
    int x;
    int y;
  };
  struct {
    float fx;
    float fy;
  };
} t_vec;

typedef struct s_points {
  int *data;
  int cols;
  int rows;
  int size;
} t_points;

int			get_and_show(int key, void *mlx);
int			mouser(int key, void *mlx);
int			push_color(char *str);
void		imposter(void *mlx, void *win, t_vec *vec, t_points point);
void		draw_line(void *mlx, void *win, t_vec vec1, t_vec vec2);
void		draw_lineH(void *mlx, void *win, t_vec vec1, t_vec vec2);
void		draw_lineV(void *mlx, void *win, t_vec vec1, t_vec vec2);
t_abs		get_coord(t_points point, int x, int y, int z);
char		*ft_substrc(char const *s, unsigned int start, size_t len);
int			*data_push(char *file, int elem);
t_buffer	*read_file(int fd);
t_points	point_parser(char *file);
char		*buff_to_str(t_buffer *src);
void		ft_lstclearc(t_buffer **lst, void (*del)(void *));
t_buffer	*ft_lstnewc(char *content, size_t size);
int			ft_lstsizec(t_buffer *lst);
t_buffer	*ft_lstlastc(t_buffer *lst);
void		ft_lstadd_backc(t_buffer **lst, t_buffer *new);
t_vec		squarelol(t_abs coord, int off_x, int off_y);
int			parse(char *file_name, void *mlx, void *win);
void		pusher(t_points point, void *mlx, void *win);
int			hooking(int key, void *mlx);
#endif
