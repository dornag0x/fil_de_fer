/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:44:35 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/13 13:30:23 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/*int	parse(char *file_name)
{
	int			fd;
	int			i;
	t_buffer	*head;
	t_points	data;
	char		*src;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	head = read_file(fd);
	close(fd);
	src = buff_to_str(head);
	data = point_parser(src);
	printf("%d\n", ft_strlen(src));
	printf("%s\n", src);
	return (0);
}

t_buffer	*read_file(int fd)
{
	t_buffer	*head;
	t_buffer	*new_node;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	head = NULL;
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		new_node = ft_lstnewc(buffer, bytes);
		if (!new_node)
			return (NULL);
		ft_lstadd_backc(&head, new_node);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes == -1)
		return (NULL);
	return (head);
}

size_t	get_total_size(t_buffer *head)
{
	size_t size;

	size = 0;
	while (head)
	{
		size += head->size;
		head = head->next;
	}
	return (size);
}

char	*buff_to_str(t_buffer *src)
{
	char		*tmp;
	size_t		bigsize;
	t_buffer	*prev;

	bigsize = get_total_size(src);
	tmp = (char *)malloc(sizeof(char) * bigsize);
	while (src->next)
	{
		ft_strlcpy(tmp, src->buff, BUFFER_SIZE);
		tmp += BUFFER_SIZE;
		prev = src;
		src = src->next;
		free(prev);
	}
	ft_strlcpy(tmp, src->buff, BUFFER_SIZE);
	free(src);
	tmp[bigsize] = '\0';
	return (tmp);
}

t_points point_parser(char *file)
{
	t_points	points;
	int			i;
	int			j;
	int			count;
	int			elem;

	i = 0;
	j = 0;
	count = 0;
	elem = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			count++;
		if (file[i] >= 0 && file[i] <= 9)
			elem++;
		i++;
	}
	points.rows = count;
	points.cols = i / count;
	points.data = (int *)malloc(sizeof(int) * elem);
	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] >= '0' && file[i] <= '9')
			points.data[j++] = file[i] - '0';
		i++;
	}
	i = 0;
	return (points);
}*/
