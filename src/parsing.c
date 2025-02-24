/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:44:35 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/24 19:46:00 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	get_dimensions(char *str, size_t size, t_points *points)
{
	size_t	i;
	int		current_row;
	int		count;
	int		elem;

	i = 0;
	count = 0;
	elem = 0;
	current_row = 0;
	while (i < size)
	{
		while (i < size && str[i] == ' ')
			i++;
		if (i < size && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		{
			elem++;
			current_row++;
			while (i < size && str[i] != ' ' && str[i] != '\n' && str[i] != ',')
				i++;
			if (i < size && str[i] == ',')
				while (i < size && str[i] != ' ' && str[i] != '\n')
					i++;
		}
		if (i < size && str[i] == '\n')
		{
			count++;
			if (points->rows == 0)
				points->rows = current_row;
			current_row = 0;
		}
		if (i < size)
			i++;
	}
	if (current_row > 0)
		count++;
	points->cols = count;
	points->size = elem;
}

static char	*read_file_fast(int fd, size_t *total_size)
{
	char	*buffer;
	char	*new_buffer;
	size_t	capacity;
	size_t	size;
	ssize_t	bytes;

	capacity = BUFFER_SIZE;
	size = 0;
	buffer = malloc(capacity);
	if (!buffer)
		return (NULL);
	while ((bytes = read(fd, buffer + size, BUFFER_SIZE)) > 0)
	{
		size += bytes;
		if (size + BUFFER_SIZE > capacity)
		{
			capacity *= 2;
			new_buffer = realloc(buffer, capacity);
			if (!new_buffer)
			{
				free(buffer);
				return (NULL);
			}
			buffer = new_buffer;
		}
	}
	if (bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	*total_size = size;
	return (buffer);
}

static void	skip_color(const char *str, size_t *i)
{
	if (str[*i] == ',')
	{
		(*i)++;
		while (str[*i] && str[*i] != ' ' && str[*i] != '\n')
			(*i)++;
	}
}

static int	fast_fill_data(char *content, size_t size, t_points *points)
{
	size_t	i;
	int		j;
	int		num;
	int		sign;

	i = 0;
	j = 0;
	while (i < size && j < points->size)
	{
		while (i < size && content[i] == ' ')
			i++;
		if (i < size && (content[i] == '-' || (content[i] >= '0'
					&& content[i] <= '9')))
		{
			num = 0;
			sign = (content[i] == '-') ? -1 : 1;
			if (content[i] == '-')
				i++;
			while (i < size && content[i] >= '0' && content[i] <= '9')
				num = num * 10 + (content[i++] - '0');
			points->data[j++] = num * sign;
			skip_color(content, &i);
		}
		if (i < size)
			i++;
	}
	return (0);
}

void	check_data()
{}

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
	if (!content)
		return (-1);
	ft_memset(&points, 0, sizeof(t_points));
	get_dimensions(content, file_size, &points);
	points.data = malloc(sizeof(int) * points.size);
	if (!points.data)
	{
		free(content);
		return (-1);
	}
	if (fast_fill_data(content, file_size, &points) < 0)
	{
		free(content);
		free(points.data);
		return (-1);
	}
	free(content);
	pusher(points, mlx, win);
	return (0);
}
