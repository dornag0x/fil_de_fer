/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:34:30 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/25 15:45:28 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static char	*extend_buffer(char *buffer, size_t capacity)
{
	char	*new_buffer;

	new_buffer = realloc(buffer, capacity);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (new_buffer);
}

static char	*handle_read_error(char *buffer)
{
	free(buffer);
	return (NULL);
}

static char	*resize_buffer(char *buffer, size_t *capacity)
{
	*capacity *= 2;
	buffer = extend_buffer(buffer, *capacity);
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*read_loop(int fd, char *buffer, size_t *size, size_t *capacity)
{
	ssize_t	bytes;

	bytes = read(fd, buffer + *size, BUFFER_SIZE);
	while (bytes > 0)
	{
		*size += bytes;
		if ((*size + BUFFER_SIZE) > *capacity)
		{
			buffer = resize_buffer(buffer, capacity);
			if (!buffer)
				return (NULL);
		}
		bytes = read(fd, buffer + *size, BUFFER_SIZE);
	}
	if (bytes < 0)
		return (handle_read_error(buffer));
	return (buffer);
}

char	*read_file_fast(int fd, size_t *total_size)
{
	char	*buffer;
	size_t	capacity;
	size_t	size;

	capacity = BUFFER_SIZE;
	size = 0;
	buffer = malloc(capacity);
	if (!buffer)
		return (NULL);
	buffer = read_loop(fd, buffer, &size, &capacity);
	if (!buffer)
		return (NULL);
	*total_size = size;
	return (buffer);
}
