/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:44:35 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/25 15:07:47 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	skip_color(const char *str, size_t *i)
{
	if (str[*i] == ',')
	{
		(*i)++;
		while (str[*i] && str[*i] != ' ' && str[*i] != '\n')
			(*i)++;
	}
}

static int	extract_number(char *content, size_t *i, size_t size)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (content[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (*i < size && content[*i] >= '0' && content[*i] <= '9')
		num = num * 10 + (content[(*i)++] - '0');
	return (num * sign);
}

static int	fast_fill_data(char *content, size_t size, t_points *points)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < size && j < points->size)
	{
		while (i < size && content[i] == ' ')
			i++;
		if (i < size && (content[i] == '-'
				|| (content[i] >= '0' && content[i] <= '9')))
		{
			points->data[j++] = extract_number(content, &i, size);
			skip_color(content, &i);
		}
		if (i < size)
			i++;
	}
	return (0);
}

static int	init_points(char *content, size_t file_size, t_points *points)
{
	ft_memset(points, 0, sizeof(t_points));
	get_dimensions(content, file_size, points);
	points->data = malloc(sizeof(int) * points->size);
	if (!points->data)
		return (-1);
	if (fast_fill_data(content, file_size, points) < 0)
	{
		free(points->data);
		return (-1);
	}
	return (0);
}

int	parse(char *file_name, void *mlx, void *win)
{
	int			fd;
	char		*content;
	size_t		file_size;
	t_points	points;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	content = read_file_fast(fd, &file_size);
	close(fd);
	if (!content || init_points(content, file_size, &points) < 0)
	{
		free(content);
		return (-1);
	}
	free(content);
	pusher(points, mlx, win);
	return (0);
}
