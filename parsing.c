/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:44:35 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/11 23:31:32 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	parse(char *file_name)
{
	int			i;
	int			fd;
	int			bytes;
	char		buffer[BUFFER_SIZE];
	t_buffer	*lst;
	t_buffer	*tmp;

	fd = open(file_name, O_RDWR);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes)
	{
		printf("%d\n", bytes);
		ft_strlcpy(lst->buff , buffer, BUFFER_SIZE);
		lst = lst->next;
		bytes = read(fd, buffer, BUFFER_SIZE);
		printf("%d\n", bytes);
	}
	while (list->next)
	{
		ft_strlcpy(tmp, lst->buff, BUFFER_SIZE);
		lst
	}
	i = ft_lstsizec(lst);
	printf("%d", i);
}
